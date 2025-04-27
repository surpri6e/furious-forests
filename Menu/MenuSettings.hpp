#pragma once
#include "../main.hpp"

#include "../Core/General.hpp"
#include "../Utils/Initializer.hpp"
#include "../Utils/ModifyShapes.hpp"
#include "MenuText.hpp"
#include "../Utils/AnimationFiller.hpp"
#include "../Core/Settings.hpp"

struct MenuSettingsShapes {
	sf::RectangleShape saveButton;
	sf::RectangleShape saveButtonBackground;
	sf::RectangleShape saveButtonMask;

	sf::RectangleShape exitButton;
	sf::RectangleShape exitButtonBackground;
	sf::RectangleShape exitButtonMask;

	sf::RectangleShape border;
	sf::RectangleShape background;

	sf::RectangleShape windowFullscreenCheckbox;
	
	sf::RectangleShape nextFramerateLimitButton;
	sf::RectangleShape nextFramerateLimitButtonBackground;
	sf::RectangleShape nextFramerateLimitButtonMask;

	sf::RectangleShape nextPlayerNameButton;
	sf::RectangleShape nextPlayerNameButtonBackground;
	sf::RectangleShape nextPlayerNameButtonMask;

	sf::RectangleShape nextSoundsVolumeButton;
	sf::RectangleShape nextSoundsVolumeButtonBackground;
	sf::RectangleShape nextSoundsVolumeButtonMask;

	sf::RectangleShape prevSoundsVolumeButton;
	sf::RectangleShape prevSoundsVolumeButtonBackground;
	sf::RectangleShape prevSoundsVolumeButtonMask;
};

class MenuSettings {
private:
	std::unique_ptr<MenuSettingsShapes> pShapes = std::make_unique<MenuSettingsShapes>();

	sf::Sound& mEnteredElementSound;
	bool mIsPlayingSound;

	SettingsInterface mPreSavedSettings;

	const sf::Color mNextElementBackgroundColor = sf::Color(135, 120, 84);
	const sf::Color mNextElementMaskColor = sf::Color(64, 56, 40, 0.4 * 255);
	const sf::Color mNextElementBorderColor = sf::Color(64, 56, 40);

	const int mIndentWidth = 10;
	const int mIndentHeight = 15;
	const int mSpaceBetweenLines = 40;

	const float mWidthBackground;
	const float mHeightBackground;
	const float mPosXBackground;
	const float mPosYBackground;

	// bad
	const int mSizeOfCheckbox = 32;

	const int mSizeOfBorder;

	bool mIsTimeForMenuSettingsInitializingElapsed;
	const std::uint32_t mAnimationDurationMenuSettingsInitializing = 500;
	std::uint32_t mTimeForAnimationMenuSettingsInitializing;

	sf::Text mSoundsVolumeText;
	sf::Text mWindowFullscreenText;
	sf::Text mPlayerNameText;
	sf::Text mFramerateLimitText;

	AnimationFiller mSaveButtonAnimation;
	AnimationFiller mExitButtonAnimation;

	sf::Text mValueSoundsVolumeText;
	sf::Text mValuePlayerNameText;
	sf::Text mValueFramerateLimitText;

	AnimationFiller mNextFramerateLimitButtonAnimation;
	AnimationFiller mNextPlayerNameButtonAnimation;
	AnimationFiller mNextSoundsVolumeButtonAnimation;
	AnimationFiller mPrevSoundsVolumeButtonAnimation;

