#include "Settings.h"

Settings::Settings()
{

}

Settings::~Settings()
{

}

void Settings::Parse()
{
	std::fstream SettingsFile("game\\settings.svne");
	
	std::string type;
	std::string text;

	while (std::getline(SettingsFile, type))
	{
		if (!SettingsFile.eof())
		{
			text = type;
			type.erase(type.find(" = "));
			text.erase(0, type.length() + 3);

			if (type == "Title")
			{
				SETTINGS.TITLE = text;
				goto EndIf;
			}
			else if (type == "Width")
			{
				SETTINGS.WIDTH = atoi(text.c_str());
				goto EndIf;
			}
			else if (type == "Height")
			{
				SETTINGS.HEIGHT = atoi(text.c_str());
				goto EndIf;
			}
		}
	EndIf: {}
	}
}

int Settings::GetWidth()
{
	return SETTINGS.WIDTH;
}

int Settings::GetHeight()
{
	return SETTINGS.HEIGHT;
}

std::string Settings::GetTitle()
{
	return SETTINGS.TITLE;
}