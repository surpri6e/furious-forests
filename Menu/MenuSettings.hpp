#pragma once
#include "../main.hpp"

#include "../Core/General.hpp"
#include "../Utils/Initializer.hpp"
#include "../Utils/ModifyShapes.hpp"

struct MenuSettingsShapes {
	sf::RectangleShape saveButton;
	sf::RectangleShape saveButtonBackground;
	sf::RectangleShape saveButtonMask;

	sf::RectangleShape exitButton;
	sf::RectangleShape exitButtonBackground;
	sf::RectangleShape exitButtonMask;

	sf::RectangleShape border;
	sf::RectangleShape background;

	sf::RectangleShape isBackgroundMusicPlayingCheckbox;
	sf::RectangleShape mIsWindowFullscreenCheckbox;
	sf::RectangleShape mIsPlayingFemaleCheckbox;
};

class MenuSettings {
private:
	std::unique_ptr<MenuSettingsShapes> pShapes = std::make_unique<MenuSettingsShapes>();

	// уточнить у люды
	const int mSizeOfBorderIndent = 54;

	const int mIndentWidth = 20;
	const int mIndentHeight = 30;
	const int mSpaceBetween = 40;

	bool mIsMenuSettingsInitialazed;
	const std::uint32_t mAnimationDurationMenuSettingsInitializing = 500;
	std::uint32_t mTimeForAnimationMenuSettingsInitializing;


	/* 1
		isWindowFullscreen 1
		playerGender 0*/

	bool isIsBackgroundMusicPlayingEntered;
	bool isIsWindowFullscreenEntered;
	bool isIsPlayingFemaleEntered;

	sf::Text mIsBackgroundMusicPlayingText;
	sf::Text mIsWindowFullscreenText;
	sf::Text mIsPlayingFemaleText;
public: 
	//MenuSettings() {}
	MenuSettings(General& G): mIsBackgroundMusicPlayingText(G.getFontsManager()->getMain()), mIsWindowFullscreenText(G.getFontsManager()->getMain()), mIsPlayingFemaleText(G.getFontsManager()->getMain()) {
		decltype(auto) texturesManager = G.getTexturesManager();
		decltype(auto) texturesSizes = texturesManager->getTexturesSizes();
		decltype(auto) settings = G.getSettings();

		//dynamic memory or not?
		const auto cursor = sf::Cursor::createFromSystem(sf::Cursor::Type::Arrow).value();
		G.getWindow().setMouseCursor(cursor);

		this->isIsBackgroundMusicPlayingEntered = false;
		this->isIsWindowFullscreenEntered = false;
		this->isIsPlayingFemaleEntered = false;


		initializer::shapeInitialize<float>(
			this->pShapes.get()->border,
			{
				(float)(settings.getWidthWindow() / 3),
				(float)(settings.getHeightWindow() / 1.2),
				(float)(settings.getWidthWindow() / 2 - settings.getWidthWindow() / 6),
				(float)(settings.getHeightWindow() / 2 - settings.getHeightWindow() / 2.4)
			},
			texturesManager->getSettingsBorderMenu()
		);

		initializer::shapeInitialize<float>(
			this->pShapes.get()->background,
			{
				(float)(settings.getWidthWindow() / 3),
				(float)(settings.getHeightWindow() / 1.2),
				(float)(settings.getWidthWindow() / 2 - settings.getWidthWindow() / 6),
				(float)(settings.getHeightWindow() / 2 - settings.getHeightWindow() / 2.4)
			},
			sf::Color(217, 192, 124)
		);

		this->mIsMenuSettingsInitialazed = false;

		// Свой класс под текст
		mIsBackgroundMusicPlayingText.setCharacterSize(16);
		mIsBackgroundMusicPlayingText.setFillColor(sf::Color::Black);
		mIsBackgroundMusicPlayingText.setString("Background music play:");
		mIsBackgroundMusicPlayingText.setPosition(sf::Vector2f(
			(float)(settings.getWidthWindow() / 2 - settings.getWidthWindow() / 6) + this->mSizeOfBorderIndent + this-> mIndentWidth,
			(float)(settings.getHeightWindow() / 2 - settings.getHeightWindow() / 2.4) + this->mSizeOfBorderIndent + this->mIndentHeight
		));
		initializer::shapeInitialize<float>(
			this->pShapes.get()->isBackgroundMusicPlayingCheckbox,
			{
				(float)32,
				(float)32,
				(float)(settings.getWidthWindow() / 2 - settings.getWidthWindow() / 6) + (float)(settings.getWidthWindow() / 3) - 32 - this->mSizeOfBorderIndent - this->mIndentWidth,
				(float)(settings.getHeightWindow() / 2 - settings.getHeightWindow() / 2.4) + this->mSizeOfBorderIndent + this->mIndentHeight - 8
			},
			settings.getIsBackgroundMusicPlaying() ? texturesManager->getCheckboxTrue() : texturesManager->getCheckboxFalse()
		);

		// 16 size of text

		mIsWindowFullscreenText.setCharacterSize(16);
		mIsWindowFullscreenText.setFillColor(sf::Color::Black);
		mIsWindowFullscreenText.setString("Fullscreen:");
		mIsWindowFullscreenText.setPosition(sf::Vector2f(
			(float)(settings.getWidthWindow() / 2 - settings.getWidthWindow() / 6) + this->mSizeOfBorderIndent + this->mIndentWidth,
			(float)(settings.getHeightWindow() / 2 - settings.getHeightWindow() / 2.4) + this->mSizeOfBorderIndent + this->mIndentHeight + 16 + this->mSpaceBetween
		));
		initializer::shapeInitialize<float>(
			this->pShapes.get()->mIsWindowFullscreenCheckbox,
			{
				(float)32,
				(float)32,
				(float)(settings.getWidthWindow() / 2 - settings.getWidthWindow() / 6) + (float)(settings.getWidthWindow() / 3) - 32 - this->mSizeOfBorderIndent - this->mIndentWidth,
				(float)(settings.getHeightWindow() / 2 - settings.getHeightWindow() / 2.4) + this->mSizeOfBorderIndent + this->mIndentHeight + 16 + this->mSpaceBetween - 8
			},
			settings.getIsWindowFullscreen() ? texturesManager->getCheckboxTrue() : texturesManager->getCheckboxFalse()
		);

		mIsPlayingFemaleText.setCharacterSize(16);
		mIsPlayingFemaleText.setFillColor(sf::Color::Black);
		mIsPlayingFemaleText.setString("Play as female:");
		mIsPlayingFemaleText.setPosition(sf::Vector2f(
			(float)(settings.getWidthWindow() / 2 - settings.getWidthWindow() / 6) + this->mSizeOfBorderIndent + this->mIndentWidth,
			(float)(settings.getHeightWindow() / 2 - settings.getHeightWindow() / 2.4) + this->mSizeOfBorderIndent + this->mIndentHeight + 2 * 16 + 2 * this->mSpaceBetween
		));

		initializer::shapeInitialize<float>(
			this->pShapes.get()->mIsPlayingFemaleCheckbox,
			{
				(float)32,
				(float)32,
				(float)(settings.getWidthWindow() / 2 - settings.getWidthWindow() / 6) + (float)(settings.getWidthWindow() / 3) - 32 - this->mSizeOfBorderIndent - this->mIndentWidth,
				(float)(settings.getHeightWindow() / 2 - settings.getHeightWindow() / 2.4) + this->mSizeOfBorderIndent + this->mIndentHeight + 2 * 16 + 2 * this->mSpaceBetween - 8
			},
			settings.getPlayerGender() ? texturesManager->getCheckboxTrue() : texturesManager->getCheckboxFalse()
		);
	}

