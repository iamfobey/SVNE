#include "Tools.h"

void CheckIsTransition(std::fstream& file, std::string fileName)
{
	file.open(fileName, std::ios::in);

	std::string res;

	while (std::getline(file, res))

		if (file.eof())
		{
			if (res[0] != '\0')
			{
				file.close();

				file.open(fileName, std::ios::app);
				file << '\n';
				file.close();
			}
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