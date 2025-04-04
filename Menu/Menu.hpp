#pragma once 
#include "../main.hpp"

#include "../Core/General.hpp"
#include "../Paths.hpp"

class Menu {
private:
	sf::RectangleShape backgroundImage;

	sf::RectangleShape playButton;
	sf::RectangleShape settingsButton;
	sf::RectangleShape exitButton;
public:
	Menu(General& G) {
		decltype(auto) texturesManager = G.getTexturesManager();
		decltype(auto) texturesSizes = texturesManager->getTexturesSizes();
		decltype(auto) settings = G.getSettings();

		int spaceBetweenButtons = 30;
		int indent = 100;

		backgroundImage.setTexture(&G.getTexturesManager()->getBackgroundImage());
		backgroundImage.setPosition(sf::Vector2f(0, 0));
		backgroundImage.setSize(sf::Vector2f((float)settings.getWidthWindow(), (float)settings.getHeightWindow())); // Какой должен быть размер? SCREEN or WINDOW?


		playButton.setTexture(&texturesManager->getPlayButton());
		playButton.setPosition(sf::Vector2f((float)indent,
			(float)(settings.getHeightWindow() - (3 * texturesSizes.at(paths::textures::menu::PLAY_BUTTON).second + indent + 2 * spaceBetweenButtons)) // Какой должен быть размер? SCREEN or WINDOW?
		));
		playButton.setSize(sf::Vector2f(
			(float)texturesSizes.at(paths::textures::menu::PLAY_BUTTON).first,
			(float)texturesSizes.at(paths::textures::menu::PLAY_BUTTON).second
		));

		settingsButton.setTexture(&G.getTexturesManager()->getSettingsButton());
		settingsButton.setPosition(sf::Vector2f((float)indent,
			(float)(settings.getHeightWindow() - (2 * texturesSizes.at(paths::textures::menu::SETTINGS_BUTTON).second + indent + spaceBetweenButtons)) // Какой должен быть размер? SCREEN or WINDOW?
		));
		settingsButton.setSize(sf::Vector2f(
			(float)texturesSizes.at(paths::textures::menu::SETTINGS_BUTTON).first,
			(float)texturesSizes.at(paths::textures::menu::SETTINGS_BUTTON).second
		));

		exitButton.setTexture(&G.getTexturesManager()->getExitButton());
		exitButton.setPosition(sf::Vector2f((float)indent,
			(float)(settings.getHeightWindow() - (texturesSizes.at(paths::textures::menu::EXIT_BUTTON).second + indent)) // Какой должен быть размер? SCREEN or WINDOW?
		));
		exitButton.setSize(sf::Vector2f(
			(float)texturesSizes.at(paths::textures::menu::EXIT_BUTTON).first,
			(float)texturesSizes.at(paths::textures::menu::EXIT_BUTTON).second
		));
	}

	void showMenu(sf::RenderWindow& w) {
		w.draw(backgroundImage);

		w.draw(playButton);
		w.draw(settingsButton);
		w.draw(exitButton);
	}
};