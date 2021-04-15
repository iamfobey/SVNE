#include "Engine.h"
#include <string>

void CheckSettingFile(std::fstream& file, Settings& SETTINGS)
{
	std::string Param;
	std::string TextParam;
	while (std::getline(file, Param))
	{
		if (!file.eof())
		{
			TextParam = Param;
			Param.erase(Param.find("=") - 1);
			TextParam.erase(0, Param.length() + 3);

			if (Param == "Title")
			{
				SETTINGS.TITLE = TextParam;
			}
			else if (Param == "Width")
			{
				SETTINGS.WIDTH = atoi(TextParam.c_str());
			}
			else if (Param == "Height")
			{
				SETTINGS.HEIGHT = atoi(TextParam.c_str());
			}
		}
	}
}

Engine::Engine()
{
	CheckIsTransition(FileSettings, "game\\settings.svne");

	FileSettings.open("game\\settings.svne", std::ios::in);
}

Engine::~Engine()
{
	
}
bool Engine::Run()
{
	sf::ContextSettings settings;
	settings.antialiasingLevel = 4;

	CheckSettingFile(FileSettings, SETTINGS);
	FileSettings.close();

	VMWindow.width = SETTINGS.WIDTH;
	VMWindow.height = SETTINGS.HEIGHT;

	window.create(VMWindow, SETTINGS.TITLE, sf::Style::Default, settings);
	window.setVerticalSyncEnabled(true);

	Script script;
	script.ParseCharacters();
	std::vector<Params> paramsScript = script.Parse();
	
	Game game(paramsScript);

	sf::View view;
	view.setCenter(sf::Vector2f(1920/2, 1080/2));
	view.setSize(sf::Vector2f(1920, 1080));
	window.setView(view);

	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
			window.setView(view);
			game.Input();
		}
		game.update(window);
	}

	return 0;
}