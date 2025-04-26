#pragma once 
#include "../main.hpp"

#include "../Core/General.hpp"
#include "../Utils/Initializer.hpp"
#include "../Utils/AnimationFiller.hpp"
#include "MenuSettings.hpp"
#include "../Utils/ModifyShapes.hpp"

// GOOD PRACTICE
struct MenuShapes {
	sf::RectangleShape backgroundImage;

	sf::RectangleShape playButton;
	sf::RectangleShape playButtonBackground;
	sf::RectangleShape playButtonMask;

	sf::RectangleShape settingsButton;
	sf::RectangleShape settingsButtonBackground;
	sf::RectangleShape settingsButtonMask;

	sf::RectangleShape exitButton;
	sf::RectangleShape exitButtonBackground;
	sf::RectangleShape exitButtonMask;
};

class Menu {
private:
	const int mSpaceBetweenButtons = 30;
	const int mIndent = 100;

	const sf::Color mBackgroundButtonsColor = sf::Color(211, 249, 188);
	const sf::Color mMaskButtonsColor = sf::Color(53, 98, 13, 0.4 * 255);

	std::unique_ptr<MenuSettings> pMenuSettings = nullptr;
	std::unique_ptr<MenuShapes> pShapes = std::make_unique<MenuShapes>();

	const int mPosYExitButton;
	const int mPosYSettingsButton;
	const int mPosYPlayButton;

	AnimationFiller mExitButtonAnimation;
	AnimationFiller mSettingsButtonAnimation;
	AnimationFiller mPlayButtonAnimation;

	sf::Sound& mEnteredElementSound;
	bool mIsPlayingSound;

	int mNumberOfMenu;

	bool mIsTimeForMenuInitializingElapsed;
	const std::uint32_t mAnimationDurationMenuInitializing = 800;
	std::uint32_t mTimeForAnimationMenuInitializing;
public:
	Menu(General& G) :
		// ALL PADDINGS IS NORMALY BECAUSE ALL BUTTONS HAS 28PX HEIGHT
		mPosYExitButton(G.getSettings().getHeightWindow() - (G.getTexturesManager()->getTexturesSizes().at(paths::textures::buttons::EXIT_BUTTON).second + this->mIndent)),
		mPosYSettingsButton(G.getSettings().getHeightWindow() - (2 * G.getTexturesManager()->getTexturesSizes().at(paths::textures::buttons::SETTINGS_BUTTON).second + this->mIndent + this->mSpaceBetweenButtons)),
		mPosYPlayButton(G.getSettings().getHeightWindow() - (3 * G.getTexturesManager()->getTexturesSizes().at(paths::textures::buttons::PLAY_BUTTON).second + this->mIndent + 2 * this->mSpaceBetweenButtons)),
		mExitButtonAnimation(
			this->pShapes.get()->exitButton,
			this->pShapes.get()->exitButtonBackground,
			this->pShapes.get()->exitButtonMask,
			{
				G.getTexturesManager()->getTexturesSizes().at(paths::textures::buttons::EXIT_BUTTON).first,
				G.getTexturesManager()->getTexturesSizes().at(paths::textures::buttons::EXIT_BUTTON).second,
				this->mIndent, // MAYBE BUG
				this->mPosYExitButton  // MAYBE BUG
			},
			G.getTexturesManager()->getExitButton(),
			this->mBackgroundButtonsColor,
			this->mMaskButtonsColor
		),
		mSettingsButtonAnimation(
			this->pShapes.get()->settingsButton,
			this->pShapes.get()->settingsButtonBackground,
			this->pShapes.get()->settingsButtonMask,
			{
				G.getTexturesManager()->getTexturesSizes().at(paths::textures::buttons::SETTINGS_BUTTON).first,
				G.getTexturesManager()->getTexturesSizes().at(paths::textures::buttons::SETTINGS_BUTTON).second,
				this->mIndent, // MAYBE BUG
				this->mPosYSettingsButton  // MAYBE BUG
			},
			G.getTexturesManager()->getSettingsButton(),
			this->mBackgroundButtonsColor,
			this->mMaskButtonsColor
		),
		mPlayButtonAnimation(
			this->pShapes.get()->playButton,
			this->pShapes.get()->playButtonBackground,
			this->pShapes.get()->playButtonMask,
			{
				G.getTexturesManager()->getTexturesSizes().at(paths::textures::buttons::PLAY_BUTTON).first,
				G.getTexturesManager()->getTexturesSizes().at(paths::textures::buttons::PLAY_BUTTON).second,
				this->mIndent, // MAYBE BUG
				this->mPosYPlayButton  // MAYBE BUG
			},
			G.getTexturesManager()->getPlayButton(),
			this->mBackgroundButtonsColor,
			this->mMaskButtonsColor
		),
		mEnteredElementSound(G.getSoundsManager()->getEnterElement())
	{
		this->mNumberOfMenu = 0;
		this->mIsPlayingSound = false;
		this->mIsTimeForMenuInitializingElapsed = false;

		this->mTimeForAnimationMenuInitializing = 0;

		initializer::shapeInitialize<int>(
			this->pShapes.get()->backgroundImage,
			{ G.getSettings().getWidthWindow(), G.getSettings().getHeightWindow(), 0, 0 }, // Какой должен быть размер? SCREEN or WINDOW?
			G.getTexturesManager()->getBackgroundImageMenu() 
		);
	}

