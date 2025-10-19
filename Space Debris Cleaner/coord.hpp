#ifndef COORD_HPP
#define COORD_HPP

namespace sdc {
	/**
	* @class 坐标类
	*/
	class coord {
	public:
		/**
		* @brief	默认构造函数
		* @input	void
		* @note		explicit;
		*/
		explicit coord() = default;

		/**
		* @brief	构造函数
		* @input	const float x
		*			const float y
		* @note		explicit;
		*/
		explicit coord(const float x, const float y) :x(x), y(y) {}
		
		/**
		* @brief	获取向量长
		* @input	void
		* @return	float 向量与原点的距离
		* @note		const;
		*/
        float len() const;

    public:
        /** @var 横坐标值 */
        float x;

        /** @var 纵坐标值 */
        float y;

	public:
        /**
        * @brief   赋值运算符重载
        * @input   const coord& 另一个 coord 对象
        * @return  当前对象的引用
        */
        coord& operator=(const coord& other) {
            if (this != &other) { 
                x = other.x;
                y = other.y;
            }
            return *this;
        }

        /**
        * @brief    相等运算符重载
        * @input    const coord& 另一个 coord 对象
        * @return   bool 两个对象是否相等
        */
        bool operator==(const coord& other) const {
            return x == other.x && y == other.y;
        }

        /**
        * @brief    不等运算符重载
        * @input    const coord& 另一个 coord 对象
        * @return   bool 两个对象是否不等
        */
        bool operator!=(const coord& other) const {
            return !(*this == other);
        }

        /**
        * @brief    矢量加法
        * @input    const coord& rhs
        * @return   coord 加法结果
        * @note     const;
        */
        coord operator+(const coord& rhs) const {
            return coord(x + rhs.x, y + rhs.y);
        }

        /**
        * @brief    矢量减法
        * @input    const coord& rhs
        * @return   coord 减法结果
        * @note     const;
        */
        coord operator-(const coord& rhs) const {
            return coord(x - rhs.x, y - rhs.y);
        }

        /**
        * @brief    矢量乘法（逐元素）
        * @input    const coord& rhs
        * @return   coord 乘法结果
        * @note     const;
        */
        coord operator*(const coord& rhs) const {
            return coord(x * rhs.x, y * rhs.y);
        }

        /**
        * @brief    矢量对标量加法
        * @input    float scalar
        * @return   coord 加法结果
        * @note     const;
        */
        coord operator+(float scalar) const {
            return coord(x + scalar, y + scalar);
        }

        /**
        * @brief    矢量对标量减法
        * @input    float scalar
        * @return   coord 减法结果
        * @note     const;
        */
        coord operator-(float scalar) const {
            return coord(x - scalar, y - scalar);
        }

        /**
        * @brief    矢量对标量乘法
        * @input    float scalar
        * @return   coord 乘法结果
        * @note     const;
        */
        coord operator*(float scalar) const {
            return coord(x * scalar, y * scalar);
        }

        /**
        * @brief    矢量对标量复合赋值加法
        * @input    float scalar
        * @return   coord& 自身
        * @note     const;
        */
        coord& operator+=(float scalar) {
            x += scalar;
            y += scalar;
            return *this;
        }

        /**
        * @brief    矢量对标量复合赋值减法
        * @input    float scalar
        * @return   coord& 自身
        * @note     const;
        */
        coord& operator-=(float scalar) {
            x -= scalar;
            y -= scalar;
            return *this;
        }

        /**
        * @brief    矢量对标量复合赋值乘法
        * @input    float scalar
        * @return   coord& 自身
        * @note     const;
        */
        coord& operator*=(float scalar) {
            x *= scalar;
            y *= scalar;
            return *this;
        }

        /**
        * @brief    矢量对矢量复合赋值加法
        * @input    const coord& rhs
        * @return   coord& 自身
        */
        coord& operator+=(const coord& rhs) {
            x += rhs.x;
            y += rhs.y;
            return *this;
        }

        /**
        * @brief    矢量对矢量复合赋值减法
        * @input    const coord& rhs
        * @return   coord& 自身
        */
        coord& operator-=(const coord& rhs) {
            x -= rhs.x;
            y -= rhs.y;
            return *this;
        }

        /**
        * @brief    矢量对矢量复合赋值乘法（逐元素）
        * @input    const coord& rhs
        * @return   coord& 自身
        */
        coord& operator*=(const coord& rhs) {
            x *= rhs.x;
            y *= rhs.y;
            return *this;
        }
	};
}

#endif // !COORD_HPP
