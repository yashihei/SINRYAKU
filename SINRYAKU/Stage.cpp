#include <DxLib.h>
#include "Stage.h"
#include "ConstParam.h"

Stage::Stage(void) {
	size = 5;
	height = ConstParam::SCREEN_HEIGHT / size;
	width = ConstParam::SCREEN_WIDTH / size;
	cnt = 0;
	map.resize(height);
	for (int i = 0; i < width; i++) map[i].resize(width);
	for (int i = 0; i < map.size(); i++) for (int j = 0; j < map[i].size(); j++) map[i][j] = Color::RED;
	for (int i = 0; i < map.size() / 2; i++) for (int j = 0; j < map[i].size(); j++) map[i][j] = Color::BLUE;
}

void Stage::Move(void) {
	cnt++;
	for (int y = 0; y < map.size(); y++) {
		for (int x = 0; x < map[y].size(); x++) {
			replace(x, y);
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
			case Color::WALL:
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
	int r = GetRand(4);
	int cnt = 0;
	//VC2012の標準ライブラリが初期化リストに非対応だったのでこんなことに
	//std::vector<Point> dir = { {-1, 0}, {1, 0}, {0, 1}, {0, -1} };
	const int DIR[][2] = { {-1, 0}, {1, 0}, {0, 1}, {0, -1} };
	for (auto& p: DIR) {
		if (!isOut(x + p[0], y + p[1]) && cnt == r) {
			map[x][y] = map[x + p[0]][y + p[1]];
		}
		if (cnt == r) return;
		cnt++;
	}

	//ボツ
	//for (int dy = -1; dy < 2; dy++) {
	//	for (int dx = -1; dx < 2; dx++) {
	//		if (!isOut(x + dx, y + dy) && cnt == r) {
	//			//std::swap(map[x + dx][y + dy], map[x][y]);
	//			//map[x + dx][y + dy] = map[x][y];
	//			map[x][y] = map[x + dx][y + dy];
	//		}
	//		if (cnt == r) return;
	//		cnt++;
	//	}
	//}

	//vectorコストおもひ
	//std::vector<Point> vec;
	//for (auto& p: DIR) {
	//	if (!isOut(x + p[0], y + p[1])) vec.push_back(Point(x + p[0], y + p[1]));
	//}
	//Point p = vec[GetRand(vec.size() - 1)];
	//map[x][y] = map[p.x][p.y];
}
