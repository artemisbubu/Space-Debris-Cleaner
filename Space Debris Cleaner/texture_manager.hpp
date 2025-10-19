#ifndef TEXTURE_MANAGER_HPP
#define TEXTURE_MANAGER_HPP

#include "definitions.hpp"

namespace sdc {
	class texture_manager {
		using texture = int;
	public:

	public:
		/** 
		* @brief	����ֻ����Դ
		* @input	sdc::entity_type entity_type ʵ������
		* @return	const texture& ��Դ��ֻ������
		* @note		const
		*/
		const texture& request(sdc::entity_type entity_type) const;

		/**
		* @brief	����ֻ����Դ
		* @input	sdc::scene_type scene_type ��������
		* @return	const texture& ��Դ��ֻ������
		* @note		const
		*/
		const texture& request(sdc::scene_type scenen_type) const;

	private:
	};

} 
#endif // !TEXTURE_MANAGER_HPP