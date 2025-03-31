#pragma once 
#include "../main.hpp"

#include "../Paths.hpp"
#include "../Constants.hpp"
#include "../Utils/Wrongs.hpp"

void textureInitialize(sf::Texture& texture, const std::string& pathToTexture) {
	if (!texture.loadFromFile(pathToTexture)) {
		Wrongs::add(WRONG_WITH_INITIALIZE_TEXTURE);
	}
	else {
		std::cout << consts::others::DIVIDING_LINE << " TEXTURE INITIALIZE CORRECT " << consts::others::DIVIDING_LINE << std::endl;
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
	// Initialize all textures  
	TexturesManager() {
		// DEBUG MODE ALL
		
		// HEROS
		textureInitialize(this->merchantHero, paths::previousDirectory + paths::textures::heros::MERCHANT_HERO);

		// PLAYERS
		textureInitialize(this->malePlayer, paths::previousDirectory + paths::textures::players::MALE_PLAYER);
		textureInitialize(this->femalePlayer, paths::previousDirectory + paths::textures::players::FEMALE_PLAYER);

		// TREES
		textureInitialize(this->smallDarkTree, paths::previousDirectory + paths::textures::trees::SMALL_DARK_TREE);
		textureInitialize(this->bigDarkTree, paths::previousDirectory + paths::textures::trees::BIG_DARK_TREE);
		textureInitialize(this->bigLightTree, paths::previousDirectory + paths::textures::trees::BIG_LIGHT_TREE);

		// CLOUDS 
		textureInitialize(this->smallCloud, paths::previousDirectory + paths::textures::clouds::SMALL_CLOUD);

		// ROCKS
		textureInitialize(this->standartRock, paths::previousDirectory + paths::textures::rocks::STANDART_ROCK);

		// GRASS 
		textureInitialize(this->lightGrass, paths::previousDirectory + paths::textures::grass::LIGHT_GRASS);

		// HUD
		textureInitialize(this->xpBorder, paths::previousDirectory + paths::textures::hud::XP_BORDER);
		textureInitialize(this->xpInside, paths::previousDirectory + paths::textures::hud::XP_INSIDE);

		// ICONS
		textureInitialize(this->checkboxFalse, paths::previousDirectory + paths::textures::icons::CHECKBOX_FALSE);
		textureInitialize(this->checkboxTrue, paths::previousDirectory + paths::textures::icons::CHECKBOX_TRUE);
		textureInitialize(this->coin, paths::previousDirectory + paths::textures::icons::COIN);

		// MENU 
		textureInitialize(this->playButton, paths::previousDirectory + paths::textures::menu::PLAY_BUTTON);
		textureInitialize(this->exitButton, paths::previousDirectory + paths::textures::menu::EXIT_BUTTON);
		textureInitialize(this->settingsButton, paths::previousDirectory + paths::textures::menu::SETTINGS_BUTTON);
		textureInitialize(this->backgroundImage, paths::previousDirectory + paths::textures::menu::BACKGROUND_IMAGE);
	}

	const sf::Texture& getBackgroundImage() const {
		return this->backgroundImage;
	}
};