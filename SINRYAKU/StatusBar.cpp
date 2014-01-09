#include <DxLib.h>
#include "StatusBar.h"
#include "Stage.h"

StatusBar::StatusBar(std::shared_ptr<Stage> stage) {
	this->stage = stage;
}

void StatusBar::Draw(void) {
}
