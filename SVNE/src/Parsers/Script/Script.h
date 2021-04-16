#pragma once

#include "Core/stdafx.h"

enum ScriptEnum
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

struct ScriptStruct
{
	ScriptEnum type;
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
	std::vector<ScriptStruct> Parse();
private:
	std::vector<std::string> CharNames;
	std::vector<std::string> CharDefs;

	std::fstream ScriptFile;
};