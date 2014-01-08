#pragma once
#include <memory>

class Stage;

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

public:
	GameManager(void);
	void Move(void);
	void Draw(void);
};
