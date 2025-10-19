#ifndef SEGMENT_HPP
#define SEGMENT_HPP
#include "definitions.hpp"
#include "coord.hpp"

namespace sdc {
	class segment {
	public:
		/**
		* @brief	默认构造函数
		* @input	void
		* @note		explicit;
		*/
		explicit segment() = default;
		
		/**
		* @brief	构造函数
		* @input	const sdc::coord c1,
		*			const sdc::coord c2,
		* @note		explicit;
		*/
		explicit segment(
			const sdc::coord c1, 
			const sdc::coord c2
		) : 
			c1(c1), c2(c2) 
		{}
		
		/**
		* @brief	获取线段长
		* @input	void
		* @return	float 线段长
		* @note		const;
		*/
		float len() const;

	public:
		/* @var 线段的端点1 */
		sdc::coord c1;

		/* @var 线段的端点2 */
		sdc::coord c2;
	};
}

#endif // !SEGMENT_HPP
