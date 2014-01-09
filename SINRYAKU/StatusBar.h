#pragma once
#include <memory>

class Stage;

class StatusBar
{
	std::shared_ptr<Stage> stage;
public:
	StatusBar(std::shared_ptr<Stage>);
	void Draw(void);
};

