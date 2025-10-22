#ifndef MATH_HPP
#define MATH_HPP

#include "coord.hpp"
#include "polygon.hpp"
#include "segment.hpp"


#include <cmath>

/** @namespace sdc*/
namespace sdc {

	/** @namespace math*/
	namespace math {

		/** @cvar Բ����ֵ*/
		const float PI_VAL = 3.1415927f;

		/** @cvar �ݲ� */
		const float EPS = 1e-6f;

		/** @cvar 180�ȳ��� */
		constexpr float DEG_180 = 180.0f;

		/**
		* @brief	������������ת��
		* @input	const sdc::coord center	��������
		*			const sdc::coord point	��ת�ĵ�����
		*			const float	rotation_degree	��ת�Ƕ�
		* @return	sdc::coord ��ת���
		* @note		inline; noexcept;
		*/
		inline sdc::coord rotate(
			const sdc::coord center,
			const sdc::coord point,
			const float rotation
		)noexcept {
			float rad = rotation * sdc::math::PI_VAL / sdc::math::DEG_180;

			float dx = point.x - center.x;
			float dy = point.y - center.y;

			float cos_r = std::cos(rad);
			float sin_r = std::sin(rad);

			return sdc::coord(
				center.x + dx * cos_r - dy * sin_r,
				center.y + dx * sin_r + dy * cos_r
			);
		}


		/**
		* @brief	������������ת�����
		* @input	sdc::coord center	��������
		*			sdc::polygon& polygon �����
		*			const float	rotation_degree	��ת�Ƕ�
		* @return	void
		* @note		inline; noexcept;
		*/
		inline void rotate(
			const sdc::coord center,
			sdc::polygon& polygon,
			const float rotation_degree
		) noexcept {
			const float rad = rotation_degree * sdc::math::PI_VAL / sdc::math::DEG_180;
			const float cos_r = std::cos(rad);
			const float sin_r = std::sin(rad);
			
			for (sdc::coord& coord : polygon) {
				const sdc::coord delta = coord - center;
				coord.x = center.x + delta.x * cos_r - delta.y * sin_r;
				coord.y = center.y + delta.x * sin_r + delta.y * cos_r;
			}
		}
		
		/**
		* @brief	�������������
		* @input	sdc::coord center	��������
		*			sdc::coord point	��
		*			const float	scaling_ratio ��������
		* @return	void
		* @note		inline; noexcept;
		*/
		inline void scale(
			const sdc::coord center,
			sdc::coord point,
			const float scaling_ratio
		) noexcept {
			point -= center;
			point *= scaling_ratio;
			point += center;
		}

		/**
		* @brief	�������������
		* @input	sdc::coord center	��������
		*			sdc::polygon& polygon ����� 
		*			const float	scaling_ratio ��������
		* @return	void
		* @note		inline; noexcept;
		*/
		inline void scale(
			const sdc::coord center,
			sdc::polygon& polygon,
			const float scaling_ratio
		) noexcept {
			for (auto& point : polygon) {
				point -= center;
				point *= scaling_ratio;
				point += center;
			}
		}


		/**
		* @brief	���������������ڻ����
		* @input	const sdc::coord v1
		*			const sdc::coord v2
		* @return	float �ڻ����
		* @note		noexcept;
		*/
		inline float inner_product(
			const sdc::coord v1,
			const sdc::coord v2
		) noexcept {
			return (v1.x * v2.x + v1.y * v2.y);
		}

		/**
		* @brief	��������������������
		* @input	const sdc::coord v1
		*			const sdc::coord v2
		* @return	float ������
		* @note		inline; noexcept;
		*/
		inline float cross_product(
			const sdc::coord v1,
			const sdc::coord v2
		) noexcept {
			return (v1.x * v2.y - v1.y * v2.x);
		}

		/**
		* @brief	�ж� c �Ƿ��� [min(a,b), max(a,b)] ��
		* @input	float a,
		*			float b,
		*			float c
		* @return	bool
		* @note		inline; noexcept;
		*/
		inline bool in_range(float a, float b, float c) noexcept {
			return (std::min(a, b) <= c + sdc::math::EPS)
				&& (c <= std::max(a, b) + sdc::math::EPS);
		}


		/**
		* @brief    �ж����߶��Ƿ��ཻ
		* @input    const sdc::segment s1,
		*           const sdc::segment s2
		* @return   bool  ���ཻ�򷵻� true�����򷵻� false
		* @note     noexcept;
		*/
		bool is_intersected(
			const sdc::segment s1,
			const sdc::segment s2
		) noexcept;

		/**
		* @brief    �ж���������Ƿ��ཻ
		* @input    const sdc::polygon& p1,
		*			const sdc::polygon& p2
		* @return   bool  ���ཻ�򷵻� true�����򷵻� false
		* @note     noexcept;
		* @tips		�ⲿ����Ҫ��֤��͹�����
		*/
		bool is_intersected(
			const sdc::polygon& p1,
			const sdc::polygon& p2
		) noexcept;

	}
}
#endif // !MATH_HPP
