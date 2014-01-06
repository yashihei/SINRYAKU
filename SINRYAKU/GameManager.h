#pragma once

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

public:
	GameManager(void);
	void Move(void);
	void Draw(void);
};
