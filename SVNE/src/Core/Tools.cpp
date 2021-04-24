#include "Tools.h"

void CheckIsTransition(std::fstream& file, std::string fileName)
{
	file.open("game\\" + fileName, std::ios::in);

	std::string res;

	while (file.good())
	{
		std::getline(file, res);
	}
	if (res[0] != '\0')
	{
		file.close();

		file.open("game\\" + fileName, std::ios::app);
		file << '\n';
		file.close();
	}
	file.close();
}

void SetTextSettings(sf::Text& text, sf::Font& font, sf::Color color, sf::Vector2f pos, int charSize)
{
	text.setFont(font);
	text.setFillColor(color);
	text.setPosition(pos);
	text.setCharacterSize(charSize);
}