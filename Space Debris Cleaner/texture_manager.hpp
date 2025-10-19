#ifndef TEXTURE_MANAGER_HPP
#define TEXTURE_MANAGER_HPP

#include "definitions.hpp"
#include <raylib.h>
#include "config_manager.hpp"

namespace sdc {
	class texture_manager {
	public:
		texture_manager(
			const sdc::config_manager& cm	// ���ڻ�ȡ����·���������ע�����߼�
		):
			_entity_texture(static_cast<int>(sdc::entity_type::SIZE)),
			_scene_texture(static_cast<int>(sdc::scene_type::SIZE))
		{
			// ... �����߼�
		}

		/** 
		* @brief	����ֻ����Դ
		* @input	sdc::entity_type entity_type ʵ������
		* @return	const texture& ��Դ��ֻ������
		* @note		const
		*/
		const Texture2D& request(const sdc::entity_type entity_type) const {

		}

		/**
		* @brief	����ֻ����Դ
		* @input	sdc::scene_type scene_type ��������
		* @return	const texture& ��Դ��ֻ������
		* @note		const
		*/
		const Texture2D& request(const sdc::scene_type scene_type) const;

	private:
		/** @var ʵ������ */
		std::vector<Texture2D> _entity_texture;
		
		/** @var �������� */
		std::vector<Texture2D> _scene_texture;
	};

} 
#endif // !TEXTURE_MANAGER_HPP