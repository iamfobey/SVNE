#include "TextBox.h"

TextBox::TextBox(sf::Color color, sf::Vector2f size, sf::Vector2f pos)
{
	TextBoxShape.setFillColor(color);
	TextBoxShape.setSize(size);
	TextBoxShape.setPosition(pos);
}

TextBox::TextBox()
{

}

sf::RectangleShape TextBox::GetTextBox()
{
	return TextBoxShape;
}

void TextBox::SetSize(sf::Vector2f size)
{
	TextBoxShape.setSize(size);
}

void TextBox::SetPos(sf::Vector2f pos)
{
	TextBoxShape.setPosition(pos);
}

void TextBox::SetColor(sf::Color color)
{
	TextBoxShape.setFillColor(color);
}

int TextBox::GetWidth()
{
	return TextBoxShape.getSize().x;
}

TextBox::~TextBox()
{

}