	void show(General& G) {
		decltype(auto) window = G.getWindow();

		if (!this->mIsTimeForMenuInitializingElapsed) {
			this->mTimeForAnimationMenuInitializing = G.getClock().getElapsedTime().asMilliseconds();
		}

		bool isShowAnimation = (G.getClock().getElapsedTime().asMilliseconds() - this->mTimeForAnimationMenuInitializing > this->mAnimationDurationMenuInitializing) && this->pMenuSettings.get() == nullptr;

		bool exitButtonEntered = this->mExitButtonAnimation.showAnimation(G, isShowAnimation);
		bool settingsButtonEntered = this->mSettingsButtonAnimation.showAnimation(G, isShowAnimation);
		bool playButtonEntered = this->mPlayButtonAnimation.showAnimation(G, isShowAnimation);

		if (exitButtonEntered || settingsButtonEntered || playButtonEntered) {
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

		if (exitButtonEntered) this->mNumberOfMenu = 3;
		if (settingsButtonEntered) this->mNumberOfMenu = 2;
		if (playButtonEntered) this->mNumberOfMenu = 1;
		if (!exitButtonEntered && !settingsButtonEntered && !playButtonEntered) this->mNumberOfMenu = 0;

		if (G.getClock().getElapsedTime().asMilliseconds() - this->mTimeForAnimationMenuInitializing <= this->mAnimationDurationMenuInitializing) {
			float indentForAllButtons = (G.getClock().getElapsedTime().asMilliseconds() - this->mTimeForAnimationMenuInitializing) / (float)this->mAnimationDurationMenuInitializing * this->mIndent;

			modshapes::setPosition(
				{ std::ref(pShapes.get()->exitButton), std::ref(pShapes.get()->exitButtonBackground), std::ref(pShapes.get()->exitButtonMask) },
				indentForAllButtons, (float)(this->mPosYExitButton)
			);
		
			modshapes::setPosition(
				{ std::ref(pShapes.get()->settingsButton), std::ref(pShapes.get()->settingsButtonBackground), std::ref(pShapes.get()->settingsButtonMask) },
				indentForAllButtons, (float)(this->mPosYSettingsButton)
			);

			modshapes::setPosition(
				{ std::ref(pShapes.get()->playButton), std::ref(pShapes.get()->playButtonBackground), std::ref(pShapes.get()->playButtonMask) },
				indentForAllButtons, (float)(this->mPosYPlayButton)
			);
		
			this->mIsTimeForMenuInitializingElapsed = true;
		}
		else {
			modshapes::setPosition(
				{ std::ref(pShapes.get()->exitButton), std::ref(pShapes.get()->exitButtonBackground), std::ref(pShapes.get()->exitButtonMask) }, this->mIndent, this->mPosYExitButton
			);

			modshapes::setPosition(
				{ std::ref(pShapes.get()->settingsButton), std::ref(pShapes.get()->settingsButtonBackground), std::ref(pShapes.get()->settingsButtonMask) }, this->mIndent, this->mPosYSettingsButton
			);

			modshapes::setPosition(
				{ std::ref(pShapes.get()->playButton), std::ref(pShapes.get()->playButtonBackground), std::ref(pShapes.get()->playButtonMask) }, this->mIndent, this->mPosYPlayButton
			);
		}

		window.draw(this->pShapes.get()->backgroundImage);

		if (this->mNumberOfMenu == 3 && G.getInputsObserver().getIsLeftMouseButtonPressed()) {
			window.close();
		}

		if (this->mNumberOfMenu == 2 && G.getInputsObserver().getIsLeftMouseButtonPressed()) {
			this->pMenuSettings.reset(new MenuSettings(G));
		}

		if (this->mNumberOfMenu == 1 && G.getInputsObserver().getIsLeftMouseButtonPressed()) {
			std::cout << "START GAME" << std::endl;
		}
		
		if (this->pMenuSettings.get() == nullptr) {
			window.draw(this->pShapes.get()->playButtonBackground);
			window.draw(this->pShapes.get()->settingsButtonBackground);
			window.draw(this->pShapes.get()->exitButtonBackground);

			window.draw(this->pShapes.get()->playButtonMask);
			window.draw(this->pShapes.get()->settingsButtonMask);
			window.draw(this->pShapes.get()->exitButtonMask);

			window.draw(this->pShapes.get()->playButton);
			window.draw(this->pShapes.get()->settingsButton);
			window.draw(this->pShapes.get()->exitButton);
		}
		else {
			this->pMenuSettings.get()->show(G);
		}
	}
};