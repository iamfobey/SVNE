#pragma once

#include "stdafx.h"
#include "../Game/Game.h"

struct Settings
{
	int WIDTH;
	int HEIGHT;
	std::string TITLE;
};

class Engine
{
public:
	Engine();
	~Engine();

	bool Run();
private:
	sf::RenderWindow window;
	sf::VideoMode VMWindow;

	std::fstream FileSettings;

	Settings SETTINGS;

	sf::Event event;
};