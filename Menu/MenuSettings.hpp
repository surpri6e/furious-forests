#pragma once
#include "../main.hpp"

#include "../Core/General.hpp"
#include "../Utils/Initializer.hpp"
#include "../Utils/ModifyShapes.hpp"
#include "MenuText.hpp"

struct MenuSettingsShapes {
	sf::RectangleShape saveButton;
	sf::RectangleShape saveButtonBackground;
	sf::RectangleShape saveButtonMask;

	sf::RectangleShape exitButton;
	sf::RectangleShape exitButtonBackground;
	sf::RectangleShape exitButtonMask;

	sf::RectangleShape border;
	sf::RectangleShape background;

	sf::RectangleShape backgroundMusicPlayingCheckbox;
	sf::RectangleShape windowFullscreenCheckbox;
	sf::RectangleShape playingFemaleCheckbox;
};

class MenuSettings {
private:
	std::unique_ptr<MenuSettingsShapes> pShapes = std::make_unique<MenuSettingsShapes>();

	const int mIndentWidth = 10;
	const int mIndentHeight = 15;
	const int mSpaceBetweenLines = 40;

	const float mWidthBackground;
	const float mHeightBackground;
	const float mPosXBackground;
	const float mPosYBackground;

	const int mSizeOfBorder;

	const int mSizeOfCheckbox = 32;

	bool mIsTimeForMenuSettingsInitializingElapsed;
	const std::uint32_t mAnimationDurationMenuSettingsInitializing = 500;
	std::uint32_t mTimeForAnimationMenuSettingsInitializing;

	sf::Text mBackgroundMusicPlayingText;
	sf::Text mWindowFullscreenText;
	sf::Text mPlayingFemaleText;
public: 
	MenuSettings(General& G): 
		mWidthBackground(G.getSettings().getWidthWindow() / 3),
		mHeightBackground(G.getSettings().getHeightWindow() / 1.2),
		mPosXBackground(G.getSettings().getWidthWindow() / 2 - G.getSettings().getWidthWindow() / 6),
		mPosYBackground(G.getSettings().getHeightWindow() / 2 - G.getSettings().getHeightWindow() / 2.4),
		mSizeOfBorder(16 * this->mWidthBackground / (float)(G.getTexturesManager()->getTexturesSizes().at(paths::textures::menu::SETTINGS_BORDER_MENU).first)),
		mBackgroundMusicPlayingText(menuText(G, "Background music play:", 
			this->mPosXBackground + this->mSizeOfBorder + this->mIndentWidth,
			this->mPosYBackground + this->mSizeOfBorder + this->mIndentHeight
		)),
		mWindowFullscreenText(menuText(G, "Fullscreen:", 
			this->mPosXBackground + this->mSizeOfBorder + this->mIndentWidth,
			this->mPosYBackground + this->mSizeOfBorder + this->mIndentHeight + this->mSpaceBetweenLines + 18
		)),
		mPlayingFemaleText(menuText(G, "Play as female:", 
			this->mPosXBackground + this->mSizeOfBorder + this->mIndentWidth,
			this->mPosYBackground + this->mSizeOfBorder + this->mIndentHeight + this->mSpaceBetweenLines * 2 + 18 * 2
		))
	{
		decltype(auto) settings = G.getSettings();
		decltype(auto) texturesManager = G.getTexturesManager();

		this->mIsTimeForMenuSettingsInitializingElapsed = false;

		this->mTimeForAnimationMenuSettingsInitializing = 0;

		initializer::shapeInitialize<float>(
			this->pShapes.get()->border,
			{this->mWidthBackground, this->mHeightBackground, this->mPosXBackground, this->mPosYBackground },
			G.getTexturesManager()->getSettingsBorderMenu()
		);
		initializer::shapeInitialize<float>(
			this->pShapes.get()->background,
			{this->mWidthBackground, this->mHeightBackground, this->mPosXBackground, this->mPosYBackground },
			sf::Color(217, 192, 124)
		);

		initializer::shapeInitialize<float>(
			this->pShapes.get()->backgroundMusicPlayingCheckbox,
			{
				(float)this->mSizeOfCheckbox, 
				(float)this->mSizeOfCheckbox,
				this->mPosXBackground + this->mWidthBackground - this->mSizeOfBorder - this->mIndentWidth - this->mSizeOfCheckbox,
				this->mPosYBackground + this->mSizeOfBorder + this->mIndentHeight - this->mSizeOfCheckbox / 4
			},
			settings.getIsBackgroundMusicPlaying() ? texturesManager->getCheckboxTrue() : texturesManager->getCheckboxFalse()
		);

		initializer::shapeInitialize<float>(
			this->pShapes.get()->windowFullscreenCheckbox,
			{
				(float)this->mSizeOfCheckbox,
				(float)this->mSizeOfCheckbox,
				this->mPosXBackground + this->mWidthBackground - this->mSizeOfBorder - this->mIndentWidth - this->mSizeOfCheckbox,
				this->mPosYBackground + this->mSizeOfBorder + this->mIndentHeight + this->mSpaceBetweenLines + 18 - this->mSizeOfCheckbox / 4
			},
			settings.getIsWindowFullscreen() ? texturesManager->getCheckboxTrue() : texturesManager->getCheckboxFalse()
		);

		initializer::shapeInitialize<float>(
			this->pShapes.get()->playingFemaleCheckbox,
			{
				(float)this->mSizeOfCheckbox,
				(float)this->mSizeOfCheckbox,
				this->mPosXBackground + this->mWidthBackground - this->mSizeOfBorder - this->mIndentWidth - this->mSizeOfCheckbox,
				this->mPosYBackground + this->mSizeOfBorder + this->mIndentHeight + this->mSpaceBetweenLines * 2 + 18 * 2 - this->mSizeOfCheckbox / 4
			},
			settings.getPlayerGender() ? texturesManager->getCheckboxTrue() : texturesManager->getCheckboxFalse()
		);
	}