	void showMenuSettings(General& G) {
		decltype(auto) window = G.getWindow();
		decltype(auto) settings = G.getSettings();

		if (!this->mIsMenuSettingsInitialazed) {
			this->mTimeForAnimationMenuSettingsInitializing = G.getClock().getElapsedTime().asMilliseconds();
		}

		// HOW I NEED WORK WIN FLOAT AND INT HERE???
		// ALL PADDINGS IS NORMALY BECAUSE ALL BUTTONS HAS 28PX HEIGHT
		if (G.getClock().getElapsedTime().asMilliseconds() - this->mTimeForAnimationMenuSettingsInitializing <= this->mAnimationDurationMenuSettingsInitializing) {
			modshapes::changePosition(
				{ std::ref(pShapes.get()->background), std::ref(pShapes.get()->border) },
				pShapes.get()->background.getPosition().x,
				(float)(((G.getClock().getElapsedTime().asMilliseconds() - this->mTimeForAnimationMenuSettingsInitializing) / (float)this->mAnimationDurationMenuSettingsInitializing) * (float)(settings.getHeightWindow() / 2 - settings.getHeightWindow() / 2.4))
			);
		
			this->mIsMenuSettingsInitialazed = true;
		}
		else {
			// end values
			modshapes::changePosition(
				{ std::ref(pShapes.get()->background), std::ref(pShapes.get()->border) },
				pShapes.get()->background.getPosition().x,
				(float)(settings.getHeightWindow() / 2 - settings.getHeightWindow() / 2.4)
			);
		}

		this->isIsBackgroundMusicPlayingEntered = false;
		this->isIsWindowFullscreenEntered = false;
		this->isIsPlayingFemaleEntered = false;

		window.draw(this->pShapes->background);
		window.draw(this->pShapes->border);

		if (G.getClock().getElapsedTime().asMilliseconds() - this->mTimeForAnimationMenuSettingsInitializing > this->mAnimationDurationMenuSettingsInitializing) {
			window.draw(this->mIsBackgroundMusicPlayingText);
			window.draw(this->mIsWindowFullscreenText);
			window.draw(this->mIsPlayingFemaleText);

			window.draw(this->pShapes.get()->isBackgroundMusicPlayingCheckbox);
			window.draw(this->pShapes.get()->mIsPlayingFemaleCheckbox);
			window.draw(this->pShapes.get()->mIsWindowFullscreenCheckbox);
		}

		//window.draw(this->backgroundImage);
		//
		//window.draw(this->checkbox);
	}
};