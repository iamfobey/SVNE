#pragma once

#include "../Core/Engine.h"
#include "../Parsers/Script/Script.h"
#include "../Tools/TextBox.h"
#include "../Tools/Transitions.h"

class Game
{
public:
	Game(std::vector<ScriptStruct> pVector);
	~Game();
	void Input();
	void update(sf::RenderWindow& window);
private:
	void NextLine();

	sf::Font font;
	sf::Text CharacterName;
	sf::Text CharacterText;
	sf::Text text;

	std::vector<ScriptStruct> param;
	bool WindowClose;
	int line;

	TextBox TextBox;

	bool IsDissolve;

	sf::Texture textureBG;
	sf::Sprite spriteBG;
};