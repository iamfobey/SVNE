#include "Game.h"


Game::Game(Script& script, Settings& settings)
{	
	SETTINGS = &settings;

	SETTINGS->Parse();

	font.loadFromFile("game\\assets\\fonts\\Font.ttf");
	music.setVolume(10);

	SetTextSettings(CharacterName, font, sf::Color::Red, sf::Vector2f(130, 855), 32);
	SetTextSettings(CharacterText, font, sf::Color::Red, sf::Vector2f(130, 895), 33);
	
	param = script.Parse();

	TextureBG.setSmooth(true);
	TextureSPR.setSmooth(true);

	DrawSprite = false;
	IsDissolve = false;

	line = 0;
	NextLine();
}

Game::~Game()
{

}

void Game::input()
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
		return;
	}
	else if (param[line].type == ScriptEnum::CHARSAY)
	{
		CharacterName.setString(param[line].CharName);
		CharacterText.setString(param[line].CharText);

		line++;
		return;
	}
	else if (param[line].type == ScriptEnum::BG)
	{
		TextureBG.loadFromFile("game\\assets\\images\\bg\\" + param[line].content);
		SpriteBG.setTexture(TextureBG);

		IsDissolve = true;

		line++;
		NextLine();
	}
	else if (param[line].type == ScriptEnum::MUSIC_PLAY)
	{
		music.openFromFile("game\\assets\\sounds\\music\\" + param[line].content);

		music.play();

		line++;
		NextLine();
	}
	else if (param[line].type == ScriptEnum::MUSIC_STOP)
	{
		music.stop();

		line++;
		NextLine();
	}
	else if (param[line].type == ScriptEnum::SHOW_SPRITE)
	{
		TextureSPR.loadFromFile("game\\assets\\images\\sprites\\" + param[line].content);
		SpriteSPR.setTexture(TextureSPR);
		SpriteSPR.setPosition(sf::Vector2f(350,0));

		DrawSprite = true;

		line++;
		NextLine();
	}
	else if (param[line].type == ScriptEnum::HIDE_SPRITE)
	{
		DrawSprite = false;

		line++;
		NextLine();
	}
	else if (param[line].type == ScriptEnum::SKIP)
	{
		line++;
		NextLine();
	}
	else
	{
		line++;
		NextLine();
	}
}

void Game::update(sf::RenderWindow& window)
{
	if (WindowClose) window.close();

	if (IsDissolve)
	{
		dissolve(window, SpriteBG);
		IsDissolve = false;
	}

	window.clear();

	window.draw(SpriteBG);
	
	if (DrawSprite)
	{
		window.draw(SpriteSPR);
	}

	window.draw(SETTINGS->GetTextBox());
	window.draw(CharacterName);
	window.draw(CharacterText);

	window.display();
}