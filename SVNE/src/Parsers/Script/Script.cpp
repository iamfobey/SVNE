#include "Script.h"

Script::Script()
{
	CheckIsTransition(ScriptFile, "game\\script.svne");
	ScriptFile.open("game\\script.svne", std::ios::in);
}

Script::~Script()
{
	ScriptFile.close();
}

void Script::ParseCharacters()
{
	std::string type;
	std::string text;

	while (std::getline(ScriptFile, type))
	{
		if (!ScriptFile.eof())
		{
			text = type;
			type.erase(type.find(" "));
			text.erase(0, type.length() + 1);

			if (type == "Character")
			{
				std::string temp = text;
				text.erase(0, text.find("=") + 2);
				temp.erase(temp.find(" = "));

				CharDefs.push_back(temp);
				CharNames.push_back(text);
			}
		}
	}
	ScriptFile.close();
	ScriptFile.open("game\\script.svne", std::ios::in);
}

std::vector<ScriptStruct> Script::Parse()
{
	std::vector<ScriptStruct> ScriptVector;
	ScriptStruct ScriptList;

	std::string type;
	std::string text;

	while (std::getline(ScriptFile, type))
	{
		if (!ScriptFile.eof())
		{
			text = type;
			type.erase(type.find(" "));
			text.erase(0, type.length() + 1);

			if (type == "background")
			{
				ScriptList.content = text;
				ScriptList.type = ScriptEnum::BG;
			}
			else if (type == "txt")
			{
				ScriptList.type = ScriptEnum::TEXT;
				ScriptList.content = text;
			}
			else if (type == "character")
			{
				std::string temp = text;
				text.erase(0, text.find("=") + 2);
				temp.erase(temp.find(" = "));

				CharDefs.push_back(temp);
				CharNames.push_back(text);
				ScriptList.type = ScriptEnum::CHARDEF;
			}
		}
		for (int i = 0; i < CharNames.size(); i++)
		{
			if (type == CharDefs[i])
			{
				ScriptList.CharName = CharNames[i];
				ScriptList.CharText = text;
				ScriptList.type = ScriptEnum::CHARSAY;
			}
		}
		ScriptVector.push_back(ScriptList);
	}
	return ScriptVector;
}