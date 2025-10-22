#ifndef TEXTURE_MANAGER_HPP
#define TEXTURE_MANAGER_HPP

#include "entity.hpp"
#include "scene.hpp"
#include <iostream>
#include <fstream>
#include <raylib.h>
#include <nlohmann/json.hpp>
#include <string>

/** @namespace sdc*/
namespace sdc {
	
	/** @class texture_manager */
	class texture_manager {
	public:
		//texture_manager() = default;
		texture_manager(
			const nlohmann::json& config
		):
			_entity_texture(static_cast<size_t>(sdc::entity_type::size)),
			_scene_texture(static_cast<size_t>(sdc::scene_type::size))
		{
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

		~texture_manager() = default;

		/** 
		* @brief	请求只读资源
		* @input	sdc::entity_type entity_type 实体名称
		* @return	const texture& 资源的只读引用
		* @note		const
		*/
		const Texture2D& request_texture(const sdc::entity_type entity_type) const {
			return _entity_texture[static_cast<size_t>(entity_type)];
		}

		/**
		* @brief	请求只读资源
		* @input	sdc::scene_type scene_type 场景名称
		* @return	const texture& 资源的只读引用
		* @note		const
		*/
		const Texture2D& request_texture(const sdc::scene_type scene_type) const;

		/**
		* @brief	获取碰撞盒坐标
		* @input	sdc::entity_type entity_type 
		* @return	std::vector<sdc::polygon>
		* @note		noexcept
		*/
		const std::vector<sdc::polygon>& cbox_coord(sdc::entity_type entity_type) const {
			return this->entities_cboxes_coords[static_cast<size_t>(entity_type)];
		}

	private:
		/** @var 实体纹理 */
		std::vector<Texture2D> _entity_texture;
		
		/** @var 场景纹理 */
		std::vector<Texture2D> _scene_texture;

		/** @var 实体坐标 */
		std::vector<std::vector<sdc::polygon>> entities_cboxes_coords;
	};

} 
#endif // !TEXTURE_MANAGER_HPP