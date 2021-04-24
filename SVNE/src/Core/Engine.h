#pragma once

#include "stdafx.h"
#include "../Game/Game.h"
#include "../Parsers/Script/Script.h"
#include "../Parsers/Settings/Settings.h"

class Engine
{
public:
	Engine();
	~Engine();

	bool Run();
private:
	sf::RenderWindow window;
	sf::VideoMode VMWindow;

	Script script;
	std::vector<ScriptStruct> ScriptVector;

	Settings settings;

	sf::View view;
	sf::Event event;
};