#pragma once 
#include "../main.hpp"

#include "../Core/General.hpp"
#include "../Paths.hpp"
#include "../Utils/InitializeShape.hpp"
#include "MenuSettings.hpp"

struct MouseMiniInformation {
	int x;
	int y;
	bool isLeftButtonClicked;
};

class Menu {
private:
	//std::unique_ptr<MenuSettings> menuSettings = nullptr;

	sf::RectangleShape backgroundImage;

	sf::RectangleShape playButton;
	sf::RectangleShape settingsButton;
	sf::RectangleShape exitButton;

	sf::RectangleShape playButtonBackground;
	sf::RectangleShape playButtonMask;

	sf::RectangleShape settingsButtonBackground;
	sf::RectangleShape settingsButtonMask;

	sf::RectangleShape exitButtonBackground;
	sf::RectangleShape exitButtonMask;

	const sf::Color backgroundButtonsColor = sf::Color(211, 249, 188);
	const sf::Color maskButtonsColor = sf::Color(171, 247, 124, 0.9 * 255);

	//const sf::Color maskButtonsColor = sf::Color(80, 145, 39, 0.75 * 255);

	const int spaceBetweenButtons = 30;
	const int indent = 100;

	MouseMiniInformation mouseMiniInformation;

	int numberOfMenu;

	const int animationDuration = 1000;

	bool isMouseEnteredExitButton;
	bool isMouseEnteredSettingsButton;
	bool isMouseEnteredPlayButton;
	
	std::uint32_t timeForAnimationForwardExitButton;
	std::uint32_t timeForAnimationBackExitButton;

	std::uint32_t timeForAnimationForwardSettingsButton;
	std::uint32_t timeForAnimationBackSettingsButton;

	std::uint32_t timeForAnimationForwardPlayButton;
	std::uint32_t timeForAnimationBackPlayButton;

	float playButtonMaskFilled;
	float settingsButtonMaskFilled;
	float exitButtonMaskFilled;
public:
	Menu(General& G) {
		decltype(auto) texturesManager = G.getTexturesManager();
		decltype(auto) texturesSizes = texturesManager->getTexturesSizes();
		decltype(auto) settings = G.getSettings();

		this->numberOfMenu = 0;

		this->playButtonMaskFilled = (float)0;
		this->settingsButtonMaskFilled = (float)0;
		this->exitButtonMaskFilled = (float)0;

		initializeShape(
			this->backgroundImage,
			settings.getWidthWindow(),
			settings.getHeightWindow(),
			0,
			0,
			texturesManager->getBackgroundImage() // Какой должен быть размер? SCREEN or WINDOW?
		);

		// =====

		initializeShape(
			this->exitButton,
			texturesSizes.at(paths::textures::menu::EXIT_BUTTON).first,
			texturesSizes.at(paths::textures::menu::EXIT_BUTTON).second,
			this->indent,
			settings.getHeightWindow() - (texturesSizes.at(paths::textures::menu::EXIT_BUTTON).second + this->indent),
			texturesManager->getExitButton()
		);
		initializeShape(
			this->exitButtonBackground,
			texturesSizes.at(paths::textures::menu::EXIT_BUTTON).first,
			texturesSizes.at(paths::textures::menu::EXIT_BUTTON).second,
			this->indent,
			settings.getHeightWindow() - (texturesSizes.at(paths::textures::menu::EXIT_BUTTON).second + this->indent),
			this->backgroundButtonsColor
		);
		initializeShape(
			this->exitButtonMask,
			0,
			texturesSizes.at(paths::textures::menu::EXIT_BUTTON).second,
			this->indent,
			settings.getHeightWindow() - (texturesSizes.at(paths::textures::menu::EXIT_BUTTON).second + this->indent),
			this->maskButtonsColor
		);

		// =====

		initializeShape(
			this->settingsButton,
			texturesSizes.at(paths::textures::menu::SETTINGS_BUTTON).first,
			texturesSizes.at(paths::textures::menu::SETTINGS_BUTTON).second,
			this->indent,
			settings.getHeightWindow() - (2 * texturesSizes.at(paths::textures::menu::SETTINGS_BUTTON).second + this->indent + this->spaceBetweenButtons),
			texturesManager->getSettingsButton()
		);
		initializeShape(
			this->settingsButtonBackground,
			texturesSizes.at(paths::textures::menu::SETTINGS_BUTTON).first,
			texturesSizes.at(paths::textures::menu::SETTINGS_BUTTON).second,
			this->indent,
			settings.getHeightWindow() - (2 * texturesSizes.at(paths::textures::menu::SETTINGS_BUTTON).second + this->indent + this->spaceBetweenButtons),
			this->backgroundButtonsColor
		);
		initializeShape(
			this->settingsButtonMask,
			0,
			texturesSizes.at(paths::textures::menu::SETTINGS_BUTTON).second,
			this->indent,
			settings.getHeightWindow() - (2 * texturesSizes.at(paths::textures::menu::SETTINGS_BUTTON).second + this->indent + this->spaceBetweenButtons),
			this->maskButtonsColor
		);

		// =====

		initializeShape(
			this->playButton,
			texturesSizes.at(paths::textures::menu::PLAY_BUTTON).first,
			texturesSizes.at(paths::textures::menu::PLAY_BUTTON).second,
			this->indent,
			settings.getHeightWindow() - (3 * texturesSizes.at(paths::textures::menu::PLAY_BUTTON).second + this->indent + 2 * this->spaceBetweenButtons),
			texturesManager->getPlayButton()
		);
		initializeShape(
			this->playButtonBackground,
			texturesSizes.at(paths::textures::menu::PLAY_BUTTON).first,
			texturesSizes.at(paths::textures::menu::PLAY_BUTTON).second,
			this->indent,
			settings.getHeightWindow() - (3 * texturesSizes.at(paths::textures::menu::PLAY_BUTTON).second + this->indent + 2 * this->spaceBetweenButtons),
			this->backgroundButtonsColor
		);
		initializeShape(
			this->playButtonMask,
			0,
			texturesSizes.at(paths::textures::menu::PLAY_BUTTON).second,
			this->indent,
			settings.getHeightWindow() - (3 * texturesSizes.at(paths::textures::menu::PLAY_BUTTON).second + this->indent + 2 * this->spaceBetweenButtons),
			this->maskButtonsColor
		);

		// =====

		this->mouseMiniInformation = { 0, 0, false };

		this->isMouseEnteredExitButton = false;
		this->isMouseEnteredSettingsButton = false;
		this->isMouseEnteredPlayButton = false;

		//this->indentForAnimationExitButton = this->indent;
	}

