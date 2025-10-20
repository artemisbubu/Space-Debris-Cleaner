#ifndef DEFINITIONS_HPP
#define DEFINITIONS_HPP
#include <vector>

namespace sdc {
	const char* const CONFIG_PATH = "./config.json";	// 配置文件所在路径

	/**
	* @enumclass 枚举实体类型
	*/
	enum class entity_type {
		stone_1,
		stone_2,
		stone_3,
		size
	};

	/**
	* @enumclass 场景类型
	*/
	enum class scene_type {
		background,
		size
	};
}


#endif // !DEFINITIONS_HPP


//void DrawTexturePro(
//	Texture2D texture,     // 要绘制的纹理
//	Rectangle source,      // 源矩形（在纹理上的区域）
//	Rectangle dest,        // 目标矩形（在屏幕上的位置和大小）
//	Vector2 origin,        // 旋转与缩放的原点（相对于目标矩形）
//	float rotation,        // 旋转角度（单位：°）
//	Color tint             // 颜色叠加（WHITE = 原色）
//);