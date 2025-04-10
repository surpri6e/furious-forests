#pragma once 
#include "../main.hpp"

#include "../Utils/InitializeShape.hpp"
#include "../Core/General.hpp"


class MenuSettings {
private:
	bool isOut;

	sf::RectangleShape backgoundMenuSettings;
public:
	MenuSettings(General& G) {
		decltype(auto) texturesManager = G.getTexturesManager();
		decltype(auto) texturesSizes = texturesManager->getTexturesSizes();
		decltype(auto) settings = G.getSettings();

		this->isOut = false;

		initializeShape(
			this->backgoundMenuSettings,
			600,
			800,
			660,
			140,
			texturesManager->getBackgroundSettings()
		);
	}

	void showMenuSettings(General& G) {
		decltype(auto) window = G.getWindow();

		window.draw(this->backgoundMenuSettings);
	}
};