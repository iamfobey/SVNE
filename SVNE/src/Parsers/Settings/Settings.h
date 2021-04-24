#pragma once

#include "Core/stdafx.h"

struct SettingStruct
{
	int WIDTH;
	int HEIGHT;
	std::string TITLE;
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
private:
	SettingStruct SETTINGS;
};