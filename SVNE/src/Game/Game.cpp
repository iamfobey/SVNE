#include "Game.h"

Game::Game(std::vector<Params> pVector)
{
	font.loadFromFile(GamePath + "assets\\fonts\\" + "Impact.ttf");

	CharacterName.setFont(font);
	CharacterName.setFillColor(sf::Color::Red);
	CharacterName.setPosition(sf::Vector2f(30,700));
	CharacterName.setCharacterSize(49);

	CharacterText.setFont(font);
	CharacterText.setFillColor(sf::Color::Red);
	CharacterText.setPosition(sf::Vector2f(25, 760));
	CharacterText.setCharacterSize(44);

	param = pVector;

	TextBox.setFillColor(sf::Color(0, 0, 0, 165));
	TextBox.setSize(sf::Vector2f(1900, 380));
	TextBox.setPosition(sf::Vector2f(10, 690));

	line = 0;
	NextLine();
}

Game::~Game()
{

}

void Game::Input()
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		if (param.size() == line)
		{
			WindowClose = true;
			return;
		}
		NextLine();
	}
}

void Game::NextLine()
{
	if (param[line].type == ScriptDefs::TEXT)
	{
		CharacterName.setString(" ");
		CharacterText.setString(param[line].content);
		line++;
		return;
	}
	else if (param[line].type == ScriptDefs::CHARSAY)
	{
		CharacterName.setString(param[line].CharName);
		CharacterText.setString(param[line].CharText);
		line++;
		return;
	}
	else if (param[line].type == ScriptDefs::CHARDEF)
	{
		line++;
		NextLine();
	}
	else if (param[line].type == ScriptDefs::BG)
	{
		textureBG.loadFromFile(GamePath + "assets\\images\\bg\\" + param[line].content);
		spriteBG.setTexture(textureBG);
		line++;
		NextLine();
	}
	else
	{
		line++;
	}
}

void Game::update(sf::RenderWindow& window)
{
	if (WindowClose)
	{
		window.close();
	}

	window.clear();
	window.draw(spriteBG);
	window.draw(TextBox);
	window.draw(CharacterName);
	window.draw(CharacterText);
	window.display();
}