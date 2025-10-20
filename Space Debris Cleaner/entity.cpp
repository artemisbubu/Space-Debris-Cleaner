#include "entity.hpp"
#include "math.hpp"

#include <chrono>
#include <iostream>

// entity
sdc::entity::entity(
	const sdc::entity_type entity_type,
	const float initial_rotation_degree,
	const sdc::coord initial_coord,
	const sdc::texture_manager& texture_manager,
	const sdc::static_data_manager& static_data_manager
) :
	_entity_type(entity_type),
	_rotation_degree(initial_rotation_degree),
	_center_coord(initial_coord),
	_texture_manager(texture_manager),
	_static_data_manager(static_data_manager)
{
	// 通过_static_data_manager初始化贴图大小
	_texture_size = _static_data_manager.texture_size(this->_entity_type);

	// 通过_static_data_manager初始化碰撞盒坐标
	this->_collision_boxes = static_data_manager.cbox_coord(this->_entity_type);
	for (auto& _collision_box : this->_collision_boxes) {
		for (auto& _coord : _collision_box) {
			//_coord += this->get_left_up_coord();
			_coord += this->_center_coord;
			_coord -= (this->_texture_size * 0.5f);
		}
	}
}

float sdc::entity::get_rotation() const noexcept {
	return this->_rotation_degree;
}

sdc::coord sdc::entity::get_center_coord() const noexcept {
	return this->_center_coord;
}

sdc::coord sdc::entity::get_left_up_coord() const noexcept {
	return (this->_center_coord - this->_texture_size * 0.5f);
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
	// 获取纹理
	const Texture2D& texture = this->_texture_manager.request(this->_entity_type);
	
	// 采样整张纹理
	Rectangle source = { 0.0f, 0.0f, (float)texture.width, (float)texture.height };
	
	// 旋转中心
	sdc::coord sdc_center = this->_center_coord;
	Vector2 raylib_center = { sdc_center.x, sdc_center.y };

	// 目标区域
	sdc::coord sdc_texture_size = this->_texture_size;
	Rectangle dest = {
		sdc_center.x - 0.5f * sdc_texture_size.x,
		sdc_center.y - 0.5f * sdc_texture_size.y,
		static_cast<float>(texture.width),
		static_cast<float>(texture.height)
	};

	// 渲染
	DrawTexturePro(
		texture,
		source,
		dest,
		raylib_center,
		this->_rotation_degree,     
		WHITE
	);
}


void sdc::entity::update(
	const sdc::coord& new_center_coord,
	const float new_rotation_degree
) noexcept {
	this->_center_coord = new_center_coord;
	this->_rotation_degree = new_rotation_degree;

	for (auto& _collison_box : this->_collision_boxes) {
		sdc::math::rotate(
			this->_center_coord,
			_collison_box, 
			this->_rotation_degree
		);
	}
}