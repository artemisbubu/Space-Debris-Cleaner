#ifndef MARCO_HPP
#define MARCO_HPP

#define SDC_DEBUG	// WIP�汾��debugʱ�ڴ����ж���

#if defined(SDC_DEBUG)

/// 
///	��Ҫ����������ʱ�Ķ�����Ҫ��release�汾���滻Ϊ����try/catch, ASSERT�����ڿ�����λ
/// ���磺
/// #ifdef DEBUG
/// #define SDC_ASSERT(cond, msg) \
///     do { if (!(cond)) { std::cerr << msg << std::endl; std::abort(); } } while(0)
/// #else
/// #define SDC_ASSERT(cond, msg) \
///     do { if (!(cond)) throw std::runtime_error(msg); } while(0)
/// #endif

/** 
* @brief	��ӡ�����ջ 
* @input	void
* @return	void
* @note		none
*/
void print_stacktrace();

/** 
* @brief	������������꣬����debug 
* @input	cond	������Ϊfalse���ӡ��ջ��Ϣ�˳�
*			msg		������Ϣ
*/
#define SDC_ASSERT(cond, msg)											\
		do {                                                            \
			if (!(cond)) {                                              \
				std::fprintf(stderr,                                    \
					"\033[1;31m[����]\033[0m\n"						\
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
* @brief	���徯��꣬����debug
* @input	cond	������Ϊfalse���ӡ������Ϣ�����жϳ���
*			msg		������Ϣ
*/
#define SDC_WARN(cond, msg)												\
	do {                                                                \
		if (!(cond)) {                                                  \
			std::fprintf(stderr,                                        \
				"\033[1;33m[����]\033[0m\n"								\
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
