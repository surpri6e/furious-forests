#pragma once 
#include "../main.hpp"

#include "../Utils/Initializer.hpp"
#include "../Parcers/TexturesSizesParcer.hpp"

// paths::previousDirectory BUG

class TexturesManager {
private:
	std::map<std::string, std::pair<int, int>> mTexturesSizes;

	// HEROS
	sf::Texture mMerchantHero;

	// PLAYERS
	sf::Texture mMalePlayer;
	sf::Texture mFemalePlayer;

	// TREES
	sf::Texture mSmallDarkTree;
	sf::Texture mBigDarkTree;
	sf::Texture mBigLightTree;

	// CLOUDS 
	sf::Texture mSmallCloud;

	// ROCKS
	sf::Texture mStandartRock;

	// GRASS 
	sf::Texture mLightGrass;

	// HUD
	sf::Texture mXpBorder;
	sf::Texture mXpInside;

	// ICONS
	sf::Texture mCheckboxFalse;
	sf::Texture mCheckboxTrue;
	sf::Texture mCoin;

	// BUTTONS
	sf::Texture mPlayButton;
	sf::Texture mExitButton;
	sf::Texture mSettingsButton;
	sf::Texture mSaveButton;
	sf::Texture mNextElementButton;

	// MENU 
	sf::Texture mBackgroundImageMenu;
	sf::Texture mSettingsBorderMenu;
public:
	// Initialize all textures  
	TexturesManager() {
		// HEROS
		initializer::textureInitialize(this->mMerchantHero, paths::previousDirectory + paths::textures::heros::MERCHANT_HERO);

		// PLAYERS
		initializer::textureInitialize(this->mMalePlayer, paths::previousDirectory + paths::textures::players::MALE_PLAYER);
		initializer::textureInitialize(this->mFemalePlayer, paths::previousDirectory + paths::textures::players::FEMALE_PLAYER);

		// TREES
		initializer::textureInitialize(this->mSmallDarkTree, paths::previousDirectory + paths::textures::trees::SMALL_DARK_TREE);
		initializer::textureInitialize(this->mBigDarkTree, paths::previousDirectory + paths::textures::trees::BIG_DARK_TREE);
		initializer::textureInitialize(this->mBigLightTree, paths::previousDirectory + paths::textures::trees::BIG_LIGHT_TREE);

		// CLOUDS 
		initializer::textureInitialize(this->mSmallCloud, paths::previousDirectory + paths::textures::clouds::SMALL_CLOUD);

		// ROCKS
		initializer::textureInitialize(this->mStandartRock, paths::previousDirectory + paths::textures::rocks::STANDART_ROCK);

		// GRASS 
		initializer::textureInitialize(this->mLightGrass, paths::previousDirectory + paths::textures::grass::LIGHT_GRASS);

		// HUD
		initializer::textureInitialize(this->mXpBorder, paths::previousDirectory + paths::textures::hud::XP_BORDER);
		initializer::textureInitialize(this->mXpInside, paths::previousDirectory + paths::textures::hud::XP_INSIDE);

		// ICONS
		initializer::textureInitialize(this->mCheckboxFalse, paths::previousDirectory + paths::textures::icons::CHECKBOX_FALSE);
		initializer::textureInitialize(this->mCheckboxTrue, paths::previousDirectory + paths::textures::icons::CHECKBOX_TRUE);
		initializer::textureInitialize(this->mCoin, paths::previousDirectory + paths::textures::icons::COIN);

		// BUTTONS
		initializer::textureInitialize(this->mPlayButton, paths::previousDirectory + paths::textures::buttons::PLAY_BUTTON);
		initializer::textureInitialize(this->mExitButton, paths::previousDirectory + paths::textures::buttons::EXIT_BUTTON);
		initializer::textureInitialize(this->mSettingsButton, paths::previousDirectory + paths::textures::buttons::SETTINGS_BUTTON);
		initializer::textureInitialize(this->mSaveButton, paths::previousDirectory + paths::textures::buttons::SAVE_BUTTON);
		initializer::textureInitialize(this->mNextElementButton, paths::previousDirectory + paths::textures::buttons::NEXT_ELEMENT_BUTTON);

		// MENU 
		initializer::textureInitialize(this->mBackgroundImageMenu, paths::previousDirectory + paths::textures::menu::BACKGROUND_IMAGE_MENU);
		initializer::textureInitialize(this->mSettingsBorderMenu, paths::previousDirectory + paths::textures::menu::SETTINGS_BORDER_MENU);

		this->mTexturesSizes = parceTexturesSizes();
	}

	const std::map<std::string, std::pair<int, int>>& getTexturesSizes() const {
		return this->mTexturesSizes;
	}

	const sf::Texture& getCheckboxFalse() const {
		return this->mCheckboxFalse;
	}

	const sf::Texture& getCheckboxTrue() const {
		return this->mCheckboxTrue;
	}

	const sf::Texture& getSettingsBorderMenu() const {
		return this->mSettingsBorderMenu;
	}

	const sf::Texture& getBackgroundImageMenu() const {
		return this->mBackgroundImageMenu;
	}

	const sf::Texture& getPlayButton() const {
		return this->mPlayButton;
	}

	const sf::Texture& getExitButton() const {
		return this->mExitButton;
	}

	const sf::Texture& getSaveButton() const {
		return this->mSaveButton;
	}
	const sf::Texture& getNextElementButton() const {
		return this->mNextElementButton;
	}

	const sf::Texture& getSettingsButton() const {
		return this->mSettingsButton;
	}
};