#ifndef GLOBAL_SETTING_HPP
#define GLOBAL_SETTING_HPP
#include <nlohmann/json.hpp>
#include "texture_manager.hpp"

/** @class global */
class global_setting {
public:
	// 默认构造函数
	global_setting() = default;

	// 移动构造函数
	global_setting(
		nlohmann::json&& config, 
		sdc::texture_manager&& texture_manager
	): 
		config(std::move(config)),
		texture_manager(std::move(texture_manager)) 
	{}

	//// 拷贝构造函数（遗弃版本）
	//global_setting(const nlohmann::json& cfg, const sdc::texture_manager& tex)
	//	: config(cfg), texture_manager(tex) {}

	nlohmann::json config;
	sdc::texture_manager texture_manager;
};

#endif // !GLOBAL_SETTING_HPP
