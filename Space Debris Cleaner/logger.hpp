#include <string>
#ifndef LOGGER_HPP
#define LOGGER_HPP

/** @namespace sdc*/
namespace sdc {

	/** @namespace logger*/
	namespace logger
	{
		// 定义颜色转义序列
		namespace COLOR
		{
			const std::string _WHITE = "\033[0m";
			const std::string _RED = "\033[31m";
			const std::string _BLUE = "\033[34m";
			const std::string _YELLOW = "\033[33m";
			const std::string _GREEN = "\033[32m";
		}

		/**
		* @brief	自定义信息打印
		* @input	const std::string& content	打印的信息
		*			const std::string& color	打印的颜色转义序列
		*			const std::string& label	方括号内显示的标签
		* @return	void
		*/
		void log(const std::string& content, const std::string& color = COLOR::_WHITE, const std::string& label = "LOG");

		/**
		* @brief	错误信息打印
		* @input	const std::string& content	打印的信息
		*			const std::string& label	方括号内显示的标签（默认 "ERROR"）
		* @return	void
		*/
		void error(const std::string& content, const std::string& label = "ERROR");

		/**
		* @brief	普通信息打印
		* @input	const std::string& content	打印的信息
		*			const std::string& label	方括号内显示的标签（默认 "INFO"）
		* @return	void
		*/
		void info(const std::string& content, const std::string& label = "INFO");

		/**
		* @brief	警告信息打印
		* @input	const std::string& content	打印的信息
		*			const std::string& label	方括号内显示的标签（默认 "WARN"）
		* @return	void
		*/
		void warn(const std::string& content, const std::string& label = "WARN");

		/**
		* @brief	重要信息打印
		* @input	const std::string& content	打印的信息
		*			const std::string& label	方括号内显示的标签（默认 "VITAL"）
		* @return	void
		*/
		void vital(const std::string& content, const std::string& label = "VITAL");

		/**
		* @brief	成功信息打印
		* @input	const std::string& content	打印的信息
		*			const std::string& label	方括号内显示的标签（默认 "SUCCESS"）
		* @return	void
		*/
		void success(const std::string& content, const std::string& label = "SUCCESS");
	}

}
#endif // !LOGGER_HPP
