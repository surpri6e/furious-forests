#pragma once 
#include "../main.hpp"

#include "../Core/General.hpp"
#include "../Utils/Initializer.hpp"
#include "../Utils/AnimationFiller.hpp"
#include "MenuSettings.hpp"
#include "../Utils/ModifyShapes.hpp"


// Для анимации при старте меню, когда нужно будет двигат сразу 3 спрайта сделать функцию основанную на reference_wrapper

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

	AnimationFiller mExitButtonAnimation;
	AnimationFiller mSettingsButtonAnimation;
	AnimationFiller mPlayButtonAnimation;

	int mNumberOfMenu;

	bool mIsMenuInitialazed;
	const std::uint32_t mAnimationDurationMenuInitializing = 500;
	std::uint32_t mTimeForAnimationMenuInitializing;

	// можно просто в функцию вынести, зачем оно тут?
	bool mIsShowCursorButtons;
public:
	Menu(General& G) :
		mExitButtonAnimation(pShapes.get()->exitButton,
			pShapes.get()->exitButtonBackground,
			pShapes.get()->exitButtonMask,
			{
				G.getTexturesManager()->getTexturesSizes().at(paths::textures::buttons::EXIT_BUTTON).first,
				G.getTexturesManager()->getTexturesSizes().at(paths::textures::buttons::EXIT_BUTTON).second,
				this->mIndent, // MAYBE BUG
				G.getSettings().getHeightWindow() - (G.getTexturesManager()->getTexturesSizes().at(paths::textures::buttons::EXIT_BUTTON).second + mIndent)  // MAYBE BUG
			},
			G.getTexturesManager()->getExitButton(),
			mBackgroundButtonsColor,
			mMaskButtonsColor
		),
		mSettingsButtonAnimation(pShapes.get()->settingsButton,
			pShapes.get()->settingsButtonBackground,
			pShapes.get()->settingsButtonMask,
			{
				G.getTexturesManager()->getTexturesSizes().at(paths::textures::buttons::SETTINGS_BUTTON).first,
				G.getTexturesManager()->getTexturesSizes().at(paths::textures::buttons::SETTINGS_BUTTON).second,
				this->mIndent, // MAYBE BUG
				G.getSettings().getHeightWindow() - (2 * G.getTexturesManager()->getTexturesSizes().at(paths::textures::buttons::SETTINGS_BUTTON).second + this->mIndent + this->mSpaceBetweenButtons)  // MAYBE BUG
			},
			G.getTexturesManager()->getSettingsButton(),
			mBackgroundButtonsColor,
			mMaskButtonsColor
		),
		mPlayButtonAnimation(pShapes.get()->playButton,
			pShapes.get()->playButtonBackground,
			pShapes.get()->playButtonMask,
			{
				G.getTexturesManager()->getTexturesSizes().at(paths::textures::buttons::PLAY_BUTTON).first,
				G.getTexturesManager()->getTexturesSizes().at(paths::textures::buttons::PLAY_BUTTON).second,
				this->mIndent, // MAYBE BUG
				G.getSettings().getHeightWindow() - (3 * G.getTexturesManager()->getTexturesSizes().at(paths::textures::buttons::PLAY_BUTTON).second + this->mIndent + 2 * this->mSpaceBetweenButtons)  // MAYBE BUG
			},
			G.getTexturesManager()->getPlayButton(),
			mBackgroundButtonsColor,
			mMaskButtonsColor
		)
	{
		this->mNumberOfMenu = 0;
		this->mIsMenuInitialazed = false;

		initializer::shapeInitialize<int>(
			this->pShapes.get()->backgroundImage,
			{ G.getSettings().getWidthWindow(), G.getSettings().getHeightWindow(), 0, 0 },
			G.getTexturesManager()->getBackgroundImageMenu() // Какой должен быть размер? SCREEN or WINDOW?
		);
	}

	void showMenu(General& G) {
		decltype(auto) window = G.getWindow();

		bool isShowAnimation = G.getClock().getElapsedTime().asMilliseconds() - this->mTimeForAnimationMenuInitializing >= this->mAnimationDurationMenuInitializing;


		// ТУТ ДЕЛАТЬ НОМЕР МЕНЮ 0 

		bool exitButtonEntered = this->mExitButtonAnimation.showAnimation(G, this->mIsShowCursorButtons, isShowAnimation);
		bool settingsButtonEntered = this->mSettingsButtonAnimation.showAnimation(G, this->mIsShowCursorButtons, isShowAnimation);
		bool playButtonEntered = this->mPlayButtonAnimation.showAnimation(G, this->mIsShowCursorButtons, isShowAnimation);

		if (exitButtonEntered || settingsButtonEntered || playButtonEntered) {
			this->mIsShowCursorButtons = true;
		}
		else {
			this->mIsShowCursorButtons = false;
		}

		if (exitButtonEntered) this->mNumberOfMenu = 3;
		if (settingsButtonEntered) {
			this->mNumberOfMenu = 2;
			/*G.getSoundsManager()->getEnterElement().setVolume(100);
			G.getSoundsManager()->getEnterElement().play();*/
		};

		if (playButtonEntered) this->mNumberOfMenu = 1;
		if (!exitButtonEntered && !settingsButtonEntered && !playButtonEntered) this->mNumberOfMenu = 0;

		if (!this->mIsMenuInitialazed) {
			this->mTimeForAnimationMenuInitializing = G.getClock().getElapsedTime().asMilliseconds();
		}

		// HOW I NEED WORK WIN FLOAT AND INT HERE???
		// ALL PADDINGS IS NORMALY BECAUSE ALL BUTTONS HAS 28PX HEIGHT
		if (G.getClock().getElapsedTime().asMilliseconds() - this->mTimeForAnimationMenuInitializing <= this->mAnimationDurationMenuInitializing) {
			modshapes::changePosition(
				{ std::ref(pShapes.get()->playButton), std::ref(pShapes.get()->playButtonBackground), std::ref(pShapes.get()->playButtonMask) },
				(G.getClock().getElapsedTime().asMilliseconds() - this->mTimeForAnimationMenuInitializing) / (float)this->mAnimationDurationMenuInitializing * this->mIndent,
				(float)(G.getSettings().getHeightWindow() - (3 * G.getTexturesManager()->getTexturesSizes().at(paths::textures::buttons::PLAY_BUTTON).second + this->mIndent + 2 * this->mSpaceBetweenButtons))
			);

			modshapes::changePosition(
				{ std::ref(pShapes.get()->settingsButton), std::ref(pShapes.get()->settingsButtonBackground), std::ref(pShapes.get()->settingsButtonMask) },
				(G.getClock().getElapsedTime().asMilliseconds() - this->mTimeForAnimationMenuInitializing) / (float)this->mAnimationDurationMenuInitializing * this->mIndent,
				(float)(G.getSettings().getHeightWindow() - (2 * G.getTexturesManager()->getTexturesSizes().at(paths::textures::buttons::SETTINGS_BUTTON).second + this->mIndent + this->mSpaceBetweenButtons))
			);

			modshapes::changePosition(
				{ std::ref(pShapes.get()->exitButton), std::ref(pShapes.get()->exitButtonBackground), std::ref(pShapes.get()->exitButtonMask) },
				(G.getClock().getElapsedTime().asMilliseconds() - this->mTimeForAnimationMenuInitializing) / (float)this->mAnimationDurationMenuInitializing * this->mIndent,
				(float)(G.getSettings().getHeightWindow() - (G.getTexturesManager()->getTexturesSizes().at(paths::textures::buttons::EXIT_BUTTON).second + mIndent))
			);

			this->mIsMenuInitialazed = true;
		}
		else {
			// Конечные значения для кнопок
			modshapes::changePosition(
				{ std::ref(pShapes.get()->playButton), std::ref(pShapes.get()->playButtonBackground), std::ref(pShapes.get()->playButtonMask) },
				(float)this->mIndent,
				(float)(G.getSettings().getHeightWindow() - (3 * G.getTexturesManager()->getTexturesSizes().at(paths::textures::buttons::PLAY_BUTTON).second + this->mIndent + 2 * this->mSpaceBetweenButtons))
			);

			modshapes::changePosition(
				{ std::ref(pShapes.get()->settingsButton), std::ref(pShapes.get()->settingsButtonBackground), std::ref(pShapes.get()->settingsButtonMask) },
				(float)this->mIndent,
				(float)(G.getSettings().getHeightWindow() - (2 * G.getTexturesManager()->getTexturesSizes().at(paths::textures::buttons::SETTINGS_BUTTON).second + this->mIndent + this->mSpaceBetweenButtons))
			);

			modshapes::changePosition(
				{ std::ref(pShapes.get()->exitButton), std::ref(pShapes.get()->exitButtonBackground), std::ref(pShapes.get()->exitButtonMask) },
				(float)this->mIndent,
				(float)(G.getSettings().getHeightWindow() - (G.getTexturesManager()->getTexturesSizes().at(paths::textures::buttons::EXIT_BUTTON).second + mIndent))
			);
		}


		window.draw(this->pShapes.get()->backgroundImage);

		if (this->mNumberOfMenu == 3 && G.getInputsObserver().getIsLeftMouseButtonPressed()) {
			window.close();
		}

		if (this->mNumberOfMenu == 2 && G.getInputsObserver().getIsLeftMouseButtonPressed()) {
			//this->menuSettings.reset(new MenuSettings(G));
			std::cout << "Settings" << std::endl;
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
			//this->pMenuSettings.get()->showMenuSettings(G);
		}
	}
};