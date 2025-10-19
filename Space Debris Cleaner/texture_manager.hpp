#ifndef TEXTURE_MANAGER_HPP
#define TEXTURE_MANAGER_HPP

#include "definitions.hpp"
#include <raylib.h>
#include "config_manager.hpp"

namespace sdc {
	class texture_manager {
	public:
		texture_manager(
			const sdc::config_manager& cm	// 用于获取加载路径，无需关注加载逻辑
		):
			_entity_texture(static_cast<int>(sdc::entity_type::SIZE)),
			_scene_texture(static_cast<int>(sdc::scene_type::SIZE))
		{
			// ... 加载逻辑
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