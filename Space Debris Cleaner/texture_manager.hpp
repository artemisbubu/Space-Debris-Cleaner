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

			// ��������ļ��ṹ
			if (config.contains("resource_path") &&
				config["resource_path"].contains("entity") &&
				config["resource_path"]["entity"].is_array()
			) {
				std::cout << "���� entity ���飺" << std::endl;
				for (auto& item : config["resource_path"]["entity"]) {
					std::cout << "Ԫ��: " << item << std::endl;
				}
			}
			else {
				std::cout << "JSON �ṹ������Ԥ�ڣ�" << std::endl;
			}
		}

		/** 
		* @brief	����ֻ����Դ
		* @input	sdc::entity_type entity_type ʵ������
		* @return	const texture& ��Դ��ֻ������
		* @note		const
		*/
		const Texture2D& request(const sdc::entity_type entity_type) const {

		}

		/**
		* @brief	����ֻ����Դ
		* @input	sdc::scene_type scene_type ��������
		* @return	const texture& ��Դ��ֻ������
		* @note		const
		*/
		const Texture2D& request(const sdc::scene_type scene_type) const;

	private:
		/** @var ʵ������ */
		std::vector<Texture2D> _entity_texture;
		
		/** @var �������� */
		std::vector<Texture2D> _scene_texture;
	};

} 
#endif // !TEXTURE_MANAGER_HPP