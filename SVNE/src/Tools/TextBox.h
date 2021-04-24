#pragma once

#include "../Core/stdafx.h"

class TextBox
{
public:
	TextBox();
	TextBox(sf::Color color, sf::Vector2f size, sf::Vector2f pos);
	
	sf::RectangleShape GetTextBox();

	void SetSize(sf::Vector2f size);
	void SetPos(sf::Vector2f pos);
	void SetColor(sf::Color color);

	int GetWidth();

	~TextBox();
private:
	sf::RectangleShape TextBoxShape;
};