	void show(General& G) {
		decltype(auto) window = G.getWindow();
		decltype(auto) settings = G.getSettings();

		if (!this->mIsTimeForMenuSettingsInitializingElapsed) {
			this->mTimeForAnimationMenuSettingsInitializing = G.getClock().getElapsedTime().asMilliseconds();
		}

		if (G.getClock().getElapsedTime().asMilliseconds() - this->mTimeForAnimationMenuSettingsInitializing <= this->mAnimationDurationMenuSettingsInitializing) {
			modshapes::setPosition(
				{ std::ref(pShapes.get()->background), std::ref(pShapes.get()->border) },
				pShapes.get()->background.getPosition().x,
				(G.getClock().getElapsedTime().asMilliseconds() - this->mTimeForAnimationMenuSettingsInitializing) / (float)this->mAnimationDurationMenuSettingsInitializing * this->mPosYBackground
			);
		
			this->mIsTimeForMenuSettingsInitializingElapsed = true;
		}
		else {
			modshapes::setPosition(
				{ std::ref(pShapes.get()->background), std::ref(pShapes.get()->border) }, pShapes.get()->background.getPosition().x, this->mPosYBackground
			);
		}

		window.draw(this->pShapes->background);
		window.draw(this->pShapes->border);

		if (G.getClock().getElapsedTime().asMilliseconds() - this->mTimeForAnimationMenuSettingsInitializing > this->mAnimationDurationMenuSettingsInitializing) {
			window.draw(this->mBackgroundMusicPlayingText);
			window.draw(this->mWindowFullscreenText);
			window.draw(this->mPlayingFemaleText);

			window.draw(this->pShapes.get()->backgroundMusicPlayingCheckbox);
			window.draw(this->pShapes.get()->playingFemaleCheckbox);
			window.draw(this->pShapes.get()->windowFullscreenCheckbox);
		}
	}
};