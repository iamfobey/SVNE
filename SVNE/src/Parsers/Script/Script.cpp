#include "Script.h"

Script::Script()
{
	CheckIsTransition(ScriptFile, "script.svne");
	ScriptFile.open("game\\script.svne", std::ios::in);
}

Script::~Script()
{
	ScriptFile.close();
}

std::vector<ScriptStruct> Script::Parse()
{
	std::vector<ScriptStruct> ScriptVector;
	ScriptStruct ScriptList;

	std::string type;
	std::string text;

	while (ScriptFile.good())
	{
		std::getline(ScriptFile, type);
		text = type;

		if (type.find(" ") != std::string::npos)
		{
			type.erase(type.find(" "));
			text.erase(0, type.length() + 1);
		}
		else
		{
			goto end2;
		}

		if (type == "bg")
		{
			ScriptList.content = text;
			ScriptList.type = ScriptEnum::BG;
			goto end;
		}
		else if (type == "txt")
		{
			ScriptList.content = text;
			ScriptList.type = ScriptEnum::TEXT;
			goto end;
		}
		else if (type == "character")
		{
			std::string temp = text;
			temp.erase(temp.find(" = "));
			text.erase(0, temp.length() + 3);

			CharDefs.push_back(temp);
			CharNames.push_back(text);
			goto end;
		}
		else if (type == "music.play")
		{
			ScriptList.content = text;
			ScriptList.type = ScriptEnum::MUSIC_PLAY;
			goto end;
		}
		else if (type == "music.stop")
		{
			ScriptList.type = ScriptEnum::MUSIC_STOP;
			goto end;
		}
		else if (type == "sprite")
		{
			if (text == "hide")
			{
				ScriptList.type = ScriptEnum::HIDE_SPRITE;
				goto end;
			}

			ScriptList.content = text;
			ScriptList.type = ScriptEnum::SHOW_SPRITE;
			goto end;
		}

		for (int i = 0; i < CharNames.size(); i++)
		{
			if (type == CharDefs[i])
			{
				ScriptList.CharName = CharNames[i];
				ScriptList.CharText = text;
				ScriptList.type = ScriptEnum::CHARSAY;
				break;
			}
		}

	end: {}

		ScriptVector.push_back(ScriptList);

	end2: {}
	}
	return ScriptVector;
}