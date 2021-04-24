#pragma once

#include "Engine/Engine.h"
#include "Parsers/Script/Script.h"
#include "Parsers/Settings/Settings.h"
#include "Transitions.h"

class Game
{
public:
	Game(Script& script, Settings& settings);
	~Game();

	void input();
	void update(sf::RenderWindow& window);
private:
	void NextLine();

	sf::Font font;
	sf::Text CharacterName;
	sf::Text CharacterText;
	sf::Text text;

	std::vector<ScriptStruct> param;
	std::vector<sf::Sprite> SpriteList;

	int line;

	bool WindowClose;
	bool IsDissolve;

	bool DrawSprite;

	Settings* SETTINGS;

	sf::Music music;

	sf::Texture TextureBG;
	sf::Sprite SpriteBG;

	sf::Texture TextureSPR;
	sf::Sprite SpriteSPR;
};