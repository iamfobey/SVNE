#pragma once

#include "stdafx.h"

void CheckIsTransition(std::fstream& file, std::string fileName);
void SetTextSettings(sf::Text& text, sf::Font& font, sf::Color color, sf::Vector2f pos, int charSize);