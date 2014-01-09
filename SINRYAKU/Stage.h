#pragma once
#include <vector>
#include <initializer_list>

class GameManager;

class Stage
{
	//各オブジェクトを(プレイヤーとかいろいろ)
	enum class Color {
		RED,
		BLUE,
		WALL,
	};

	struct Point {
		int x, y;
		Point(int x, int y) {this->x = x, this->y = y;};
	};

	GameManager* gameManager;

	int height, width, size, cnt;
	int redCount, blueCount;
	int sep;
	//std::array<std::array<Color, width>, height> map;
	std::vector<std::vector<Color>> map;

public:
	Stage(GameManager*);
	void Init(void);
	void Move(void);
	void Draw(void);
private:
	bool isOut(int x, int y);
	void replace(int x, int y);
	void countCell(void);
public:
	int GetRedCount(void) {return this->redCount;};
	int GetBlueCount(void) {return this->blueCount;};
};
