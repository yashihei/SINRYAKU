#pragma once
#include <vector>

class Stage
{
	//�e�I�u�W�F�N�g��(�v���C���[�Ƃ����낢��)
	enum class Color {
		RED,
		BLUE,
		GREEN,
		NONE,
	};

	int height, width, size, cnt;
	//std::array<std::array<Color, width>, height> map;
	std::vector<std::vector<Color>> map;

public:
	Stage(void);
	void Move(void);
	void Draw(void);
private:
	bool isOut(int x, int y);
	void replace(int x, int y);
};

