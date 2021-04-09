#include "Engine.h"

void Engine::WindowDraw(sf::RenderWindow& window, sf::Sprite& sprite)
{
	window.clear();
	window.draw(sprite);
	window.display();
}

void Engine::WindowDraw(sf::RenderWindow& window, sf::Text& text)
{
	window.clear();
	window.draw(text);
	window.display();
}

bool Engine::IsHover(sf::FloatRect sprite, sf::Vector2f mp)
{
	if (sprite.contains(mp))
		return true;
	return false;
}

Engine::Engine()
{
	VM.width = 1280;
	VM.height = 720;

	EngineWindow.setVerticalSyncEnabled(true);

	settings.antialiasingLevel = 4;

	font.loadFromFile("Assets\\Impact.ttf");
	text.setFont(font);

	mp.x = sf::Mouse::getPosition(EngineWindow).x;
	mp.y = sf::Mouse::getPosition(EngineWindow).y;
}

Engine::~Engine()
{
	
}

bool Engine::GameRun()
{
	GameWindow.create(VM, "SVNE");
	
	while (GameWindow.isOpen())
	{
		while (GameWindow.pollEvent(event))
			if (event.type == sf::Event::Closed)
				GameWindow.close();
	}

	return 0;	
}

bool Engine::EngineRun()
{
	EngineWindow.create(sf::VideoMode(800, 600), "SVNE", sf::Style::Default, settings);
	
	text.setPosition(300, 200);
	text.setCharacterSize(35);
	text.setFillColor(sf::Color::White);
	text.setString("Create Project");

	WindowDraw(EngineWindow, text);

	bool CreateProject = 0;
	EnteredChars = "MyProject";

    while (EngineWindow.isOpen())
    {
        while (EngineWindow.pollEvent(event))
        {
			const sf::Keyboard::Key keycode = event.key.code;

            if (event.type == sf::Event::Closed)
				EngineWindow.close();
			if (CreateProject)
			{
				text.setPosition(300, 200);
				text.setCharacterSize(30);
				text.setFillColor(sf::Color::White);
				text.setString(EnteredChars);
				
				WindowDraw(EngineWindow, text);

				if (event.type == sf::Event::KeyPressed)
				{
					if (keycode >= sf::Keyboard::A && keycode <= sf::Keyboard::Z)
					{
						char chr = static_cast<char>(keycode - sf::Keyboard::A + 'a');
						EnteredChars.push_back(chr);
						text.setString((std::string)EnteredChars);

						ProjectName = EnteredChars;

						WindowDraw(EngineWindow, text);
					}
					else if (keycode == sf::Keyboard::Backspace)
					{
						if (EnteredChars.size() == 0)
						{
							break;
						}
						else
						{
							EnteredChars.pop_back();
							text.setString((std::string)EnteredChars);

							ProjectName = EnteredChars;

							WindowDraw(EngineWindow, text);
						}
					}
					else if (keycode == sf::Keyboard::Enter)
					{
						text.setString("SVNE Creating your project...");

						WindowDraw(EngineWindow, text);

						std::filesystem::create_directory((std::filesystem::path)EnteredChars);

						return 0;
					}
				}
			}
			else if (IsHover(text.getGlobalBounds(), sf::Vector2f(event.mouseButton.x, event.mouseButton.y)) == true)
			{
				if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
				{
					EngineWindow.clear();
					EngineWindow.display();
					CreateProject = true;
				}
			}			
        }
    }
	return 0;
}