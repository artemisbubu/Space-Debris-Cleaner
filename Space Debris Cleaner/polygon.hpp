#ifndef POLYGON_HPP
#define POLYGON_HPP
#include "definitions.hpp"
#include "coord.hpp"

namespace sdc {

	/**
	* @class �������ƶ����
	*/
	class polygon {
	public:
		/**
		* @brief Ĭ�Ϲ��캯��
		* @input void
		* @note	 explicit
		*/
		explicit polygon() = default;

		/**
		* @brief Ĭ�Ϲ��캯��
		* @input const std::vector<coord>& coords
		* @note	 explicit
		*/
		explicit polygon(
			const std::vector<sdc::coord>& coords
		) :
			_coords(coords)
		{}

		/**
		* @brief	�ڲ�coords��ֻ���ӿ�
		* @input	void
		* @return	std::vector<sdc::coord>& 
		* @note		const;noexcept;
		*/
		const std::vector<sdc::coord>& get_coords() const noexcept { return _coords; }

		/**
		* @brief	coords��д�ӿڣ��ƶ�ver.)
		* @input	std::vector<sdc::coord>&& coords д������꣨�ƶ����壩
		* @return	void
		* @note		noexcept;
		*/
		void set_coords(std::vector<sdc::coord>&& coords) noexcept { _coords = std::move(coords); }

		/**
		* @brief	��ȡ�������
		* @input	void
		* @return	size ����
		* @note		const
		*/
		size_t size() const {
			return this->_coords.size();
		}

	private:
		/** @var ���꣬�ڲ��޼�飬�ⲿ���ݱ�֤�������˳ʱ��Χ��һ������� */
		std::vector<sdc::coord> _coords;

	public:
		/** @var ���������������� */
		using iterator = std::vector<sdc::coord>::iterator;

		/** @var ������ֻ������������ */
		using const_iterator = std::vector<sdc::coord>::const_iterator;

		/**
		* @brief �������ӿ� begin()
		*/
		iterator begin() noexcept { return _coords.begin(); }

		/**
		* @brief �������ӿ� end()
		*/
		iterator end() noexcept { return _coords.end(); }

		/**
		* @brief ֻ���������ӿ� begin() const
		*/
		const_iterator begin() const noexcept { return _coords.begin(); }

		/**
		* @brief ֻ���������ӿ� end() const
		*/
		const_iterator end() const noexcept { return _coords.end(); }

		/**
		* @brief ǿ��ֻ���������ӿ� begin() const
		*/
		const_iterator cbegin() const noexcept { return _coords.cbegin(); }

		/**
		* @brief ǿ��ֻ���������ӿ� end() const
		*/
		const_iterator cend() const noexcept { return _coords.cend(); }

		/**
		* @brief	�����±���ʶ��㣨�� const �汾��
		* @input	i �±�
		* @return	sdc::coord& ���޸�����
		*/
		sdc::coord& operator[](std::size_t i) noexcept {
			return _coords[i];
		}

		/**
		* @brief	�����±���ʶ��㣨const �汾��
		* @input	i �±�
		* @return	const sdc::coord& ֻ������
		*/
		const sdc::coord& operator[](std::size_t i) const noexcept {
			return _coords[i];
		}
	};
}

#endif // !POLYGON_HPP
