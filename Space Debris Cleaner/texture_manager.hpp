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
			const nlohmann::json& config
		):
			_entity_texture(static_cast<size_t>(sdc::entity_type::size)),
			_scene_texture(static_cast<size_t>(sdc::scene_type::size))
		{
			// ��Դ���Ӧ�ý���launcher���������ڲ���������Դ��飬Ĭ��config�Ѿ��ǺϹ��
			for (size_t i = 0; i < static_cast<size_t>(sdc::entity_type::size); ++i) {
				_entity_texture[i] = LoadTexture(
					config["resource_path"]["entity"][i].get<std::string>().c_str()
				);
			}

			for (size_t i = 0; i < static_cast<size_t>(sdc::scene_type::size); ++i) {
				_scene_texture[i] = LoadTexture(
					config["resource_path"]["scene"][i].get<std::string>().c_str()
				);
			}
		}

		~texture_manager() {
			for (Texture2D& tex : _entity_texture) {
				UnloadTexture(tex);
			}

			for (Texture2D& tex : _scene_texture) {
				UnloadTexture(tex);
			}
		}

		/** 
		* @brief	����ֻ����Դ
		* @input	sdc::entity_type entity_type ʵ������
		* @return	const texture& ��Դ��ֻ������
		* @note		const
		*/
		const Texture2D& request(const sdc::entity_type entity_type) const {
			return _entity_texture[static_cast<size_t>(entity_type)];
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