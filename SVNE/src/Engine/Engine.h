#pragma once

#include "../Core/stdafx.h"

class Engine
{
public:
	Engine();
	virtual ~Engine();
	bool EngineRun();
private:
	bool GameRun();
	bool IsHover(sf::FloatRect sprite, sf::Vector2f mp);
	void WindowDraw(sf::RenderWindow& window, sf::Sprite& sprite);
	void WindowDraw(sf::RenderWindow& window, sf::Text& text);

	sf::RenderWindow EngineWindow;
	sf::RenderWindow GameWindow;

	sf::VideoMode VM;
	sf::Vector2f mp;

	sf::Texture texture;
	sf::Sprite sprite;
	
	sf::Font font;
	sf::Text text;
	
	sf::Event event;
	sf::ContextSettings settings;

	std::string EnteredChars;
	std::filesystem::path ProjectName;
};