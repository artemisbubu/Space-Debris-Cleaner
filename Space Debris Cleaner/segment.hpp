#ifndef SEGMENT_HPP
#define SEGMENT_HPP
#include "definitions.hpp"
#include "coord.hpp"

namespace sdc {
	class segment {
	public:
		/**
		* @brief	Ĭ�Ϲ��캯��
		* @input	void
		* @note		explicit;
		*/
		explicit segment() = default;
		
		/**
		* @brief	���캯��
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
		* @brief	��ȡ�߶γ�
		* @input	void
		* @return	float �߶γ�
		* @note		const;
		*/
		float len() const;

	public:
		/* @var �߶εĶ˵�1 */
		sdc::coord c1;

		/* @var �߶εĶ˵�2 */
		sdc::coord c2;
	};
}

#endif // !SEGMENT_HPP
