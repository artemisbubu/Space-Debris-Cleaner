#ifndef POLYGON_HPP
#define POLYGON_HPP
#include "definitions.hpp"
#include "coord.hpp"

namespace sdc {

	/**
	* @class 采样近似多边形
	*/
	class polygon {
	public:
		/**
		* @brief 默认构造函数
		* @input void
		* @note	 explicit
		*/
		explicit polygon() = default;

		/**
		* @brief 默认构造函数
		* @input const std::vector<coord>& coords
		* @note	 explicit
		*/
		explicit polygon(
			const std::vector<sdc::coord>& coords
		) :
			_coords(coords)
		{}

		/**
		* @brief	内部coords的只读接口
		* @input	void
		* @return	std::vector<sdc::coord>& 
		* @note		const;noexcept;
		*/
		const std::vector<sdc::coord>& get_coords() const noexcept { return _coords; }

		/**
		* @brief	coords的写接口（移动ver.)
		* @input	std::vector<sdc::coord>&& coords 写入的坐标（移动语义）
		* @return	void
		* @note		noexcept;
		*/
		void set_coords(std::vector<sdc::coord>&& coords) noexcept { _coords = std::move(coords); }

		/**
		* @brief	获取点的数量
		* @input	void
		* @return	size 数量
		* @note		const
		*/
		size_t size() const {
			return this->_coords.size();
		}

	private:
		/** @var 坐标，内部无检查，外部数据保证坐标点是顺时针围成一个多边形 */
		std::vector<sdc::coord> _coords;

	public:
		/** @var 重命名迭代器变量 */
		using iterator = std::vector<sdc::coord>::iterator;

		/** @var 重命名只读迭代器变量 */
		using const_iterator = std::vector<sdc::coord>::const_iterator;

		/**
		* @brief 迭代器接口 begin()
		*/
		iterator begin() noexcept { return _coords.begin(); }

		/**
		* @brief 迭代器接口 end()
		*/
		iterator end() noexcept { return _coords.end(); }

		/**
		* @brief 只读迭代器接口 begin() const
		*/
		const_iterator begin() const noexcept { return _coords.begin(); }

		/**
		* @brief 只读迭代器接口 end() const
		*/
		const_iterator end() const noexcept { return _coords.end(); }

		/**
		* @brief 强制只读迭代器接口 begin() const
		*/
		const_iterator cbegin() const noexcept { return _coords.cbegin(); }

		/**
		* @brief 强制只读迭代器接口 end() const
		*/
		const_iterator cend() const noexcept { return _coords.cend(); }

		/**
		* @brief	允许下标访问顶点（非 const 版本）
		* @input	i 下标
		* @return	sdc::coord& 可修改引用
		*/
		sdc::coord& operator[](std::size_t i) noexcept {
			return _coords[i];
		}

		/**
		* @brief	允许下标访问顶点（const 版本）
		* @input	i 下标
		* @return	const sdc::coord& 只读引用
		*/
		const sdc::coord& operator[](std::size_t i) const noexcept {
			return _coords[i];
		}
	};
}

#endif // !POLYGON_HPP
