#ifndef MATH_HPP
#define MATH_HPP

#include "definitions.hpp"
#include "coord.hpp"
#include "polygon.hpp"
#include <cmath>
#include "segment.hpp"

namespace sdc {
	namespace math {
		/** @cvar 圆周率值*/
		const float PI = 3.1415927f;

		/** @cvar 容差 */
		const float EPS = 1e-6f;

		/** @cvar 180度常量 */
		constexpr float DEG_180 = 180.0f;

		/**
		* @brief	绕center旋转point点rotation度（角度），得到的point'坐标
		* @input	const sdc::coord center	中心坐标
		*			const sdc::coord point	旋转的点坐标
		*			const float	rotation	旋转角度
		* @return	sdc::coord 旋转结果
		* @note		inline; noexcept;
		*/
		inline sdc::coord rotate(
			const sdc::coord center,
			const sdc::coord point,
			const float rotation
		)noexcept {
			float rad = rotation * sdc::math::PI / sdc::math::DEG_180;

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
		* @brief	绕center旋转point点rotation度（角度），得到的point'坐标
		* @input	sdc::coord> center	中心坐标
		*			const std::vector<sdc::coord>& point_s	旋转的点坐标
		*			const float	rotation	旋转角度
		* @return	void
		* @note		inline; noexcept;
		*/
		inline void rotate(
			const sdc::coord center,
			sdc::polygon& polygon,
			const float rotation
		) noexcept {
			const float rad = rotation * sdc::math::PI / sdc::math::DEG_180;
			const float cos_r = std::cos(rad);
			const float sin_r = std::sin(rad);

			for (sdc::coord& coord : polygon) {
				const float dx = coord.x - center.x;
				const float dy = coord.y - center.y;
				coord.x = center.x + dx * cos_r - dy * sin_r;
				coord.y = center.y + dx * sin_r + dy * cos_r;
			}
		}


		/**
		* @brief	计算两个向量的内积结果
		* @input	const sdc::coord v1
		*			const sdc::coord v2
		* @return	float 内积结果
		* @note		noexcept;
		*/
		inline float inner_product(
			const sdc::coord v1,
			const sdc::coord v2
		) noexcept {
			return (v1.x * v2.x + v1.y * v2.y);
		}

		/**
		* @brief	计算两个向量的外积结果
		* @input	const sdc::coord v1
		*			const sdc::coord v2
		* @return	float 外积结果
		* @note		inline; noexcept;
		*/
		inline float cross_product(
			const sdc::coord v1,
			const sdc::coord v2
		) noexcept {
			return (v1.x * v2.y - v1.y * v2.x);
		}

		/**
		* @brief	判断 c 是否在 [min(a,b), max(a,b)] 内
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
		* @brief    判断两线段是否相交
		* @input    const sdc::segment s1,
		*           const sdc::segment s2
		* @return   bool  若相交则返回 true，否则返回 false
		* @note     noexcept;
		*/
		bool is_intersected(
			const sdc::segment s1,
			const sdc::segment s2
		) noexcept;

		/**
		* @brief    判断两多边形是否相交
		* @input    const sdc::polygon& p1,
		*			const sdc::polygon& p2
		* @return   bool  若相交则返回 true，否则返回 false
		* @note     noexcept;
		* @tips		外部数据要保证：凸多边形
		*/
		bool is_intersected(
			const sdc::polygon& p1,
			const sdc::polygon& p2
		) noexcept;

	}
}
#endif // !MATH_HPP
