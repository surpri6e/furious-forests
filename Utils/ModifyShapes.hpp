#pragma once 
#include "../main.hpp"

// BAD NAME
namespace modshapes {
	template<typename T>
	void changePosition(const std::vector<std::reference_wrapper<sf::RectangleShape>>& shapes, const T posX, const T posY) {
		for (auto& shape : shapes) {
			shape.get().setPosition(sf::Vector2f((float)posX, (float)posY));
		}
	}
}