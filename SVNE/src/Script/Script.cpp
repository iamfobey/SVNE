#include "Script.h"

Script::Script()
{
	CheckIsTransition(ScriptFile, "game\\script.svne");
	ScriptFile.open(ScriptsPath + "script.svne", std::ios::in);
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
	ScriptFile.open(ScriptsPath + "script.svne", std::ios::in);
}

std::vector<Params> Script::Parse()
{
	std::vector<Params> ParamVector;
	Params params;

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
				params.content = text;
				params.type = ScriptDefs::BG;
			}
			else if (type == "txt")
			{
				params.type = ScriptDefs::TEXT;
				params.content = text;
			}
			else if (type == "Character")
			{
				std::string temp = text;
				text.erase(0, text.find("=") + 2);
				temp.erase(temp.find(" = "));

				CharDefs.push_back(temp);
				CharNames.push_back(text);
				params.type = ScriptDefs::CHARDEF;
			}
		}
		for (int i = 0; i < CharNames.size(); i++)
		{
			if (type == CharDefs[i])
			{
				params.CharName = CharNames[i];
				params.CharText = text;
				params.type = ScriptDefs::CHARSAY;
			}
		}
		ParamVector.push_back(params);
	}
	return ParamVector;
}