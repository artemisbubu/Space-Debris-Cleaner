//void DrawTexturePro(
//	Texture2D texture,     // 要绘制的纹理
//	Rectangle source,      // 源矩形（在纹理上的区域）
//	Rectangle dest,        // 目标矩形（在屏幕上的位置和大小）
//	Vector2 origin,        // 旋转与缩放的原点（相对于目标矩形）
//	float rotation,        // 旋转角度（单位：°）
//	Color tint             // 颜色叠加（WHITE = 原色）
//);

#include "marco.hpp"
#include "texture_manager.hpp"
#include "global_setting.hpp"
#include "launcher.hpp"

int main(void)
{
 //   // 设置窗口为可调整大小
 //   SetConfigFlags(FLAG_WINDOW_RESIZABLE);
 //   // 初始化窗口
 //   InitWindow(
 //       960,
 //       640,    // 设置窗口初始大小
 //       "Space Debris Cleaner"      // 窗口名称
 //   );
 //   // 设置目标FPS
 //   SetTargetFPS(60);
 //   // 主循环
 //   while (!WindowShouldClose())
 //   {
 //       BeginDrawing();
 //       ClearBackground(RAYWHITE);
 //       int width = GetScreenWidth();
 //       int height = GetScreenHeight();
 //       DrawText(TextFormat("Width: %d", width), 20, 60, 20, BLACK);
 //       DrawText(TextFormat("Height: %d", height), 20, 90, 20, BLACK);
 //       EndDrawing();
 //   }
 //   CloseWindow();

    // 构造启动器
    sdc::launcher game("./config.json");

    // 运行
    game.run();

    return 0;
}

