#include "definitions.hpp"
#include "raylib.h"
#include "entity.hpp"
#include <chrono>
#include "segment.hpp"
#include <iostream>
int main(void)
{
//    //// 设置窗口为可调整大小
//    //SetConfigFlags(FLAG_WINDOW_RESIZABLE);
//    //// 初始化窗口
//    //InitWindow(
//    //    sdc::GM_WIN_INIT_WIDTH,
//    //    sdc::GM_WIN_INIT_HEIGHT,    // 设置窗口初始大小
//    //    "Space Debris Cleaner"      // 窗口名称
//    //);
//    //// 设置目标FPS
//    //SetTargetFPS(60);
//    //// 主循环
//    //while (!WindowShouldClose())
//    //{
//    //    BeginDrawing();
//    //    ClearBackground(RAYWHITE);
//    //    int width = GetScreenWidth();
//    //    int height = GetScreenHeight();
//    //    DrawText(TextFormat("Width: %d", width), 20, 60, 20, BLACK);
//    //    DrawText(TextFormat("Height: %d", height), 20, 90, 20, BLACK);
//    //    EndDrawing();
//    //}
//    //CloseWindow();
//    sdc::texture_manager tm;

	nlohmann::json config;
	std::ifstream file{"./config.json"};
	file >> config;

	// 检查配置文件结构
	if (config.contains("resource_path") &&
		config["resource_path"].contains("entity") &&
		config["resource_path"]["entity"].is_array()
		) {
		std::cout << "遍历 entity 数组：" << std::endl;
		for (auto& item : config["resource_path"]["entity"]) {
			std::cout << "元素: " << item << std::endl;
		}
	}
	else {
		std::cout << "JSON 结构不符合预期！" << std::endl;
	}

    return 0;
}

