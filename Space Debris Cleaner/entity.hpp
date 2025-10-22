#ifndef ENTITY_HPP
#define ENTITY_HPP

#include "coord.hpp"
#include "polygon.hpp"
#include <vector>
#include <raylib.h>

/** @namespace sdc*/
namespace sdc {

	/** @enumclass ö��ʵ������ */
	enum class entity_type {
		stone_1,
		stone_2,
		stone_3,
		size
	};

	/** @class ʵ���� */
	class entity {
	public:
		entity(
			const sdc::entity_type entity_type,
			const float initial_rotation_degree,
			const sdc::coord initial_coord,
			const std::vector<sdc::polygon>& origin_collision_boxes,
			const Texture2D& texture
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
			const float new_rotation_degreee,
			const float new_scaling_ratio = 1.0f
		) noexcept;

	protected:
		/** @cvar ʵ������ */
		const sdc::entity_type _entity_type;

		/** @cvar ���ʣ���ͼ����ϵ�� */
		const Texture2D& _texture;

		/** @cvar ԭʼ��ײ�����꣨��ͼ����ϵ�� */
		const std::vector<sdc::polygon> _origin_collision_boxes;

		/** @var ʵ���������ֱ�����˳ʱ����ת�Ƕȣ��Ƕȣ� */
		float _rotation_degree;

		/** @var ���ʴ�С */
		sdc::coord _texture_size;

		/** @var ��ͼ����λ�� */
		sdc::coord _center_coord;

		/** @var ��ײ�� */
		std::vector<sdc::polygon> _collision_boxes;

		/** @var ��������*/
		float _scaling_ratio;
	};
}



#endif // !ENTITY_HPP