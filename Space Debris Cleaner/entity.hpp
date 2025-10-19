#ifndef ENTITY_HPP
#define ENTITY_HPP

#include "definitions.hpp"
#include "coord.hpp"
#include "polygon.hpp"
#include "texture_manager.hpp"
#include "static_data_manager.hpp"

namespace sdc {

	/**
	* @class 实体类
	*/
	class entity {
	public:
		entity(
			const sdc::entity_type entity_type,
			const float initial_rotation_degree,
			const sdc::coord initial_coord,
			const sdc::texture_manager& texture_manager,
			const sdc::static_data_manager& static_data_manager
		);

		/**
		* @brief	获取实体旋转角度（顺时针）
		* @input	void
		* @return	float
		* @note		const; noexcept;
		*/
		float get_rotation() const noexcept;

		/**
		* @brief	获取实体的坐标（这里的坐标指贴图的坐标中心）
		* @input	void
		* @return	sdc::coord
		* @note		const; noexcept;
		*/
		sdc::coord get_center_coord() const noexcept;


		/**
		* @brief	获取实体的坐标（这里的坐标指贴图左上角）
		* @input	void
		* @return	sdc::coord
		* @note		const; noexcept;
		*/
		sdc::coord get_left_up_coord() const noexcept;

		/**
		* @brief	获取实体大小
		* @input	void
		* @return	sdc::coord .x代表横向上的大小，.y代表纵向上的大小
		* @note		const; noexcept;
		*/
		sdc::coord get_texture_size() const noexcept;

		/**
		* @brief	获取试题类型
		* @input	void
		* @return	entity_type
		* @note		const; noexcept;
		*/
		entity_type get_entity_type() const noexcept;

		/**
		* @brief	渲染出实体
		* @input	void
		* @return	void
		* @note		const;
		*/
		void render() const;

		/**
		* @brief	检测两个实体是否产生碰撞
		* @input	const entity* const oth 用于检测的实体
		* @return	bool 标志是否产生碰撞
		* @note		const; noexcept;
		*/
		bool is_collide(const entity& oth) const noexcept;

		/**
		* @brief	更新实体信息
		* @input	const sdc::coord& new_center_coord 新的中心坐标
		*			const float new_rotation_degreee 新的旋转角
		* @return	bool 标志是否产生碰撞
		* @note		noexcept;
		*/
		void update(
			const sdc::coord& new_center_coord,
			const float new_rotation_degreee
		) noexcept;

	protected:
		/** @cvar 贴图管理器 */
		const sdc::texture_manager& _texture_manager;

		/** @cvar 静态数据管理器 */
		const sdc::static_data_manager& _static_data_manager;

		/** @var 实体类型 */
		sdc::entity_type _entity_type;

		/** @var 实体大小 */
		sdc::coord _texture_size;

		/** @var 实体相对于竖直方向的顺时针旋转角度（角度） */
		float _rotation_degree;

		/** @var 贴图中心位置 */
		sdc::coord _center_coord;

		/** @var 碰撞盒 */
		std::vector<sdc::polygon> _collision_boxes;

	};
}



#endif // !ENTITY_HPP