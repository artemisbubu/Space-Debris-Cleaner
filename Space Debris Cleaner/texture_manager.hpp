#ifndef TEXTURE_MANAGER_HPP
#define TEXTURE_MANAGER_HPP

#include "definitions.hpp"

namespace sdc {
	class texture_manager {
		using texture = int;
	public:

	public:
		/** 
		* @brief	请求只读资源
		* @input	sdc::entity_type entity_type 实体名称
		* @return	const texture& 资源的只读引用
		* @note		const
		*/
		const texture& request(sdc::entity_type entity_type) const;

		/**
		* @brief	请求只读资源
		* @input	sdc::scene_type scene_type 场景名称
		* @return	const texture& 资源的只读引用
		* @note		const
		*/
		const texture& request(sdc::scene_type scenen_type) const;

	private:
	};

} 
#endif // !TEXTURE_MANAGER_HPP