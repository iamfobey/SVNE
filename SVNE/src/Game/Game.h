#pragma once

#include "../Core/Engine.h"
#include "../Script/Script.h"

class Game
{
public:
	Game(std::vector<Params> pVector);
	~Game();
	void Input();
	void update(sf::RenderWindow& window);
private:
	void NextLine();

	sf::Font font;
	sf::Text CharacterName;
	sf::Text CharacterText;
	sf::Text text;

	std::vector<Params> param;
	bool WindowClose;
	int line;

	std::string GamePath = "game\\";

	sf::RectangleShape TextBox;

	sf::Texture textureBG;
	sf::Sprite spriteBG;
};