#ifndef MARCO_HPP
#define MARCO_HPP

#define SDC_DEBUG	// WIP版本，debug时在代码中定义

#if defined(SDC_DEBUG)

/// 
///	重要：所有运行时的断言需要再release版本中替换为错误try/catch, ASSERT仅用于开发定位
/// 例如：
/// #ifdef DEBUG
/// #define SDC_ASSERT(cond, msg) \
///     do { if (!(cond)) { std::cerr << msg << std::endl; std::abort(); } } while(0)
/// #else
/// #define SDC_ASSERT(cond, msg) \
///     do { if (!(cond)) throw std::runtime_error(msg); } while(0)
/// #endif

/** 
* @brief	打印错误堆栈 
* @input	void
* @return	void
* @note		none
*/
void print_stacktrace();

/** 
* @brief	定义断言条件宏，用于debug 
* @input	cond	条件：为false则打印堆栈信息退出
*			msg		报错信息
*/
#define SDC_ASSERT(cond, msg)											\
		do {                                                            \
			if (!(cond)) {                                              \
				std::fprintf(stderr,                                    \
					"\033[1;31m[错误]\033[0m\n"						\
					"  Condition : %s\n"                                \
					"  Message   : %s\n"                                \
					"  Function  : %s\n"                                \
					"  File      : %s\n"                                \
					"  Line      : %d\n",                               \
					#cond, msg, __func__, __FILE__, __LINE__);			\
				print_stacktrace();										\
				std::exit(1);                                           \
			}                                                           \
		} while(0)

/**
* @brief	定义警告宏，用于debug
* @input	cond	条件：为false则打印警告信息但不中断程序
*			msg		警告信息
*/
#define SDC_WARN(cond, msg)												\
	do {                                                                \
		if (!(cond)) {                                                  \
			std::fprintf(stderr,                                        \
				"\033[1;33m[警告]\033[0m\n"								\
				"  Condition : %s\n"                                    \
				"  Message   : %s\n"                                    \
				"  Function  : %s\n"                                    \
				"  File      : %s\n"                                    \
				"  Line      : %d\n",                                   \
				#cond, msg, __func__, __FILE__, __LINE__);				\
		}                                                               \
	} while(0)
#else
	#define SDC_ASSERT(cond, msg) ((void)0)
	#define SDC_WARN(cond, msg) ((void)0)
#endif

#endif // !MARCO_HPP
