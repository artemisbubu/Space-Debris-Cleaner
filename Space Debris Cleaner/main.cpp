#include "definitions.hpp"
#include "raylib.h"
#include "entity.hpp"
#include <chrono>
#include "segment.hpp"
#include <iostream>


int main(void)
{

	// 资源加载
	nlohmann::json config;
	std::ifstream file{ sdc::CONFIG_PATH };
	file >> config;

    // 设置窗口为可调整大小
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    // 初始化窗口
    InitWindow(
        960,
        640,    // 设置窗口初始大小
        "Space Debris Cleaner"      // 窗口名称
    );
    // 设置目标FPS
    SetTargetFPS(60);
    // 主循环
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        int width = GetScreenWidth();
        int height = GetScreenHeight();
        DrawText(TextFormat("Width: %d", width), 20, 60, 20, BLACK);
        DrawText(TextFormat("Height: %d", height), 20, 90, 20, BLACK);
        EndDrawing();
    }
    CloseWindow();
    return 0;
}

