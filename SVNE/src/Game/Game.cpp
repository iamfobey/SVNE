#include "Game.h"

Game::Game(std::vector<ScriptStruct> pVector)
{
	font.loadFromFile("game\\assets\\fonts\\Impact.ttf");
	
	SetTextSettings(CharacterName, font, sf::Color::Red, sf::Vector2f(30, 700), 49);
	SetTextSettings(CharacterText, font, sf::Color::Red, sf::Vector2f(25, 760), 44);

	param = pVector;

	TextBox.SetColor(sf::Color(0, 0, 0, 165));
	TextBox.SetSize(sf::Vector2f(1900, 380));
	TextBox.SetPos(sf::Vector2f(10, 690));

	line = 0;
	NextLine();
	textPos = 0;
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
	if (param[line].type == ScriptEnum::TEXT)
	{
		CharacterName.setString(" ");
		CharacterText.setString(param[line].content);
		line++;
		textPos = 0;
		return;
	}
	else if (param[line].type == ScriptEnum::CHARSAY)
	{
		CharacterName.setString(param[line].CharName);
		CharacterText.setString(param[line].CharText);
		line++;
		textPos = 0;
		return;
	}
	else if (param[line].type == ScriptEnum::CHARDEF)
	{
		line++;
		NextLine();
	}
	else if (param[line].type == ScriptEnum::BG)
	{
		textureBG.loadFromFile("game\\assets\\images\\bg\\" + param[line].content);
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
	if (WindowClose) window.close();

	WrapperText(CharacterText, window);

	window.clear();

	window.draw(spriteBG);
	window.draw(TextBox.GetTextBox());
	window.draw(CharacterName);
	window.draw(CharacterText);

	window.display();
}