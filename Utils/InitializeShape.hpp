#pragma once
#include "../main.hpp"

template<typename T, typename U>
void initializeShape(sf::RectangleShape& shape, T width, T height, U posX, U posY, const sf::Texture& texture) {
	shape.setSize(sf::Vector2f((float)width, (float)height));
	shape.setPosition(sf::Vector2f((float)posX, (float)posY));
	shape.setTexture(&texture);
};

template<typename T, typename U>
void initializeShape(sf::RectangleShape& shape, T width, T height, U posX, U posY, const sf::Color& color) {
	shape.setSize(sf::Vector2f((float)width, (float)height));
	shape.setPosition(sf::Vector2f((float)posX, (float)posY));
	shape.setFillColor(color);
};

//template<typename T>
//void initializeShape(sf::RecatngleShape& shape, T width, T height, T posX, T posY, const sf::Texture& texture) {
//	shape.setSize(sf::Vector2f((float)width, (float)height));
//	shape.setPosition(sf::Vector2f((float)posX, (float)posY));
//	shape.setTexture(&texture);
//};