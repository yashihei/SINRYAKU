#pragma once
#include <vector>
#include <map>

class GameManager
{
	enum class State {
		TITLE,
		IN_GAME,
		GAMEOVER,
		PAUSE,
	};

	State state;

	//各オブジェクトを(プレイヤーとかいろいろ)
	enum class Color {
		RED,
		BLUE,
		YELLOW,
		GREEN,
		NONE,
	};

	int height, width, size;
	const int HEIGHT = 100, WIDTH = 100;
	//std::array<std::array<Color, width>, height> map;
	std::vector<std::vector<Color>> map;

public:
	GameManager(void);
	void Move(void);
	void Draw(void);
};
