#pragma once 
#include "../main.hpp"

#include "../Core/General.hpp"


sf::Text menuText(General& G, const std::string& str, const float posX, const float posY) {
	sf::Text result(G.getFontsManager()->getMain());

	result.setCharacterSize(18);
	result.setFillColor(sf::Color::Black);

	result.setString(str);
	result.setPosition(sf::Vector2f(posX, posY));

	return result;
}

sf::Text menuTextSmall(General& G, const std::string& str, const float posX, const float posY) {
	sf::Text result(G.getFontsManager()->getMain());

	result.setCharacterSize(14);
	result.setFillColor(sf::Color::Black);

	result.setString(str);
	result.setPosition(sf::Vector2f(posX, posY));

	return result;
}