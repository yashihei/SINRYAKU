#include <DxLib.h>
#include "GameManager.h"
#include "Stage.h"
#include "StatusBar.h"
#include "global.h"

GameManager::GameManager(void) {
	state = State::IN_GAME;//‚Æ‚è‚ ‚¦‚¸‚Í
	stage = std::make_shared<Stage>(this);
}

void GameManager::Move(void) {
	switch (state) {
	case State::IN_GAME:
		stage->Move();
		if (GetKey(KEY_INPUT_SPACE) == 1) state = State::PAUSE;
		break;
	case State::PAUSE:
		if (GetKey(KEY_INPUT_SPACE) == 1) state = State::IN_GAME;
		break;
	}
}

void GameManager::Draw(void) {
	stage->Draw();
}
