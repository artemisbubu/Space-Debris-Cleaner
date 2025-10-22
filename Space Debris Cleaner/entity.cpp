#include "entity.hpp"
#include "math.hpp"

#include <chrono>
#include <iostream>

// entity
sdc::entity::entity(
	const sdc::entity_type entity_type,
	const float initial_rotation_degree,
	const sdc::coord initial_coord,
	const std::vector<sdc::polygon>& origin_collision_boxes,
	const Texture2D& texture
) : 
	_entity_type(entity_type),
	_rotation_degree(initial_rotation_degree),
	_center_coord(initial_coord),
	_origin_collision_boxes(origin_collision_boxes),
	_collision_boxes(origin_collision_boxes),
	_texture(texture),
	_texture_size(
		sdc::coord(
			static_cast<float>(_texture.width),
			static_cast<float>(_texture.height)
		)
	),
	_scaling_ratio(1.0f)
{}

float sdc::entity::get_rotation() const noexcept {
	return this->_rotation_degree;
}

sdc::coord sdc::entity::get_center_coord() const noexcept {
	return this->_center_coord;
}

sdc::coord sdc::entity::get_left_up_coord() const noexcept {
	return (this->_center_coord - sdc::coord()* 0.5f);
}

sdc::coord sdc::entity::get_texture_size() const noexcept {
	return this->_texture_size;
}

sdc::entity_type sdc::entity::get_entity_type() const noexcept {
	return this->_entity_type;
}

bool sdc::entity::is_collide(const sdc::entity& oth) const noexcept {
	return false;
}

void sdc::entity::render() const {
	// 采样整张纹理
	Rectangle source = { 0.0f, 0.0f, 
		static_cast<float>(_texture.width), 
		static_cast<float>(_texture.height) 
	};
	
	// 旋转中心
	sdc::coord sdc_center = this->_center_coord;
	Vector2 raylib_center = { sdc_center.x, sdc_center.y };

	// 目标区域
	sdc::coord sdc_texture_size = _texture_size;
	Rectangle dest = {
		sdc_center.x - 0.5f * sdc_texture_size.x,
		sdc_center.y - 0.5f * sdc_texture_size.y,
		static_cast<float>(_texture.width),
		static_cast<float>(_texture.height)
	};

	// 渲染
	DrawTexturePro(
		_texture,
		source,
		dest,
		raylib_center,
		this->_rotation_degree,     
		WHITE
	);
}

void sdc::entity::update(
	const sdc::coord& new_center_coord,
	const float new_rotation_degree,
	const float new_scaling_ratio
) noexcept {
	// 朴素更新方法
	this->_center_coord = new_center_coord;
	this->_rotation_degree = new_rotation_degree;
	this->_scaling_ratio = new_scaling_ratio;
	
	this->_collision_boxes = this->_origin_collision_boxes; // 主要测量开销
	
	// 更新碰撞盒坐标
	for (auto& collision_box : this->_collision_boxes) {
		for (auto& point : collision_box) {
			point += this->_center_coord;
			point -= (_texture_size * 0.5f);
		}
	}

	// 旋转坐标
	for (auto& collison_box : this->_collision_boxes) {
		sdc::math::rotate(
			this->_center_coord,
			collison_box, 
			this->_rotation_degree
		);
	}

	// 若放缩比例为1.0f，则不做处理
	if (std::fabs(new_scaling_ratio - 1.0f) < sdc::math::EPS) {
		return;
	}

	// 放缩坐标
	for (auto& collison_box : this->_collision_boxes) {
		sdc::math::scale(
			this->_center_coord,
			collison_box,
			new_scaling_ratio
		);
	}
}