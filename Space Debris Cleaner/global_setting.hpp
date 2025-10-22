#ifndef GLOBAL_SETTING_HPP
#define GLOBAL_SETTING_HPP
#include <nlohmann/json.hpp>
#include "texture_manager.hpp"

/** @class global */
class global_setting {
public:
	// Ĭ�Ϲ��캯��
	global_setting() = default;

	// �ƶ����캯��
	global_setting(
		nlohmann::json&& config, 
		sdc::texture_manager&& texture_manager
	): 
		config(std::move(config)),
		texture_manager(std::move(texture_manager)) 
	{}

	//// �������캯���������汾��
	//global_setting(const nlohmann::json& cfg, const sdc::texture_manager& tex)
	//	: config(cfg), texture_manager(tex) {}

	nlohmann::json config;
	sdc::texture_manager texture_manager;
};

#endif // !GLOBAL_SETTING_HPP
