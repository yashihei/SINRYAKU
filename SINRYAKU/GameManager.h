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

	//�e�I�u�W�F�N�g��(�v���C���[�Ƃ����낢��)

public:
	GameManager(void);
	void Move(void);
	void Draw(void);
};
