#include <DxLib.h>
#include "GameManager.h"
#include "Stage.h"

GameManager::GameManager(void) {
	state = State::IN_GAME;//�Ƃ肠������
	stage = std::make_shared<Stage>();
}

void GameManager::Move(void) {
	stage->Move();
}

void GameManager::Draw(void) {
	stage->Draw();
}
