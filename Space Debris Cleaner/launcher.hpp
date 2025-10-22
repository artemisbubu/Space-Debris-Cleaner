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

            // ��ȡ����
            const Texture2D& tex1 = global_setting.texture_manager.request_texture(sdc::entity_type::stone_1);
            const Texture2D& tex2 = global_setting.texture_manager.request_texture(sdc::entity_type::stone_2);
            const Texture2D& tex3 = global_setting.texture_manager.request_texture(sdc::entity_type::stone_3);

            // ��Ļ����
            sdc::coord center(screenWidth / 2.0f, screenHeight / 2.0f);

            // Բ�ܰ뾶
            float r1 = 50.0f, r2 = 70.0f, r3 = 40.0f;

            // ��ʼ�Ƕȣ�120�ȼ����
            float angle1 = 0.0f, angle2 = 120.0f, angle3 = 240.0f;
            const float angle_speed = 0.2f; // ÿ֡���� 0.2 ��

            // ����ʵ�壬��ʼλ����Բ����
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

                // ������Ļ���ĺ��
                DrawCircle(center.x, center.y, 5, RED);

                // ���½Ƕ�
                angle1 += angle_speed;
                angle2 += angle_speed;
                angle3 += angle_speed;

                // ����Բ�����겢����ʵ��
                e1.update(center + sdc::coord(cos(angle1 * DEG2RAD) * r1, sin(angle1 * DEG2RAD) * r1), angle1);
                e2.update(center + sdc::coord(cos(angle2 * DEG2RAD) * r2, sin(angle2 * DEG2RAD) * r2), angle2);
                e3.update(center + sdc::coord(cos(angle3 * DEG2RAD) * r3, sin(angle3 * DEG2RAD) * r3), angle3);

                // ��Ⱦ
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
            // ���֮ǰ�Ѿ����ڣ����ټ���
            if (_global_setting) {
                SDC_WARN(false, "��Դ�Ѽ��أ���������");
                return;
            }

            // 1. ��ȡ�����ļ�
            nlohmann::json config;
            std::ifstream file(_config_path);
            SDC_ASSERT(file.is_open(), "�޷��������ļ���");
            file >> config;

            // 2. ��ʼ�����������
            sdc::texture_manager texture_manager(config);

            sdc::logger::warn("1");

            // 3. ��̬���� global_setting
            _global_setting = std::make_unique<global_setting>(
                std::move(config),
                std::move(texture_manager)
            );

        }

	};
}
#endif // !LAUNCHER_HPP
