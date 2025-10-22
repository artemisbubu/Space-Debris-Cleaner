#include "marco.hpp"
#include <windows.h>
#include <stdio.h>
#include <malloc.h>
#include <DbgHelp.h>

typedef BOOL(WINAPI* symInitialize_t)(HANDLE, PCSTR, BOOL);
typedef BOOL(WINAPI* sym_from_addr_t)(HANDLE, DWORD64, DWORD64*, void*);
typedef BOOL(WINAPI* sym_get_line_from_addr64_t)(HANDLE, DWORD64, DWORD*, void*);
typedef BOOL(WINAPI* sym_cleanup_t)(HANDLE);

typedef struct _SYMBOL_INFO_USER {
	SYMBOL_INFO sym;
	char name[256];
} SYMBOL_INFO_USER;


#include <windows.h>
#include <stdio.h>
#include <dbghelp.h>

#pragma comment(lib, "dbghelp.lib")

void print_stacktrace() {
    HMODULE hDbghelp = LoadLibraryA("dbghelp.dll");
    if (!hDbghelp) {
        fprintf(stderr, "[stacktrace] Failed to load dbghelp.dll\n");
        return;
    }

    symInitialize_t SymInitialize = (symInitialize_t)GetProcAddress(hDbghelp, "SymInitialize");
    sym_from_addr_t SymFromAddr = (sym_from_addr_t)GetProcAddress(hDbghelp, "SymFromAddr");
    sym_get_line_from_addr64_t SymGetLineFromAddr64 = (sym_get_line_from_addr64_t)GetProcAddress(hDbghelp, "SymGetLineFromAddr64");
    sym_cleanup_t SymCleanup = (sym_cleanup_t)GetProcAddress(hDbghelp, "SymCleanup");

    if (!SymInitialize || !SymFromAddr || !SymGetLineFromAddr64 || !SymCleanup) {
        fprintf(stderr, "[stacktrace] Missing required symbols in dbghelp.dll\n");
        FreeLibrary(hDbghelp);
        return;
    }

    HANDLE process = GetCurrentProcess();
    if (!SymInitialize(process, NULL, TRUE)) {
        fprintf(stderr, "[stacktrace] SymInitialize() failed (error=%lu)\n", GetLastError());
        FreeLibrary(hDbghelp);
        return;
    }

    void* stack[128];
    USHORT frames = CaptureStackBackTrace(0, 128, stack, NULL);

    const int MAX_NAME_LEN = 256;
    size_t symbolSize = sizeof(SYMBOL_INFO) + MAX_NAME_LEN * sizeof(char);
    SYMBOL_INFO* symbol = (SYMBOL_INFO*)calloc(1, symbolSize);
    if (!symbol) {
        SymCleanup(process);
        FreeLibrary(hDbghelp);
        return;
    }

    symbol->SizeOfStruct = sizeof(SYMBOL_INFO);
    symbol->MaxNameLen = MAX_NAME_LEN - 1;

    fprintf(stderr, "Stack trace (%d frames):\n", frames);
    for (int i = 0; i < frames; ++i) {
        DWORD64 addr = (DWORD64)(stack[i]);
        DWORD displacement = 0;
        IMAGEHLP_LINE64 line = { 0 };
        line.SizeOfStruct = sizeof(IMAGEHLP_LINE64);

        BOOL hasSymbol = SymFromAddr(process, addr, 0, symbol);
        BOOL hasLine = SymGetLineFromAddr64(process, addr, &displacement, &line);

        if (hasSymbol && hasLine) {
            fprintf(stderr, "  #%02d: %s - %s:%lu\n",
                i, symbol->Name, line.FileName, line.LineNumber);
        }
        else if (hasSymbol) {
            fprintf(stderr, "  #%02d: %s - 0x%0llX\n",
                i, symbol->Name, symbol->Address);
        }
        else {
            fprintf(stderr, "  #%02d: [0x%p]\n", i, stack[i]);
        }
    }

    free(symbol);
    SymCleanup(process);
    FreeLibrary(hDbghelp);
}


/** Deprecated version version from Oblivious STL lib by min */
//void print_stacktrace() {
//	HMODULE hDbghelp = LoadLibraryA("dbghelp.dll");
//	if (!hDbghelp) return;
//	symInitialize_t SymInitialize = (symInitialize_t)GetProcAddress(hDbghelp, "SymInitialize");
//	sym_from_addr_t SymFromAddr = (sym_from_addr_t)GetProcAddress(hDbghelp, "SymFromAddr");
//	sym_get_line_from_addr64_t SymGetLineFromAddr64 = (sym_get_line_from_addr64_t)GetProcAddress(hDbghelp, "SymGetLineFromAddr64");
//	sym_cleanup_t SymCleanup = (sym_cleanup_t)GetProcAddress(hDbghelp, "SymCleanup");
//	if (!SymInitialize || !SymFromAddr || !SymGetLineFromAddr64 || !SymCleanup) {
//		FreeLibrary(hDbghelp);
//		return;
//	}
//	HANDLE process = GetCurrentProcess();
//	SymInitialize(process, NULL, TRUE);
//	void* stack[128];
//	USHORT frames = CaptureStackBackTrace(0, 128, stack, NULL);
//	SYMBOL_INFO_USER* symbol = (SYMBOL_INFO_USER*)malloc(sizeof(SYMBOL_INFO_USER));
//	symbol->sym.SizeOfStruct = sizeof(SYMBOL_INFO);
//	symbol->sym.MaxNameLen = 255;
//	IMAGEHLP_LINE64 line;
//	DWORD displacement;
//	fprintf(stderr, "Stack trace (%d frames):\n", frames);
//	for (int i = 0; i < frames; ++i) {
//		BOOL hasSymbol = SymFromAddr(process, (DWORD64)(stack[i]), 0, (SYMBOL_INFO*)&symbol->sym);
//		BOOL hasLine = FALSE;
//		if (hasSymbol) {
//			line.SizeOfStruct = sizeof(IMAGEHLP_LINE64);
//			hasLine = SymGetLineFromAddr64(process, (DWORD64)(stack[i]), &displacement, &line);
//		}
//
//		if (hasSymbol && hasLine) {
//			fprintf(stderr, "  %i: %s - %s:%lu\n", i, symbol->sym.Name, line.FileName, line.LineNumber);
//		}
//		else if (hasSymbol) {
//			fprintf(stderr, "  %i: %s - 0x%0llX\n", i, symbol->sym.Name, symbol->sym.Address);
//		}
//		else {
//			fprintf(stderr, "  %i: 0x%p\n", i, stack[i]);
//		}
//	}
//	free(symbol);
//	SymCleanup(process);
//	FreeLibrary(hDbghelp);
//}