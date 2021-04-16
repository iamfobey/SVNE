#include "Engine.h"
#include <string>

Engine::Engine()
{
	view.setCenter(sf::Vector2f(1920 / 2, 1080 / 2));
	view.setSize(sf::Vector2f(1920, 1080));
}

Engine::~Engine()
{
	
}
bool Engine::Run()
{
	settings.Parse();
	VMWindow.width = settings.GetWidth();
	VMWindow.height = settings.GetHeight();

	window.create(VMWindow, settings.GetTitle());
	window.setVerticalSyncEnabled(true);

	script.ParseCharacters();
	ScriptVector = script.Parse();
	
	Game game(ScriptVector);

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