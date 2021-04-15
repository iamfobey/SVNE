#pragma once

#include "../Core/stdafx.h"

enum ScriptDefs
{
	AMBIENCE,
	NAMEBOX,
	CHARSAY,
	CHARDEF,
	SAYBOX,
	MUSIC,
	MENU,
	TEXT,
	BG,
	CG
};

struct Params
{
	ScriptDefs type;
	std::string content;
	std::string CharText;
	std::string CharName;
};

class Script
{
public:
	Script();
	~Script();
	void ParseCharacters();
	std::vector<Params> Parse();
private:
	std::vector<std::string> CharNames;
	std::vector<std::string> CharDefs;

	std::string ScriptsPath = "game\\";

	std::fstream ScriptFile;
};