#pragma once 
#include "../main.hpp"

#include "../Managers/TexturesManager.hpp"
#include "Settings.hpp"

class General {
private:
	const std::unique_ptr<const TexturesManager> texturesManager = std::make_unique<TexturesManager>(TexturesManager());

	sf::RenderWindow& window;
	sf::Clock clock;
	sf::View camera;

	Settings& settings;
public:
	General(sf::RenderWindow& window, Settings& settings) : window(window), settings(settings) {
		
	}

	sf::View& getCamera() {
		return this->camera;
	}

	sf::Clock& getClock() {
		return this->clock;
	}

	sf::RenderWindow& getWindow() {
		return this->window;
	}

	Settings& getSettings() {
		return this->settings;
	}

	const TexturesManager* getTexturesManager() {
		return this->texturesManager.get();
	}
};