	bool mIsSetFramerateLimitOne;
	bool mIsSetPlayerNameOne;
	bool mIsSetSoundVolumeOne;
	bool mIsSetWindowFullscreenOne;
public: 
	MenuSettings(General& G) :
		mEnteredElementSound(G.getSoundsManager()->getEnterElement()),
		mPreSavedSettings(G.getSettings().getCopySettings()),
		mWidthBackground(G.getSettings().getWidthWindow() / 3),
		mHeightBackground(G.getSettings().getHeightWindow() / 1.2),
		mPosXBackground(G.getSettings().getWidthWindow() / 2 - G.getSettings().getWidthWindow() / 6),
		mPosYBackground(G.getSettings().getHeightWindow() / 2 - G.getSettings().getHeightWindow() / 2.4),
		mSizeOfBorder(16 * this->mWidthBackground / (float)(G.getTexturesManager()->getTexturesSizes().at(paths::textures::menu::SETTINGS_BORDER_MENU).first)),
		mSoundsVolumeText(menuText(G, "Sounds volume:",
			this->mPosXBackground + this->mSizeOfBorder + this->mIndentWidth,
			this->mPosYBackground + this->mSizeOfBorder + this->mIndentHeight
		)),
		mWindowFullscreenText(menuText(G, "Fullscreen:",
			this->mPosXBackground + this->mSizeOfBorder + this->mIndentWidth,
			this->mPosYBackground + this->mSizeOfBorder + this->mIndentHeight + this->mSpaceBetweenLines + 18
		)),
		mPlayerNameText(menuText(G, "Change player hero:",
			this->mPosXBackground + this->mSizeOfBorder + this->mIndentWidth,
			this->mPosYBackground + this->mSizeOfBorder + this->mIndentHeight + this->mSpaceBetweenLines * 2 + 18 * 2
		)),
		mFramerateLimitText(menuText(G, "Max FPS:",
			this->mPosXBackground + this->mSizeOfBorder + this->mIndentWidth,
			this->mPosYBackground + this->mSizeOfBorder + this->mIndentHeight + this->mSpaceBetweenLines * 3 + 18 * 3
		)),
		mExitButtonAnimation(
			this->pShapes.get()->exitButton,
			this->pShapes.get()->exitButtonBackground,
			this->pShapes.get()->exitButtonMask,
			{
				G.getTexturesManager()->getTexturesSizes().at(paths::textures::buttons::EXIT_BUTTON).first,
				G.getTexturesManager()->getTexturesSizes().at(paths::textures::buttons::EXIT_BUTTON).second,
				(int)(this->mPosXBackground + this->mWidthBackground - this->mSizeOfBorder - this->mIndentWidth - G.getTexturesManager()->getTexturesSizes().at(paths::textures::buttons::EXIT_BUTTON).first) - 150,
				(int)(this->mPosYBackground + this->mHeightBackground - this->mSizeOfBorder - this->mIndentHeight - G.getTexturesManager()->getTexturesSizes().at(paths::textures::buttons::EXIT_BUTTON).second)
			},
			G.getTexturesManager()->getExitButton(),
			sf::Color(212, 47, 55),
			sf::Color(171, 21, 33, 0.5 * 255)
		),
		mSaveButtonAnimation(
			this->pShapes.get()->saveButton,
			this->pShapes.get()->saveButtonBackground,
			this->pShapes.get()->saveButtonMask,
			{
				G.getTexturesManager()->getTexturesSizes().at(paths::textures::buttons::SAVE_BUTTON).first,
				G.getTexturesManager()->getTexturesSizes().at(paths::textures::buttons::SAVE_BUTTON).second,
				(int)(this->mPosXBackground + this->mSizeOfBorder + this->mIndentWidth) + 150,
				(int)(this->mPosYBackground + this->mHeightBackground - this->mSizeOfBorder - this->mIndentHeight - G.getTexturesManager()->getTexturesSizes().at(paths::textures::buttons::SAVE_BUTTON).second)
			},
			G.getTexturesManager()->getSaveButton(),
			sf::Color(139, 179, 30),
			sf::Color(112, 143, 26, 0.5 * 255)
		),
		mValueSoundsVolumeText(menuTextSmall(G, std::to_string(this->mPreSavedSettings.soundsVolume.second),
			this->mPosXBackground + this->mWidthBackground - this->mSizeOfBorder - this->mIndentWidth - this->mSizeOfCheckbox - 100,
			this->mPosYBackground + this->mSizeOfBorder + this->mIndentHeight + 4
		)),
		mValuePlayerNameText(menuTextSmall(G, this->mPreSavedSettings.playerName.second,
			this->mPosXBackground + this->mWidthBackground - this->mSizeOfBorder - this->mIndentWidth - this->mSizeOfCheckbox - 100,
			this->mPosYBackground + this->mSizeOfBorder + this->mIndentHeight + this->mSpaceBetweenLines * 2 + 18 * 2 + 4
		)),
		mValueFramerateLimitText(menuTextSmall(G, std::to_string(this->mPreSavedSettings.framerateLimit.second),
			this->mPosXBackground + this->mWidthBackground - this->mSizeOfBorder - this->mIndentWidth - this->mSizeOfCheckbox - 100,
			this->mPosYBackground + this->mSizeOfBorder + this->mIndentHeight + this->mSpaceBetweenLines * 3 + 18 * 3 + 4
		)),
		mNextFramerateLimitButtonAnimation(
			this->pShapes.get()->nextFramerateLimitButton,
			this->pShapes.get()->nextFramerateLimitButtonBackground,
			this->pShapes.get()->nextFramerateLimitButtonMask,
			{
				G.getTexturesManager()->getTexturesSizes().at(paths::textures::buttons::NEXT_ELEMENT_BUTTON).first,
				G.getTexturesManager()->getTexturesSizes().at(paths::textures::buttons::NEXT_ELEMENT_BUTTON).second,
				(int)(this->mPosXBackground + this->mWidthBackground - this->mSizeOfBorder - this->mIndentWidth - this->mSizeOfCheckbox),
				(int)(this->mPosYBackground + this->mSizeOfBorder + this->mIndentHeight + this->mSpaceBetweenLines * 3 + 18 * 3 - this->mSizeOfCheckbox / 4)
			},
			G.getTexturesManager()->getNextElementButton(),
			this->mNextElementBackgroundColor,
			this->mNextElementMaskColor
		),
		mNextPlayerNameButtonAnimation(
			this->pShapes.get()->nextPlayerNameButton,
			this->pShapes.get()->nextPlayerNameButtonBackground,
			this->pShapes.get()->nextPlayerNameButtonMask, 	
			{
				G.getTexturesManager()->getTexturesSizes().at(paths::textures::buttons::NEXT_ELEMENT_BUTTON).first,
				G.getTexturesManager()->getTexturesSizes().at(paths::textures::buttons::NEXT_ELEMENT_BUTTON).second,
				(int)(this->mPosXBackground + this->mWidthBackground - this->mSizeOfBorder - this->mIndentWidth - this->mSizeOfCheckbox),
				(int)(this->mPosYBackground + this->mSizeOfBorder + this->mIndentHeight + this->mSpaceBetweenLines * 2 + 18 * 2 - this->mSizeOfCheckbox / 4)
			},
			G.getTexturesManager()->getNextElementButton(),
			this->mNextElementBackgroundColor,
			this->mNextElementMaskColor
		),
		mNextSoundsVolumeButtonAnimation(
			this->pShapes.get()->nextSoundsVolumeButton,
			this->pShapes.get()->nextSoundsVolumeButtonBackground,
			this->pShapes.get()->nextSoundsVolumeButtonMask,
			{
				G.getTexturesManager()->getTexturesSizes().at(paths::textures::buttons::NEXT_ELEMENT_BUTTON).first,
				G.getTexturesManager()->getTexturesSizes().at(paths::textures::buttons::NEXT_ELEMENT_BUTTON).second,
				(int)(this->mPosXBackground + this->mWidthBackground - this->mSizeOfBorder - this->mIndentWidth - this->mSizeOfCheckbox),
				(int)(this->mPosYBackground + this->mSizeOfBorder + this->mIndentHeight - this->mSizeOfCheckbox / 4)
			},
			G.getTexturesManager()->getNextElementButton(),
			this->mNextElementBackgroundColor,
			this->mNextElementMaskColor
		),
		mPrevSoundsVolumeButtonAnimation(
			this->pShapes.get()->prevSoundsVolumeButton,
			this->pShapes.get()->prevSoundsVolumeButtonBackground,
			this->pShapes.get()->prevSoundsVolumeButtonMask,
			{
				G.getTexturesManager()->getTexturesSizes().at(paths::textures::buttons::NEXT_ELEMENT_BUTTON).first,
				G.getTexturesManager()->getTexturesSizes().at(paths::textures::buttons::NEXT_ELEMENT_BUTTON).second,
				(int)(this->mPosXBackground + this->mWidthBackground - this->mSizeOfBorder - this->mIndentWidth - this->mSizeOfCheckbox - 200),
				(int)(this->mPosYBackground + this->mSizeOfBorder + this->mIndentHeight - this->mSizeOfCheckbox / 4)
			},
			G.getTexturesManager()->getNextElementButton(),
			this->mNextElementBackgroundColor,
			this->mNextElementMaskColor
		)
	{
		decltype(auto) settings = G.getSettings();
		decltype(auto) texturesManager = G.getTexturesManager();

		this->mIsTimeForMenuSettingsInitializingElapsed = false;

		this->mTimeForAnimationMenuSettingsInitializing = 0;

		this->mIsPlayingSound = false;

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
			this->pShapes.get()->windowFullscreenCheckbox,
			{
				(float)this->mSizeOfCheckbox,
				(float)this->mSizeOfCheckbox,
				this->mPosXBackground + this->mWidthBackground - this->mSizeOfBorder - this->mIndentWidth - this->mSizeOfCheckbox,
				this->mPosYBackground + this->mSizeOfBorder + this->mIndentHeight + this->mSpaceBetweenLines + 18 - this->mSizeOfCheckbox / 4
			},
			settings.getIsWindowFullscreen() ? texturesManager->getCheckboxTrue() : texturesManager->getCheckboxFalse()
		);

