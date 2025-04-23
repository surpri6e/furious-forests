#pragma once 
#include "../main.hpp"

#include "../Utils/Initializer.hpp"

// paths::previousDirectory BUG

class FontsManager {
private:
	sf::Font main;
public:
	FontsManager() {
		initializer::fontInitialize(this->main, paths::previousDirectory + paths::fonts::MAIN);
	}

	const sf::Font& getMain() const {
		return this->main;
	}
};