#ifndef ENTITY_HPP
#define ENTITY_HPP

#include "definitions.hpp"
#include "coord.hpp"
#include "polygon.hpp"
#include "texture_manager.hpp"
#include "static_data_manager.hpp"

namespace sdc {

	/**
	* @class ʵ����
	*/
	class entity {
	public:
		entity(
			const sdc::entity_type entity_type,
			const float initial_rotation_degree,
			const sdc::coord initial_coord,
			const sdc::texture_manager& texture_manager,
			const sdc::static_data_manager& static_data_manager
		);

		/**
		* @brief	��ȡʵ����ת�Ƕȣ�˳ʱ�룩
		* @input	void
		* @return	float
		* @note		const; noexcept;
		*/
		float get_rotation() const noexcept;

		/**
		* @brief	��ȡʵ������꣨���������ָ��ͼ���������ģ�
		* @input	void
		* @return	sdc::coord
		* @note		const; noexcept;
		*/
		sdc::coord get_center_coord() const noexcept;


		/**
		* @brief	��ȡʵ������꣨���������ָ��ͼ���Ͻǣ�
		* @input	void
		* @return	sdc::coord
		* @note		const; noexcept;
		*/
		sdc::coord get_left_up_coord() const noexcept;

		/**
		* @brief	��ȡʵ���С
		* @input	void
		* @return	sdc::coord .x��������ϵĴ�С��.y���������ϵĴ�С
		* @note		const; noexcept;
		*/
		sdc::coord get_texture_size() const noexcept;

		/**
		* @brief	��ȡ��������
		* @input	void
		* @return	entity_type
		* @note		const; noexcept;
		*/
		entity_type get_entity_type() const noexcept;

		/**
		* @brief	��Ⱦ��ʵ��
		* @input	void
		* @return	void
		* @note		const;
		*/
		void render() const;

		/**
		* @brief	�������ʵ���Ƿ������ײ
		* @input	const entity* const oth ���ڼ���ʵ��
		* @return	bool ��־�Ƿ������ײ
		* @note		const; noexcept;
		*/
		bool is_collide(const entity& oth) const noexcept;

		/**
		* @brief	����ʵ����Ϣ
		* @input	const sdc::coord& new_center_coord �µ���������
		*			const float new_rotation_degreee �µ���ת��
		* @return	bool ��־�Ƿ������ײ
		* @note		noexcept;
		*/
		void update(
			const sdc::coord& new_center_coord,
			const float new_rotation_degreee
		) noexcept;

	protected:
		/** @cvar ��ͼ������ */
		const sdc::texture_manager& _texture_manager;

		/** @cvar ��̬���ݹ����� */
		const sdc::static_data_manager& _static_data_manager;

		/** @var ʵ������ */
		sdc::entity_type _entity_type;

		/** @var ʵ���С */
		sdc::coord _texture_size;

		/** @var ʵ���������ֱ�����˳ʱ����ת�Ƕȣ��Ƕȣ� */
		float _rotation_degree;

		/** @var ��ͼ����λ�� */
		sdc::coord _center_coord;

		/** @var ��ײ�� */
		std::vector<sdc::polygon> _collision_boxes;

	};
}



#endif // !ENTITY_HPP