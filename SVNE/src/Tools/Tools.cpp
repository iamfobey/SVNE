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

void WrapperText(sf::Text& text, sf::RenderWindow& window)
{
	float width = text.getLocalBounds().width;

	std::string temp = text.getString();

	if (width > window.getSize().x / 2)
	{
		sf::Text tempText;
		std::string temp2;
		for (int i = 0; i < text.getString().getSize(); i++)
		{
			temp2 += temp[i];
			std::cout << temp2;
			if (tempText.getLocalBounds().width == window.getSize().x)
			{
				std::cout << "true\n";
			}
		}
		std::cout << '\n\n';
	}
}