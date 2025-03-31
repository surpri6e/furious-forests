#pragma once 
#include "../main.hpp"

#include "../Core/General.hpp"
#include "../Constants.hpp"

class Menu {
private:
	sf::RectangleShape backgroundImage;

	sf::RectangleShape playButton;
	sf::RectangleShape settingsButton;
	sf::RectangleShape exitButton;
public:
	Menu(General& G) {
		backgroundImage.setTexture(&G.getTexturesManager()->getBackgroundImage());
		backgroundImage.setPosition(sf::Vector2f(0, 0));
		// backgroundImage.setSize(sf::Vector2f(consts::WIDTH_WINDOW, consts::HEIGHT_WINDOW));
	}

	void showMenu(sf::RenderWindow& w) {
		w.draw(backgroundImage);
		w.display();
	}
};