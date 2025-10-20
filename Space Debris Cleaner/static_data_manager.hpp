#ifndef STATIC_DATA_MANAGER_HPP
#define STATIC_DATA_MANAGER_HPP

#include "definitions.hpp"
#include "polygon.hpp"

namespace sdc {
	class static_data_manager {
	public:
		/**
		* @brief 请求碰撞盒坐标（只读）
		* @input sdc::entity_type entity_type 实体名称
		* @return std::vector<sdc::polygon> 
		* @note  noexcept
		*/
		const std::vector<sdc::polygon>& cbox_coord(sdc::entity_type entity_type) const {
			return this->_cbox_coord[static_cast<size_t>(entity_type)];
		}

		/**
		* @brief 请求贴图大小（只读）
		* @input sdc::entity_type entity_type 实体名称
		* @return sdc::coord
		* @note  noexcept
		*/
		const sdc::coord texture_size(sdc::entity_type entity_type) const {
			return this->_texture_size[static_cast<size_t>(entity_type)];
		}

	private:
		const std::vector<std::vector<sdc::polygon>> _cbox_coord;
		const std::vector<sdc::coord> _texture_size;
	};

}
#endif // !STATIC_DATA_MANAGER_HPP