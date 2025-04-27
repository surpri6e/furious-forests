#pragma once 
#include "../main.hpp"

#include "../Managers/TexturesManager.hpp"
#include "../Managers/FontsManager.hpp"
#include "../Managers/SoundsManager.hpp"
#include "Settings.hpp"
#include "InputsObserver.hpp"

class General {
private:
	const std::unique_ptr<const TexturesManager> pTexturesManager = std::make_unique<TexturesManager>(TexturesManager());
	const std::unique_ptr<const FontsManager> pFontsManager = std::make_unique<FontsManager>(FontsManager());

	const std::unique_ptr<const SoundsBuffersManager> pSoundsBuffersManager = std::make_unique<SoundsBuffersManager>(SoundsBuffersManager());
	const std::unique_ptr<SoundsManager> pSoundsManager = std::make_unique<SoundsManager>(SoundsManager(pSoundsBuffersManager.get()));

	Settings& mSettings;
	InputsObserver& mInputsObserver;

	sf::RenderWindow& mWindow;
	sf::Clock mClock;
	sf::View mCamera;
public:
	General(sf::RenderWindow& window, Settings& settings, InputsObserver& inputsObserver) : mWindow(window), mSettings(settings), mInputsObserver(inputsObserver) {
		this->mWindow.setFramerateLimit(this->mSettings.getFramerateLimit());
		this->pSoundsManager.get()->setSoundsVolume(this->mSettings.getSoundsVolume());
	}

	void updateSettings() {
		this->mWindow.close();
		this->mWindow.create(
			sf::VideoMode({ (unsigned int)this->mSettings.getWidthWindow(), (unsigned int)this->mSettings.getHeightWindow() }),
			"Furious forests",
			sf::Style::Close,
			this->mSettings.getIsWindowFullscreen() ? sf::State::Fullscreen : sf::State::Windowed
		);

		this->mWindow.setFramerateLimit(this->mSettings.getFramerateLimit());
		this->pSoundsManager.get()->setSoundsVolume(this->mSettings.getSoundsVolume());
	}

	sf::View& getCamera() {
		return this->mCamera;
	}

	sf::Clock& getClock() {
		return this->mClock;
	}

	sf::RenderWindow& getWindow() {
		return this->mWindow;
	}

	Settings& getSettings() {
		return this->mSettings;
	}

	InputsObserver& getInputsObserver() {
		return this->mInputsObserver;
	}

	SoundsManager* getSoundsManager() {
		return this->pSoundsManager.get();
	}

	const TexturesManager* getTexturesManager() {
		return this->pTexturesManager.get();
	}

	const FontsManager* getFontsManager() {
		return this->pFontsManager.get();
	}
};