#ifndef ENTITY_HPP
#define ENTITY_HPP

#include "coord.hpp"
#include "polygon.hpp"
#include <vector>
#include <raylib.h>

/** @namespace sdc*/
namespace sdc {

	/** @enumclass 枚举实体类型 */
	enum class entity_type {
		stone_1,
		stone_2,
		stone_3,
		size
	};

	/** @class 实体类 */
	class entity {
	public:
		entity(
			const sdc::entity_type entity_type,
			const float initial_rotation_degree,
			const sdc::coord initial_coord,
			const std::vector<sdc::polygon>& origin_collision_boxes,
			const Texture2D& texture
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
			const float new_rotation_degreee,
			const float new_scaling_ratio = 1.0f
		) noexcept;

	protected:
		/** @cvar 实体类型 */
		const sdc::entity_type _entity_type;

		/** @cvar 材质（贴图坐标系） */
		const Texture2D& _texture;

		/** @cvar 原始碰撞盒坐标（贴图坐标系） */
		const std::vector<sdc::polygon> _origin_collision_boxes;

		/** @var 实体相对于竖直方向的顺时针旋转角度（角度） */
		float _rotation_degree;

		/** @var 材质大小 */
		sdc::coord _texture_size;

		/** @var 贴图中心位置 */
		sdc::coord _center_coord;

		/** @var 碰撞盒 */
		std::vector<sdc::polygon> _collision_boxes;

		/** @var 放缩比例*/
		float _scaling_ratio;
	};
}



#endif // !ENTITY_HPP