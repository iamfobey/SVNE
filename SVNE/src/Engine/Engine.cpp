#include "Engine.h"

Engine::Engine()
{
	view.setCenter(sf::Vector2f(1920 / 2, 1080 / 2));
	view.setSize(sf::Vector2f(1920, 1080));
	settings.Parse();
}

Engine::~Engine()
{
	
}
bool Engine::Run()
{
	Game game(script, settings);

	VMWindow.width = settings.GetWidth();
	VMWindow.height = settings.GetHeight();

	window.create(VMWindow, settings.GetTitle() + " (Powered by SVNE)");
	window.setVerticalSyncEnabled(true);

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
			game.input();
		}
		game.update(window);
	}

	return 0;
}