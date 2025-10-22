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

		/** @cvar 圆周率值*/
		const float PI_VAL = 3.1415927f;

		/** @cvar 容差 */
		const float EPS = 1e-6f;

		/** @cvar 180度常量 */
		constexpr float DEG_180 = 180.0f;

		/**
		* @brief	绕中心坐标旋转点
		* @input	const sdc::coord center	中心坐标
		*			const sdc::coord point	旋转的点坐标
		*			const float	rotation_degree	旋转角度
		* @return	sdc::coord 旋转结果
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
		* @brief	绕中心坐标旋转多边形
		* @input	sdc::coord center	中心坐标
		*			sdc::polygon& polygon 多边形
		*			const float	rotation_degree	旋转角度
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
		* @brief	据中心坐标放缩
		* @input	sdc::coord center	中心坐标
		*			sdc::coord point	点
		*			const float	scaling_ratio 放缩比例
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
		* @brief	据中心坐标放缩
		* @input	sdc::coord center	中心坐标
		*			sdc::polygon& polygon 多边形 
		*			const float	scaling_ratio 放缩比例
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
