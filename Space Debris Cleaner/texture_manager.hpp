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
			// 资源检查应该交给launcher来做，类内部不进行资源检查，默认config已经是合规的
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
		* @brief	请求只读资源
		* @input	sdc::entity_type entity_type 实体名称
		* @return	const texture& 资源的只读引用
		* @note		const
		*/
		const Texture2D& request(const sdc::entity_type entity_type) const {
			return _entity_texture[static_cast<size_t>(entity_type)];
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