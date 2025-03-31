#pragma once 
#include "../main.hpp"

#include "../Managers/TexturesManager.hpp"
#include "../Parcers/SettingsParcer.hpp"
#include "Settings.hpp"

class General {
private:
	const std::unique_ptr<const TexturesManager> texturesManager = std::make_unique<TexturesManager>(TexturesManager());

	sf::RenderWindow window;
	sf::Clock clock;
	sf::View camera;

	Settings settings;
public:
	General(const std::string& title) {
		auto parcedSettings = parceSettings();
		this->settings = Settings(parcedSettings);

		this->window = sf::RenderWindow(
			sf::VideoMode({ (unsigned int)this->settings.getWidthWindow() , (unsigned int)this->settings.getHeightWindow() }),
			title,
			this->settings.getIsWindowFullscreen()
		);
	}

	sf::RenderWindow& getWindow() {
		return this->window;
	}

	const TexturesManager* getTexturesManager() {
		return this->texturesManager.get();
	}
};