#pragma once
#include "../main.hpp"

#include "../Core/General.hpp"

class MenuSettings {
private:
	/*sf::RectangleShape backgroundImage;

	sf::RectangleShape checkbox;

	sf::Text txt;*/
public: 
	MenuSettings() {}
	/*MenuSettings(General& G): txt(G.getFontsManager()->getMain()) {
		decltype(auto) texturesManager = G.getTexturesManager();
		decltype(auto) texturesSizes = texturesManager->getTexturesSizes();
		decltype(auto) settings = G.getSettings();

		initializeShape(
			this->backgroundImage,
			(float)(settings.getWidthWindow() / 3),
			(float)(settings.getHeightWindow() / 1.2),
			(float)(settings.getWidthWindow() / 2 - settings.getWidthWindow() / 6),
			(float)(settings.getHeightWindow() / 2 - settings.getHeightWindow() / 2.4),
			texturesManager->getSettingsBackgroundImage()
		);

		initializeShape(
			this->checkbox,
			32,
			32,
			(float)(settings.getWidthWindow() / 2 - settings.getWidthWindow() / 6) + 80 + 440,
			(float)(settings.getHeightWindow() / 2 - settings.getHeightWindow() / 2.4) + 60 - 8,
			texturesManager->getCheckboxFalse()
		);

		txt.setFillColor(sf::Color::Black);
		txt.setPosition(sf::Vector2f((float)(settings.getWidthWindow() / 2 - settings.getWidthWindow() / 6) + 80, (float)(settings.getHeightWindow() / 2 - settings.getHeightWindow() / 2.4) + 60));
		txt.setCharacterSize(16);
		txt.setString("Player gender is male");
	}*/

	/*void showMenuSettings(General& G) {
		decltype(auto) window = G.getWindow();

		window.draw(this->backgroundImage);
		window.draw(this->txt);
		window.draw(this->checkbox);
	}*/
};