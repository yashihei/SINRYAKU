#include <DxLib.h>
#include "GameManager.h"

GameManager::GameManager(void) {
	state = State::IN_GAME;//とりあえずは
	height = 100;
	width = 100;
	size = 1;
	map.resize(height);
	for (int i = 0; i < width; i++) map[i].resize(width);
	for (int i = 0; i < map.size(); i++) for (int j = 0; map[i].size(); j++) map[i][j] = Color::RED;
	//初期配置
}

void GameManager::Move(void) {
}

void GameManager::Draw(void) {

	//やっぱりクラス化したほうがいい気が
	for (int i = 0; i < map.size(); i++) {
		for (int j = 0; map[i].size(); j++) {
			int rgb;
			switch (map[i][j])
			{
			case Color::RED:
				rgb = GetColor(255, 0, 0);
				break;
			case Color::BLUE:
				rgb = GetColor(0, 255, 0);
				break;
			case Color::YELLOW:
				rgb = GetColor(255, 0, 0);
				break;
			case Color::GREEN:
				rgb = GetColor(255, 0, 0);
				break;
			case Color::NONE:
				rgb = GetColor(255, 0, 0);
				break;
			default:
				printf("bakana");
				break;
			}
			DrawFillBox(0,0, 100, 100, rgb);
			printf("いきてる");
		}
	}
}
