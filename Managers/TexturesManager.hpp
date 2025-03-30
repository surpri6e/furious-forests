#pragma once 
#include "../main.hpp"

#include "../Core/Paths.hpp"
#include "../Core/Constants.hpp"

void textureInitilize(sf::Texture& texture, const std::string& pathToTexture) {
	if (!texture.loadFromFile(pathToTexture)) {
		std::cerr << consts::others::DIVIDING_LINE << " WRONG WITH INITILIZE TEXTURE " << consts::others::DIVIDING_LINE << std::endl;
	}
	else {
		std::cout << consts::others::DIVIDING_LINE << " TEXTURE INITILIZE CORRECT " << consts::others::DIVIDING_LINE << std::endl;
	}
}

class TexturesManager {
private:

	// HEROS
	sf::Texture merchantHero;

	// PLAYERS
	sf::Texture malePlayer;
	sf::Texture femalePlayer;

	// TREES
	sf::Texture smallDarkTree;
	sf::Texture bigDarkTree;
	sf::Texture bigLightTree;

	// CLOUDS 
	sf::Texture smallCloud;

	// ROCKS
	sf::Texture standartRock;

	// GRASS 
	sf::Texture lightGrass;

	// HUD
	sf::Texture xpBorder;
	sf::Texture xpInside;

	// ICONS
	sf::Texture checkboxFalse;
	sf::Texture checkboxTrue;
	sf::Texture coin;

	// MENU 
	sf::Texture playButton;
	sf::Texture exitButton;
	sf::Texture settingsButton;
	sf::Texture backgroundImage;

public:

	// Initilize all textures  
	TexturesManager() {
		
		// HEROS
		textureInitilize(this->merchantHero, paths::previousDirectory + paths::textures::heros::MERCHANT_HERO);

		// PLAYERS
		textureInitilize(this->malePlayer, paths::previousDirectory + paths::textures::players::MALE_PLAYER);
		textureInitilize(this->femalePlayer, paths::previousDirectory + paths::textures::players::FEMALE_PLAYER);

		// TREES
		textureInitilize(this->smallDarkTree, paths::previousDirectory + paths::textures::trees::SMALL_DARK_TREE);
		textureInitilize(this->bigDarkTree, paths::previousDirectory + paths::textures::trees::BIG_DARK_TREE);
		textureInitilize(this->bigLightTree, paths::previousDirectory + paths::textures::trees::BIG_LIGHT_TREE);

		// CLOUDS 
		textureInitilize(this->smallCloud, paths::previousDirectory + paths::textures::clouds::SMALL_CLOUD);

		// ROCKS
		textureInitilize(this->standartRock, paths::previousDirectory + paths::textures::rocks::STANDART_ROCK);

		// GRASS 
		textureInitilize(this->lightGrass, paths::previousDirectory + paths::textures::grass::LIGHT_GRASS);

		// HUD
		textureInitilize(this->xpBorder, paths::previousDirectory + paths::textures::hud::XP_BORDER);
		textureInitilize(this->xpInside, paths::previousDirectory + paths::textures::hud::XP_INSIDE);

		// ICONS
		textureInitilize(this->checkboxFalse, paths::previousDirectory + paths::textures::icons::CHECKBOX_FALSE);
		textureInitilize(this->checkboxTrue, paths::previousDirectory + paths::textures::icons::CHECKBOX_TRUE);
		textureInitilize(this->coin, paths::previousDirectory + paths::textures::icons::COIN);

		// MENU 
		textureInitilize(this->playButton, paths::previousDirectory + paths::textures::menu::PLAY_BUTTON);
		textureInitilize(this->exitButton, paths::previousDirectory + paths::textures::menu::EXIT_BUTTON);
		textureInitilize(this->settingsButton, paths::previousDirectory + paths::textures::menu::SETTINGS_BUTTON);
		textureInitilize(this->backgroundImage, paths::previousDirectory + paths::textures::menu::BACKGROUND_IMAGE);
	}

};