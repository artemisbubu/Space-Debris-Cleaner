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
			_coord -= (this->_texture_size * 0.5);
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
	return (this->_center_coord - this->_texture_size * 0.5);
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