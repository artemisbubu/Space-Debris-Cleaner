#ifndef COORD_HPP
#define COORD_HPP

namespace sdc {
	/**
	* @class ������
	*/
	class coord {
	public:
		/**
		* @brief	Ĭ�Ϲ��캯��
		* @input	void
		* @note		explicit;
		*/
		explicit coord() = default;

		/**
		* @brief	���캯��
		* @input	const float x
		*			const float y
		* @note		explicit;
		*/
		explicit coord(const float x, const float y) :x(x), y(y) {}
		
		/**
		* @brief	��ȡ������
		* @input	void
		* @return	float ������ԭ��ľ���
		* @note		const;
		*/
        float len() const;

    public:
        /** @var ������ֵ */
        float x;

        /** @var ������ֵ */
        float y;

	public:
        /**
        * @brief   ��ֵ���������
        * @input   const coord& ��һ�� coord ����
        * @return  ��ǰ���������
        */
        coord& operator=(const coord& other) {
            if (this != &other) { 
                x = other.x;
                y = other.y;
            }
            return *this;
        }

        /**
        * @brief    ������������
        * @input    const coord& ��һ�� coord ����
        * @return   bool ���������Ƿ����
        */
        bool operator==(const coord& other) const {
            return x == other.x && y == other.y;
        }

        /**
        * @brief    �������������
        * @input    const coord& ��һ�� coord ����
        * @return   bool ���������Ƿ񲻵�
        */
        bool operator!=(const coord& other) const {
            return !(*this == other);
        }

        /**
        * @brief    ʸ���ӷ�
        * @input    const coord& rhs
        * @return   coord �ӷ����
        * @note     const;
        */
        coord operator+(const coord& rhs) const {
            return coord(x + rhs.x, y + rhs.y);
        }

        /**
        * @brief    ʸ������
        * @input    const coord& rhs
        * @return   coord �������
        * @note     const;
        */
        coord operator-(const coord& rhs) const {
            return coord(x - rhs.x, y - rhs.y);
        }

        /**
        * @brief    ʸ���˷�����Ԫ�أ�
        * @input    const coord& rhs
        * @return   coord �˷����
        * @note     const;
        */
        coord operator*(const coord& rhs) const {
            return coord(x * rhs.x, y * rhs.y);
        }

        /**
        * @brief    ʸ���Ա����ӷ�
        * @input    float scalar
        * @return   coord �ӷ����
        * @note     const;
        */
        coord operator+(float scalar) const {
            return coord(x + scalar, y + scalar);
        }

        /**
        * @brief    ʸ���Ա�������
        * @input    float scalar
        * @return   coord �������
        * @note     const;
        */
        coord operator-(float scalar) const {
            return coord(x - scalar, y - scalar);
        }

        /**
        * @brief    ʸ���Ա����˷�
        * @input    float scalar
        * @return   coord �˷����
        * @note     const;
        */
        coord operator*(float scalar) const {
            return coord(x * scalar, y * scalar);
        }

        /**
        * @brief    ʸ���Ա������ϸ�ֵ�ӷ�
        * @input    float scalar
        * @return   coord& ����
        * @note     const;
        */
        coord& operator+=(float scalar) {
            x += scalar;
            y += scalar;
            return *this;
        }

        /**
        * @brief    ʸ���Ա������ϸ�ֵ����
        * @input    float scalar
        * @return   coord& ����
        * @note     const;
        */
        coord& operator-=(float scalar) {
            x -= scalar;
            y -= scalar;
            return *this;
        }

        /**
        * @brief    ʸ���Ա������ϸ�ֵ�˷�
        * @input    float scalar
        * @return   coord& ����
        * @note     const;
        */
        coord& operator*=(float scalar) {
            x *= scalar;
            y *= scalar;
            return *this;
        }

        /**
        * @brief    ʸ����ʸ�����ϸ�ֵ�ӷ�
        * @input    const coord& rhs
        * @return   coord& ����
        */
        coord& operator+=(const coord& rhs) {
            x += rhs.x;
            y += rhs.y;
            return *this;
        }

        /**
        * @brief    ʸ����ʸ�����ϸ�ֵ����
        * @input    const coord& rhs
        * @return   coord& ����
        */
        coord& operator-=(const coord& rhs) {
            x -= rhs.x;
            y -= rhs.y;
            return *this;
        }

        /**
        * @brief    ʸ����ʸ�����ϸ�ֵ�˷�����Ԫ�أ�
        * @input    const coord& rhs
        * @return   coord& ����
        */
        coord& operator*=(const coord& rhs) {
            x *= rhs.x;
            y *= rhs.y;
            return *this;
        }
	};
}

#endif // !COORD_HPP
