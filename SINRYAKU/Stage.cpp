#include <DxLib.h>
#include "Stage.h"

Stage::Stage(void) {
	height = 100;
	width = 100;
	size = 3;
	cnt = 0;
	map.resize(height);
	for (int i = 0; i < width; i++) map[i].resize(width);
	for (int i = 0; i < map.size(); i++) for (int j = 0; j < map[i].size(); j++) map[i][j] = Color::RED;
	for (int i = 0; i < map.size() / 2; i++) for (int j = 0; j < map[i].size(); j++) map[i][j] = Color::BLUE;
	//map[0][0] = Color::RED;
	//map[width-1][height-1] = Color::BLUE;
	//map[0][height-1] = Color::BLUE;
	//map[width/2][height/2] = Color::GREEN;
}

void Stage::Move(void) {
	cnt++;
	for (int y = 0; y < map.size(); y++) {
		for (int x = 0; x < map[y].size(); x++) {
			if (map[x][y] != Color::NONE) replace(x, y);
		}
	}
}

void Stage::Draw(void) {
	for (int y = 0; y < map.size(); y++) {
		for (int x = 0; x < map[y].size(); x++) {
			int rgb;
			switch (map[x][y])
			{
			case Color::RED:
				rgb = GetColor(255, 100, 0);
				break;
			case Color::BLUE:
				rgb = GetColor(0, 100, 255);
				break;
			case Color::GREEN:
				rgb = GetColor(0, 255, 0);
				break;
			case Color::NONE:
				rgb = GetColor(0, 0, 0);
				break;
			default:
				printf("bakana");
				break;
			}
			DrawFillBox(size * x, size * y, size * x + size, size * y + size, rgb);
		}
	}
}

bool Stage::isOut(int x, int y) {
	if (x < 0 || x >= width || y < 0 || y >= height) return true;
	return false;
}

void Stage::replace(int x, int y) {
	int r = GetRand(9);
	int cnt = 0;
	for (int dy = -1; dy < 2; dy++) {
		for (int dx = -1; dx < 2; dx++) {
			//if (dx == dy) continue;
			if (!isOut(x + dx, y + dy) && cnt == r) {
				//std::swap(map[x + dx][y + dy], map[x][y]);
				//map[x + dx][y + dy] = map[x][y];
				map[x][y] = map[x + dx][y + dy];
			}
			if (cnt == r) return;
			cnt++;
		}
	}
}