		this->pShapes.get()->prevSoundsVolumeButton.setScale(sf::Vector2f(-1, 1));
		this->pShapes.get()->prevSoundsVolumeButton.setPosition(sf::Vector2f(this->pShapes.get()->prevSoundsVolumeButton.getPosition().x + this->mSizeOfCheckbox, this->pShapes.get()->prevSoundsVolumeButton.getPosition().y));


		this->pShapes.get()->nextFramerateLimitButton.setOutlineThickness(3);
		this->pShapes.get()->nextFramerateLimitButton.setOutlineColor(this->mNextElementBorderColor);

		this->pShapes.get()->nextSoundsVolumeButton.setOutlineColor(this->mNextElementBorderColor);
		this->pShapes.get()->nextSoundsVolumeButton.setOutlineThickness(3);

		this->pShapes.get()->prevSoundsVolumeButton.setOutlineColor(this->mNextElementBorderColor);
		this->pShapes.get()->prevSoundsVolumeButton.setOutlineThickness(3);

		this->pShapes.get()->nextPlayerNameButton.setOutlineColor(this->mNextElementBorderColor);
		this->pShapes.get()->nextPlayerNameButton.setOutlineThickness(3);

		this->mIsSetFramerateLimitOne = true;
		this->mIsSetPlayerNameOne = true;
		this->mIsSetSoundVolumeOne = true;
		this->mIsSetWindowFullscreenOne = true;
	}

	bool show(General& G) {
		decltype(auto) window = G.getWindow();
		decltype(auto) settings = G.getSettings();
		decltype(auto) inputsObserver = G.getInputsObserver();

		if (!this->mIsTimeForMenuSettingsInitializingElapsed) {
			this->mTimeForAnimationMenuSettingsInitializing = G.getClock().getElapsedTime().asMilliseconds();
		}

		bool isShowAnimation = G.getClock().getElapsedTime().asMilliseconds() - this->mTimeForAnimationMenuSettingsInitializing > this->mAnimationDurationMenuSettingsInitializing;

		bool exitButtonEntered = this->mExitButtonAnimation.showAnimation(G, isShowAnimation);
		bool saveButtonEntered = this->mSaveButtonAnimation.showAnimation(G, isShowAnimation);

		bool nextSoundsVolumeButtonEntered = this->mNextSoundsVolumeButtonAnimation.showAnimation(G, isShowAnimation);
		bool prevSoundsVolumeButtonEntered = this->mPrevSoundsVolumeButtonAnimation.showAnimation(G, isShowAnimation);

		bool nextPlayerNameButtonEntered = this->mNextPlayerNameButtonAnimation.showAnimation(G, isShowAnimation);
		bool nextFramerateLimitButtonEntered = this->mNextFramerateLimitButtonAnimation.showAnimation(G, isShowAnimation);

		bool checkboxWindowFullscreenEntered = 
			sf::IntRect(
				sf::Vector2i(this->mPosXBackground + this->mWidthBackground - this->mSizeOfBorder - this->mIndentWidth - this->mSizeOfCheckbox, this->mPosYBackground + this->mSizeOfBorder + this->mIndentHeight + this->mSpaceBetweenLines + 18 - this->mSizeOfCheckbox / 4),
				sf::Vector2i(this->mSizeOfCheckbox, this->mSizeOfCheckbox)).contains(sf::Vector2i(inputsObserver.getMousePositionX(), inputsObserver.getMousePositionY())
			);

		if (exitButtonEntered || saveButtonEntered || nextSoundsVolumeButtonEntered || prevSoundsVolumeButtonEntered || nextPlayerNameButtonEntered || nextFramerateLimitButtonEntered || checkboxWindowFullscreenEntered) {
			// This dynamic memory or not?
			const auto cursor = sf::Cursor::createFromSystem(sf::Cursor::Type::Hand).value();
			window.setMouseCursor(cursor);

			if (!this->mIsPlayingSound) {
				this->mIsPlayingSound = true;

				if (this->mEnteredElementSound.getStatus() != sf::SoundSource::Status::Playing) {
					this->mEnteredElementSound.play();
				}
			}
		}
		else {
			this->mIsPlayingSound = false;
			// This dynamic memory or not?
			const auto cursor = sf::Cursor::createFromSystem(sf::Cursor::Type::Arrow).value();
			window.setMouseCursor(cursor);
		}

		if (nextFramerateLimitButtonEntered && inputsObserver.getIsLeftMouseButtonPressed() && this->mIsSetFramerateLimitOne) {
			auto position = 0;

			// search
			for (auto i = 0; i < presetsFramerateLimits.size(); i++) {
				if (presetsFramerateLimits[i] == this->mPreSavedSettings.framerateLimit.second) {
					position = i;
					break;
				}
			}

			if (position + 1 == presetsFramerateLimits.size()) {
				position = 0;
			}
			else {
				position += 1;
			}

			this->mPreSavedSettings.framerateLimit.second = presetsFramerateLimits[position];
			this->mValueFramerateLimitText.setString(std::to_string(presetsFramerateLimits[position]));

			this->mIsSetFramerateLimitOne = false;
		}

		if (nextPlayerNameButtonEntered && inputsObserver.getIsLeftMouseButtonPressed() && this->mIsSetPlayerNameOne) {
			auto position = 0;

			// search
			for (auto i = 0; i < presetsPlayerNames.size(); i++) {
				if (presetsPlayerNames[i] == this->mPreSavedSettings.playerName.second) {
					position = i;
					break;
				}
			}

			if (position + 1 == presetsPlayerNames.size()) {
				position = 0;
			}
			else {
				position += 1;
			}

			this->mPreSavedSettings.playerName.second = presetsPlayerNames[position];
			this->mValuePlayerNameText.setString(presetsPlayerNames[position]);

			this->mIsSetPlayerNameOne = false;
		}

		if (nextSoundsVolumeButtonEntered && inputsObserver.getIsLeftMouseButtonPressed() && this->mIsSetSoundVolumeOne) {
			auto volume = this->mPreSavedSettings.soundsVolume.second;

			if (inputsObserver.getIsShiftPressed() && volume + 5 <= 100) {
				volume += 5;

				this->mPreSavedSettings.soundsVolume.second = volume;
				this->mValueSoundsVolumeText.setString(std::to_string(volume));
			}
			else if (volume + 1 <= 100) {
				volume += 1;

				this->mPreSavedSettings.soundsVolume.second = volume;
				this->mValueSoundsVolumeText.setString(std::to_string(volume));
			}

			this->mIsSetSoundVolumeOne = false;
		}

		if (prevSoundsVolumeButtonEntered && inputsObserver.getIsLeftMouseButtonPressed() && this->mIsSetSoundVolumeOne) {
			auto volume = this->mPreSavedSettings.soundsVolume.second;

			if (inputsObserver.getIsShiftPressed() && volume - 5 >= 0) {
				volume -= 5;

				this->mPreSavedSettings.soundsVolume.second = volume;
				this->mValueSoundsVolumeText.setString(std::to_string(volume));
			}
			else if (volume - 1 >= 0) {
				volume -= 1;

				this->mPreSavedSettings.soundsVolume.second = volume;
				this->mValueSoundsVolumeText.setString(std::to_string(volume));
			}

			this->mIsSetSoundVolumeOne = false;
		}

		if (checkboxWindowFullscreenEntered && inputsObserver.getIsLeftMouseButtonPressed() && this->mIsSetWindowFullscreenOne) {
			this->mPreSavedSettings.isWindowFullscreen.second = !this->mPreSavedSettings.isWindowFullscreen.second;
			this->pShapes.get()->windowFullscreenCheckbox.setTexture(this->mPreSavedSettings.isWindowFullscreen.second ? &G.getTexturesManager()->getCheckboxTrue() : &G.getTexturesManager()->getCheckboxFalse());

			this->mIsSetWindowFullscreenOne = false;
		}

		if (!inputsObserver.getIsLeftMouseButtonPressed()) {
			this->mIsSetFramerateLimitOne = true;
			this->mIsSetPlayerNameOne = true;
			this->mIsSetSoundVolumeOne = true;
			this->mIsSetWindowFullscreenOne = true;
		}

		if (saveButtonEntered && inputsObserver.getIsLeftMouseButtonPressed()) {
			settings.save(this->mPreSavedSettings);
			G.updateSettings();
			return true;
		}

		if (exitButtonEntered && inputsObserver.getIsLeftMouseButtonPressed()) {
			return true;
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
			window.draw(this->mWindowFullscreenText);

			window.draw(this->mSoundsVolumeText);
			window.draw(this->mPlayerNameText);
			window.draw(this->mFramerateLimitText);

			window.draw(this->mValueSoundsVolumeText);
			window.draw(this->mValuePlayerNameText);
			window.draw(this->mValueFramerateLimitText);

			window.draw(this->pShapes.get()->windowFullscreenCheckbox);

			window.draw(this->pShapes.get()->exitButtonBackground);
			window.draw(this->pShapes.get()->saveButtonBackground);
			window.draw(this->pShapes.get()->nextFramerateLimitButtonBackground);
			window.draw(this->pShapes.get()->nextSoundsVolumeButtonBackground);
			window.draw(this->pShapes.get()->nextPlayerNameButtonBackground);
			window.draw(this->pShapes.get()->prevSoundsVolumeButtonBackground);

			window.draw(this->pShapes.get()->exitButtonMask);
			window.draw(this->pShapes.get()->saveButtonMask);
			window.draw(this->pShapes.get()->nextFramerateLimitButtonMask);
			window.draw(this->pShapes.get()->nextSoundsVolumeButtonMask);
			window.draw(this->pShapes.get()->nextPlayerNameButtonMask);
			window.draw(this->pShapes.get()->prevSoundsVolumeButtonMask);

			window.draw(this->pShapes.get()->exitButton);
			window.draw(this->pShapes.get()->saveButton);
			window.draw(this->pShapes.get()->nextFramerateLimitButton);
			window.draw(this->pShapes.get()->nextSoundsVolumeButton);
			window.draw(this->pShapes.get()->nextPlayerNameButton);
			window.draw(this->pShapes.get()->prevSoundsVolumeButton);
		}

		return false;
	}
};