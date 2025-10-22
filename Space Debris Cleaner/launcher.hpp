#ifndef LAUNCHER_HPP
#define LAUNCHER_HPP
#include <string>
#include "global_setting.hpp"
#include "logger.hpp"
/** @namespace sdc*/
namespace sdc{

	/** @class launcher */
	class launcher {
	public:
		launcher(const std::string& config_path) : 
			_global_setting(nullptr),
			_config_path(config_path)
		{}
		
		launcher(const launcher&) = delete;
		launcher& operator=(const launcher&) = delete;	
        ~launcher() = default;

	public:
        void run() {
            const int screenWidth = 1350;
            const int screenHeight = 1000;
            InitWindow(screenWidth, screenHeight, "SDC Example");
            SetTargetFPS(60);

            load_resource();
            const global_setting& global_setting = *_global_setting;

            // 获取纹理
            const Texture2D& tex1 = global_setting.texture_manager.request_texture(sdc::entity_type::stone_1);
            const Texture2D& tex2 = global_setting.texture_manager.request_texture(sdc::entity_type::stone_2);
            const Texture2D& tex3 = global_setting.texture_manager.request_texture(sdc::entity_type::stone_3);

            // 屏幕中心
            sdc::coord center(screenWidth / 2.0f, screenHeight / 2.0f);

            // 圆周半径
            float r1 = 50.0f, r2 = 70.0f, r3 = 40.0f;

            // 初始角度（120度间隔）
            float angle1 = 0.0f, angle2 = 120.0f, angle3 = 240.0f;
            const float angle_speed = 0.2f; // 每帧增加 0.2 度

            // 创建实体，初始位置在圆周上
            sdc::entity e1(sdc::entity_type::stone_1, 0.0f,
                center + sdc::coord(cos(angle1 * DEG2RAD) * r1, sin(angle1 * DEG2RAD) * r1),
                {}, tex1);

            sdc::entity e2(sdc::entity_type::stone_2, 0.0f,
                center + sdc::coord(cos(angle2 * DEG2RAD) * r2, sin(angle2 * DEG2RAD) * r2),
                {}, tex2);

            sdc::entity e3(sdc::entity_type::stone_3, 0.0f,
                center + sdc::coord(cos(angle3 * DEG2RAD) * r3, sin(angle3 * DEG2RAD) * r3),
                {}, tex3);

            while (!WindowShouldClose()) {
                BeginDrawing();
                ClearBackground(RAYWHITE);

                // 绘制屏幕中心红点
                DrawCircle(center.x, center.y, 5, RED);

                // 更新角度
                angle1 += angle_speed;
                angle2 += angle_speed;
                angle3 += angle_speed;

                // 计算圆周坐标并更新实体
                e1.update(center + sdc::coord(cos(angle1 * DEG2RAD) * r1, sin(angle1 * DEG2RAD) * r1), angle1);
                e2.update(center + sdc::coord(cos(angle2 * DEG2RAD) * r2, sin(angle2 * DEG2RAD) * r2), angle2);
                e3.update(center + sdc::coord(cos(angle3 * DEG2RAD) * r3, sin(angle3 * DEG2RAD) * r3), angle3);

                // 渲染
                e1.render();
                e2.render();
                e3.render();

                EndDrawing();
            }

            CloseWindow();
        }

		
	private:
		const std::string _config_path;
        std::unique_ptr<global_setting> _global_setting;

        void load_resource() {
            // 如果之前已经存在，则不再加载
            if (_global_setting) {
                SDC_WARN(false, "资源已加载，请勿重载");
                return;
            }

            // 1. 读取配置文件
            nlohmann::json config;
            std::ifstream file(_config_path);
            SDC_ASSERT(file.is_open(), "无法打开配置文件。");
            file >> config;

            // 2. 初始化纹理管理器
            sdc::texture_manager texture_manager(config);

            sdc::logger::warn("1");

            // 3. 动态创建 global_setting
            _global_setting = std::make_unique<global_setting>(
                std::move(config),
                std::move(texture_manager)
            );

        }

	};
}
#endif // !LAUNCHER_HPP
