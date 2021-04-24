#include "Settings.h"

Settings::Settings()
{
	SETTINGS.TEXTURE_TEXTBOX.setSmooth(true);
}

Settings::~Settings()
{

}

void Settings::Parse()
{
	std::fstream SettingsFile;
	CheckIsTransition(SettingsFile, "settings.svne");

	SettingsFile.open("game\\settings.svne");
	
	std::string type;
	std::string text;

	while (SettingsFile.good())
	{
		std::getline(SettingsFile, text);
		type = text;
		
		if (type.find(" = ") != std::string::npos)
		{
			type.erase(type.find(" = "));
			text.erase(0, type.length() + 3);
		}

		if (type == "window.setTitle")
		{
			SETTINGS.WINDOW_TITLE = text;
			goto EndIf;
		}
		else if (type == "window.setWidth")
		{
			SETTINGS.WINDOW_WIDTH = atoi(text.c_str());
			goto EndIf;
		}
		else if (type == "window.setHeight")
		{
			SETTINGS.WINDOW_HEIGHT = atoi(text.c_str());
			goto EndIf;
		}
		else if (type == "textbox.setImage")
		{
			SETTINGS.TEXTURE_TEXTBOX.loadFromFile("game\\assets\\images\\gui\\textbox\\" + text);
			SETTINGS.SPRITE_TEXTBOX.setTexture(SETTINGS.TEXTURE_TEXTBOX);
			goto EndIf;
		}
		else if (type == "textbox.setPosition")
		{
			std::string temp = text;
			text.erase(text.find(", "));
			temp.erase(0, text.length() + 2);
			SETTINGS.SPRITE_TEXTBOX.setPosition(sf::Vector2f(atoi(text.c_str()), atoi(temp.c_str())));
			goto EndIf;
		}
		else if (type == "textbox.setScale")
		{
			std::string temp = text;
			text.erase(text.find(", "));
			temp.erase(0, text.length() + 2);
			SETTINGS.SPRITE_TEXTBOX.setScale(sf::Vector2f(std::stof(text.c_str()), std::stof(temp.c_str())));
			goto EndIf;
		}
	EndIf: {}
	}
}

int Settings::GetWidth()
{
	return SETTINGS.WINDOW_WIDTH;
}

int Settings::GetHeight()
{
	return SETTINGS.WINDOW_HEIGHT;
}

std::string Settings::GetTitle()
{
	return SETTINGS.WINDOW_TITLE;
}

sf::Sprite Settings::GetTextBox()
{
	return SETTINGS.SPRITE_TEXTBOX;
}