	void changeMouseMiniInformation(int x, int y, bool isLeftButtonClicked) {
		this->mouseMiniInformation = { x, y, isLeftButtonClicked };
	}

	void showMenu(General& G) {
		decltype(auto) window = G.getWindow();

		decltype(auto) texturesManager = G.getTexturesManager();
		decltype(auto) texturesSizes = texturesManager->getTexturesSizes();
		decltype(auto) settings = G.getSettings();

		this->numberOfMenu = 0;


		if (!this->isMouseEnteredExitButton) {
			this->timeForAnimationForwardExitButton = G.getClock().getElapsedTime().asMilliseconds();
		}
		if (this->isMouseEnteredExitButton) {
			this->timeForAnimationBackExitButton = G.getClock().getElapsedTime().asMilliseconds();
		}

		if (!this->isMouseEnteredSettingsButton) {
			this->timeForAnimationForwardSettingsButton = G.getClock().getElapsedTime().asMilliseconds();
		}
		if (this->isMouseEnteredSettingsButton) {
			this->timeForAnimationBackSettingsButton = G.getClock().getElapsedTime().asMilliseconds();
		}

		if (!this->isMouseEnteredPlayButton) {
			this->timeForAnimationForwardPlayButton = G.getClock().getElapsedTime().asMilliseconds();
		}
		if (this->isMouseEnteredPlayButton) {
			this->timeForAnimationBackPlayButton = G.getClock().getElapsedTime().asMilliseconds();
		}

		// EXIT BUTTON

		if (
			sf::IntRect(
				sf::Vector2i( this->indent, settings.getHeightWindow() - (texturesSizes.at(paths::textures::menu::EXIT_BUTTON).second + this->indent) ),
				sf::Vector2i( texturesSizes.at(paths::textures::menu::EXIT_BUTTON).first, texturesSizes.at(paths::textures::menu::EXIT_BUTTON).second )
			).contains(
				sf::Vector2i( this->mouseMiniInformation.x, this->mouseMiniInformation.y )
			)
		) {
			if (this->isMouseEnteredExitButton && G.getClock().getElapsedTime().asMilliseconds() - this->timeForAnimationForwardExitButton < this->animationDuration) {
				this->exitButtonMaskFilled += (float)texturesSizes.at(paths::textures::menu::EXIT_BUTTON).first / (float)this->animationDuration;

				// Control pointer of animation
				if (this->exitButtonMaskFilled > (float)texturesSizes.at(paths::textures::menu::EXIT_BUTTON).first) {
					this->exitButtonMaskFilled = (float)texturesSizes.at(paths::textures::menu::EXIT_BUTTON).first;
				}

				this->exitButtonMask.setSize(
					sf::Vector2f(
						this->exitButtonMaskFilled,
						texturesSizes.at(paths::textures::menu::EXIT_BUTTON).second
					)
				);
			}

			this->numberOfMenu = 3;

			this->isMouseEnteredExitButton = true;
		}

		if (!
			sf::IntRect(
				sf::Vector2i( this->indent, settings.getHeightWindow() - (texturesSizes.at(paths::textures::menu::EXIT_BUTTON).second + this->indent) ),
				sf::Vector2i( texturesSizes.at(paths::textures::menu::EXIT_BUTTON).first, texturesSizes.at(paths::textures::menu::EXIT_BUTTON).second )
			).contains(
				sf::Vector2i( this->mouseMiniInformation.x, this->mouseMiniInformation.y )
			)
			) {
			if (!this->isMouseEnteredExitButton && G.getClock().getElapsedTime().asMilliseconds() - this->timeForAnimationBackExitButton < this->animationDuration) {
				this->exitButtonMaskFilled -= (float)texturesSizes.at(paths::textures::menu::EXIT_BUTTON).first / (float)this->animationDuration;

				// Control pointer of animation
				if (this->exitButtonMaskFilled < (float)0) {
					this->exitButtonMaskFilled = (float)0;
				}

				this->exitButtonMask.setSize(
					sf::Vector2f(
						this->exitButtonMaskFilled,
						texturesSizes.at(paths::textures::menu::EXIT_BUTTON).second
					)
				);
			}

			this->isMouseEnteredExitButton = false;
		}

		// SETTINGS BUTTON

		if (
			sf::IntRect(
				sf::Vector2i( this->indent, settings.getHeightWindow() - (2 * texturesSizes.at(paths::textures::menu::SETTINGS_BUTTON).second + this->indent + this->spaceBetweenButtons) ),
				sf::Vector2i( texturesSizes.at(paths::textures::menu::SETTINGS_BUTTON).first, texturesSizes.at(paths::textures::menu::SETTINGS_BUTTON).second )
			).contains(
				sf::Vector2i( this->mouseMiniInformation.x, this->mouseMiniInformation.y )
			)
			) {
			if (this->isMouseEnteredSettingsButton && G.getClock().getElapsedTime().asMilliseconds() - this->timeForAnimationForwardSettingsButton < this->animationDuration) {
				this->settingsButtonMaskFilled += (float)texturesSizes.at(paths::textures::menu::SETTINGS_BUTTON).first / (float)this->animationDuration;

				// Control pointer of animation
				if (this->settingsButtonMaskFilled > (float)texturesSizes.at(paths::textures::menu::SETTINGS_BUTTON).first) {
					this->settingsButtonMaskFilled = (float)texturesSizes.at(paths::textures::menu::SETTINGS_BUTTON).first;
				}

				this->settingsButtonMask.setSize(
					sf::Vector2f(
						this->settingsButtonMaskFilled,
						texturesSizes.at(paths::textures::menu::SETTINGS_BUTTON).second
					)
				);
			}

			this->numberOfMenu = 2;

			this->isMouseEnteredSettingsButton = true;
		}

		if (!
			sf::IntRect(
				sf::Vector2i( this->indent, settings.getHeightWindow() - (2 * texturesSizes.at(paths::textures::menu::SETTINGS_BUTTON).second + this->indent + this->spaceBetweenButtons) ),
				sf::Vector2i( texturesSizes.at(paths::textures::menu::SETTINGS_BUTTON).first, texturesSizes.at(paths::textures::menu::SETTINGS_BUTTON).second )
			).contains(
				sf::Vector2i( this->mouseMiniInformation.x, this->mouseMiniInformation.y )
			)
			) {
			if (!this->isMouseEnteredSettingsButton && G.getClock().getElapsedTime().asMilliseconds() - this->timeForAnimationBackSettingsButton < this->animationDuration) {
				this->settingsButtonMaskFilled -= (float)texturesSizes.at(paths::textures::menu::SETTINGS_BUTTON).first / (float)this->animationDuration;

				// Control pointer of animation
				if (this->settingsButtonMaskFilled < (float)0) {
					this->settingsButtonMaskFilled = (float)0;
				}

				this->settingsButtonMask.setSize(
					sf::Vector2f(
						this->settingsButtonMaskFilled,
						texturesSizes.at(paths::textures::menu::SETTINGS_BUTTON).second
					)
				);
			}

			this->isMouseEnteredSettingsButton = false;
		}

		// PLAY BUTTON

		if (
			sf::IntRect(
				sf::Vector2i( this->indent, settings.getHeightWindow() - (3 * texturesSizes.at(paths::textures::menu::PLAY_BUTTON).second + this->indent + 2 * this->spaceBetweenButtons) ),
				sf::Vector2i( texturesSizes.at(paths::textures::menu::PLAY_BUTTON).first, texturesSizes.at(paths::textures::menu::PLAY_BUTTON).second )
			).contains(
				sf::Vector2i( this->mouseMiniInformation.x, this->mouseMiniInformation.y )
			)
			) {
			if (this->isMouseEnteredPlayButton && G.getClock().getElapsedTime().asMilliseconds() - this->timeForAnimationForwardPlayButton < this->animationDuration) {
				this->playButtonMaskFilled += (float)texturesSizes.at(paths::textures::menu::PLAY_BUTTON).first / (float)this->animationDuration;

				// Control pointer of animation
				if (this->playButtonMaskFilled > (float)texturesSizes.at(paths::textures::menu::PLAY_BUTTON).first) {
					this->playButtonMaskFilled = (float)texturesSizes.at(paths::textures::menu::PLAY_BUTTON).first;
				}

				this->playButtonMask.setSize(
					sf::Vector2f(
						this->playButtonMaskFilled,
						texturesSizes.at(paths::textures::menu::PLAY_BUTTON).second
					)
				);
			}

			this->numberOfMenu = 1;

			this->isMouseEnteredPlayButton = true;
		}

		if (!
			sf::IntRect(
				sf::Vector2i( this->indent, settings.getHeightWindow() - (3 * texturesSizes.at(paths::textures::menu::PLAY_BUTTON).second + this->indent + 2 * this->spaceBetweenButtons) ),
				sf::Vector2i( texturesSizes.at(paths::textures::menu::PLAY_BUTTON).first, texturesSizes.at(paths::textures::menu::PLAY_BUTTON).second )
			).contains(
				sf::Vector2i( this->mouseMiniInformation.x, this->mouseMiniInformation.y )
			)
			) {
			if (!this->isMouseEnteredPlayButton && G.getClock().getElapsedTime().asMilliseconds() - this->timeForAnimationBackPlayButton < this->animationDuration) {
				this->playButtonMaskFilled -= (float)texturesSizes.at(paths::textures::menu::PLAY_BUTTON).first / (float)this->animationDuration;

				// Control pointer of animation
				if (this->playButtonMaskFilled < (float)0) {
					this->playButtonMaskFilled = (float)0;
				}

				this->playButtonMask.setSize(
					sf::Vector2f(
						this->playButtonMaskFilled,
						texturesSizes.at(paths::textures::menu::PLAY_BUTTON).second
					)
				);
			}

			this->isMouseEnteredPlayButton = false;
		}

		if ((this->isMouseEnteredExitButton || this->isMouseEnteredSettingsButton || this->isMouseEnteredPlayButton)) { // && this->menuSettings.get() == nullptr
			// This dynamic memory or not?
			const auto cursor = sf::Cursor::createFromSystem(sf::Cursor::Type::Hand).value();
			window.setMouseCursor(cursor);
		}
		else {
			// This dynamic memory or not?
			const auto cursor = sf::Cursor::createFromSystem(sf::Cursor::Type::Arrow).value();
			window.setMouseCursor(cursor);
		}

		window.draw(backgroundImage);

		if (numberOfMenu == 3 && this->mouseMiniInformation.isLeftButtonClicked) {
			window.close();
		}

		if (numberOfMenu == 1 && this->mouseMiniInformation.isLeftButtonClicked) {
			window.close();
		}

		/*if (numberOfMenu == 2 && this->mouseMiniInformation.isLeftButtonClicked) {
			this->menuSettings.reset(new MenuSettings(G));
		} */
		
		//if (this->menuSettings.get() == nullptr) {
			window.draw(playButtonBackground);
			window.draw(settingsButtonBackground);
			window.draw(exitButtonBackground);

			window.draw(playButtonMask);
			window.draw(settingsButtonMask);
			window.draw(exitButtonMask);

			window.draw(playButton);
			window.draw(settingsButton);
			window.draw(exitButton);
		//}
		/*else {
			this->menuSettings.get()->showMenuSettings(G);
		}*/
	}
};