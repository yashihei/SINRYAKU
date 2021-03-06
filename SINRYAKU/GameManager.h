#pragma once
#include <memory>

class Stage;
class StatusBar;
class Fps;

class GameManager
{
	enum class State {
		TITLE,
		IN_GAME,
		GAMEOVER,
		PAUSE,
	};

	State state;
	std::shared_ptr<Stage> stage;
	std::shared_ptr<Fps> fps;

public:
	GameManager(void);
	void Move(void);
	void Draw(void);
};
