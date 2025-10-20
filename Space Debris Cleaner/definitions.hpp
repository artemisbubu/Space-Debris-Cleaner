#ifndef DEFINITIONS_HPP
#define DEFINITIONS_HPP
#include <vector>

namespace sdc {
	const char* const CONFIG_PATH = "./config.json";	// �����ļ�����·��

	/**
	* @enumclass ö��ʵ������
	*/
	enum class entity_type {
		stone_1,
		stone_2,
		stone_3,
		size
	};

	/**
	* @enumclass ��������
	*/
	enum class scene_type {
		background,
		size
	};
}


#endif // !DEFINITIONS_HPP


//void DrawTexturePro(
//	Texture2D texture,     // Ҫ���Ƶ�����
//	Rectangle source,      // Դ���Σ��������ϵ�����
//	Rectangle dest,        // Ŀ����Σ�����Ļ�ϵ�λ�úʹ�С��
//	Vector2 origin,        // ��ת�����ŵ�ԭ�㣨�����Ŀ����Σ�
//	float rotation,        // ��ת�Ƕȣ���λ���㣩
//	Color tint             // ��ɫ���ӣ�WHITE = ԭɫ��
//);