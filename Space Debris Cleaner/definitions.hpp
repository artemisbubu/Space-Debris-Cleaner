#ifndef DEFINITIONS_HPP
#define DEFINITIONS_HPP
#include <vector>

namespace sdc {

	const int	GM_WIN_INIT_WIDTH = 1280;		// 初始化游戏窗口宽
	const int	GM_WIN_INIT_HEIGHT = 853;		// 初始化游戏窗口高
	const int	GM_FPS = 60;					// 游戏帧率

	/**
	* @enumclass 枚举实体类型
	*/
	enum class entity_type {
		TRASH_A,
		SIZE
	};

	/**
	* @enumclass 场景类型
	*/
	enum class scene_type {
		SCENE_A,
		SIZE
	};
}


#endif // !DEFINITIONS_HPP
