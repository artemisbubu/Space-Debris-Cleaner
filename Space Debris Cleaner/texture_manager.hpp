#ifndef TEXTURE_MANAGER_HPP
#define TEXTURE_MANAGER_HPP

#include "definitions.hpp"
#include <iostream>
#include <fstream>
#include <raylib.h>
#include <nlohmann/json.hpp>
#include <string>

namespace sdc {
	class texture_manager {
	public:
		texture_manager(
			const std::string& config_path
		):
			_entity_texture(static_cast<int>(sdc::entity_type::SIZE)),
			_scene_texture(static_cast<int>(sdc::scene_type::SIZE))
		{
			nlohmann::json config;
			std::ifstream file{ config_path };
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
		}

		/** 
		* @brief	请求只读资源
		* @input	sdc::entity_type entity_type 实体名称
		* @return	const texture& 资源的只读引用
		* @note		const
		*/
		const Texture2D& request(const sdc::entity_type entity_type) const {

		}

		/**
		* @brief	请求只读资源
		* @input	sdc::scene_type scene_type 场景名称
		* @return	const texture& 资源的只读引用
		* @note		const
		*/
		const Texture2D& request(const sdc::scene_type scene_type) const;

	private:
		/** @var 实体纹理 */
		std::vector<Texture2D> _entity_texture;
		
		/** @var 场景纹理 */
		std::vector<Texture2D> _scene_texture;
	};

} 
#endif // !TEXTURE_MANAGER_HPP