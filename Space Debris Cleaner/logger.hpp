#include <string>
#ifndef LOGGER_HPP
#define LOGGER_HPP

/** @namespace sdc*/
namespace sdc {

	/** @namespace logger*/
	namespace logger
	{
		// ������ɫת������
		namespace COLOR
		{
			const std::string _WHITE = "\033[0m";
			const std::string _RED = "\033[31m";
			const std::string _BLUE = "\033[34m";
			const std::string _YELLOW = "\033[33m";
			const std::string _GREEN = "\033[32m";
		}

		/**
		* @brief	�Զ�����Ϣ��ӡ
		* @input	const std::string& content	��ӡ����Ϣ
		*			const std::string& color	��ӡ����ɫת������
		*			const std::string& label	����������ʾ�ı�ǩ
		* @return	void
		*/
		void log(const std::string& content, const std::string& color = COLOR::_WHITE, const std::string& label = "LOG");

		/**
		* @brief	������Ϣ��ӡ
		* @input	const std::string& content	��ӡ����Ϣ
		*			const std::string& label	����������ʾ�ı�ǩ��Ĭ�� "ERROR"��
		* @return	void
		*/
		void error(const std::string& content, const std::string& label = "ERROR");

		/**
		* @brief	��ͨ��Ϣ��ӡ
		* @input	const std::string& content	��ӡ����Ϣ
		*			const std::string& label	����������ʾ�ı�ǩ��Ĭ�� "INFO"��
		* @return	void
		*/
		void info(const std::string& content, const std::string& label = "INFO");

		/**
		* @brief	������Ϣ��ӡ
		* @input	const std::string& content	��ӡ����Ϣ
		*			const std::string& label	����������ʾ�ı�ǩ��Ĭ�� "WARN"��
		* @return	void
		*/
		void warn(const std::string& content, const std::string& label = "WARN");

		/**
		* @brief	��Ҫ��Ϣ��ӡ
		* @input	const std::string& content	��ӡ����Ϣ
		*			const std::string& label	����������ʾ�ı�ǩ��Ĭ�� "VITAL"��
		* @return	void
		*/
		void vital(const std::string& content, const std::string& label = "VITAL");

		/**
		* @brief	�ɹ���Ϣ��ӡ
		* @input	const std::string& content	��ӡ����Ϣ
		*			const std::string& label	����������ʾ�ı�ǩ��Ĭ�� "SUCCESS"��
		* @return	void
		*/
		void success(const std::string& content, const std::string& label = "SUCCESS");
	}

}
#endif // !LOGGER_HPP
