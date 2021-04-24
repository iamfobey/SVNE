#pragma once

#include "Core/stdafx.h"
#include "Core/Tools.h"

enum ScriptEnum
{
	SHOW_SPRITE,
	HIDE_SPRITE,
	MUSIC_PLAY,
	MUSIC_STOP,
	CHARSAY,
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

	std::vector<std::string> SpriteList;
	std::vector<std::string> SpriteDefs;

	std::fstream ScriptFile;
};