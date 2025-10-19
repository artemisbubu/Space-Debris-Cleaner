#ifndef DEFINITIONS_HPP
#define DEFINITIONS_HPP
#include <vector>

namespace sdc {

	const int	GM_WIN_INIT_WIDTH = 1280;		// ��ʼ����Ϸ���ڿ�
	const int	GM_WIN_INIT_HEIGHT = 853;		// ��ʼ����Ϸ���ڸ�
	const int	GM_FPS = 60;					// ��Ϸ֡��

	/**
	* @enumclass ö��ʵ������
	*/
	enum class entity_type {
		TRASH_A,
		SIZE
	};

	/**
	* @enumclass ��������
	*/
	enum class scene_type {
		SCENE_A,
		SIZE
	};
}


#endif // !DEFINITIONS_HPP
