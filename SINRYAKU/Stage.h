#pragma once
#include <vector>
#include <initializer_list>

class Stage
{
	//各オブジェクトを(プレイヤーとかいろいろ)
	enum class Color {
		RED,
		BLUE,
		GREEN,
		WALL,
	};

	struct Point {
		int x, y;
		Point(int x, int y) {this->x = x, this->y = y;};
	};

	int height, width, size, cnt;
	//std::array<std::array<Color, width>, height> map;
	std::vector<std::vector<Color>> map;
	std::vector<std::vector<Color>> tMap;

public:
	Stage(void);
	void Move(void);
	void Draw(void);
private:
	bool isOut(int x, int y);
	void replace(int x, int y);
};

