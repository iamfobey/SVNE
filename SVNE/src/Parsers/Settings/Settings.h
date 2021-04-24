#pragma once

#include "Core/stdafx.h"
#include "Core/Tools.h"

struct SettingStruct
{
	int WINDOW_WIDTH;
	int WINDOW_HEIGHT;
	std::string WINDOW_TITLE;

	sf::Texture TEXTURE_TEXTBOX;
	sf::Sprite SPRITE_TEXTBOX;
};

class Settings
{
public:
	Settings();
	~Settings();

	void Parse();

	int GetWidth();
	int GetHeight();
	std::string GetTitle();

	sf::Sprite GetTextBox();
private:
	SettingStruct SETTINGS;
};