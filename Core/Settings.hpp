#pragma once 
#include "../main.hpp"

#include "../Parcers/SettingsParcer.hpp"
#include "../Constants.hpp"
#include "../Paths.hpp"

// Вынести в более общее место
enum PlayerGender {
	MALE,
	FEMALE
};

struct SettingsInterface {
	std::pair<std::string, int> widthWindow;
	std::pair<std::string, int> heightWindow;
	std::pair<std::string, int> framerateLimit;
	std::pair<std::string, bool> isWindowFullscreen;
	std::pair<std::string, bool> isBackgroundMusicPlaying;
	std::pair<std::string, PlayerGender> playerGender;
};

class Settings {
private:
	SettingsInterface currentSettingsInterface;
	SettingsInterface defaultSettingsInterface;
public:
	Settings() {
		this->defaultSettingsInterface.framerateLimit = std::make_pair("framerateLimit", 60); // Нужно ли выносить во внешние константы?
		this->defaultSettingsInterface.heightWindow = std::make_pair("heightWindow", consts::HEIGHT_SCREEN); 
		this->defaultSettingsInterface.widthWindow = std::make_pair("widthWindow", consts::WIDTH_SCREEN);
		this->defaultSettingsInterface.isBackgroundMusicPlaying = std::make_pair("isBackgroundMusicPlaying", true); // Нужно ли выносить во внешние константы?
		this->defaultSettingsInterface.isWindowFullscreen = std::make_pair("isWindowFullscreen", true); // Нужно ли выносить во внешние константы?
		this->defaultSettingsInterface.playerGender = std::make_pair("playerGender", MALE); // Нужно ли выносить во внешние константы?

		auto parcedSettings = parceSettings();

		this->currentSettingsInterface = this->defaultSettingsInterface;

		if (parcedSettings.empty()) {
			this->save();
		}
		else {
			this->currentSettingsInterface.framerateLimit.second = std::stoi(parcedSettings[this->currentSettingsInterface.framerateLimit.first]);
			this->currentSettingsInterface.heightWindow.second = std::stoi(parcedSettings[this->currentSettingsInterface.heightWindow.first]);
			this->currentSettingsInterface.widthWindow.second = std::stoi(parcedSettings[this->currentSettingsInterface.widthWindow.first]);
			this->currentSettingsInterface.isBackgroundMusicPlaying.second = (bool)std::stoi(parcedSettings[this->currentSettingsInterface.isBackgroundMusicPlaying.first]);
			this->currentSettingsInterface.isWindowFullscreen.second = (bool)std::stoi(parcedSettings[this->currentSettingsInterface.isWindowFullscreen.first]);
			this->currentSettingsInterface.playerGender.second = (PlayerGender)std::stoi(parcedSettings[this->currentSettingsInterface.playerGender.first]);
		}
	};

	void save() {
		// DEBUG MODE
		std::ofstream write(paths::previousDirectory + paths::saves::SETTINGS, std::ios::out);

		// Функция гарантирует, что файл будет находиться в нужной директории и существовать
		if (!write.is_open()) {
			write.close();
			Wrongs::add(WRONG_WITH_SAVE_SETTINGS);
		}
		else {
			write << this->currentSettingsInterface.framerateLimit.first << " " << this->currentSettingsInterface.framerateLimit.second << std::endl;
			write << this->currentSettingsInterface.heightWindow.first << " " << this->currentSettingsInterface.heightWindow.second << std::endl;
			write << this->currentSettingsInterface.widthWindow.first << " " << this->currentSettingsInterface.widthWindow.second << std::endl;
			write << this->currentSettingsInterface.isBackgroundMusicPlaying.first << " " << this->currentSettingsInterface.isBackgroundMusicPlaying.second << std::endl;
			write << this->currentSettingsInterface.isWindowFullscreen.first << " " << this->currentSettingsInterface.isWindowFullscreen.second << std::endl;
			write << this->currentSettingsInterface.playerGender.first << " " << this->currentSettingsInterface.playerGender.second << std::endl;
		}

		write.close();
	}

	const SettingsInterface& getDefaultSettingsInterface() {
		return this->defaultSettingsInterface;
	}

	void setFramerateLimit(const int framerateLimit) {
		this->currentSettingsInterface.framerateLimit.second = framerateLimit;
	}

	const int getFramerateLimit() {
		return this->currentSettingsInterface.framerateLimit.second;
	}

	void setWidthWindow(const int widthWindow) {
		this->currentSettingsInterface.widthWindow.second = widthWindow;
	}

	const int getWidthWindow() {
		return this->currentSettingsInterface.widthWindow.second;
	}

	void setHeightWindow(const int heightWindow) {
		this->currentSettingsInterface.heightWindow.second = heightWindow;
	}

	const int getHeightWindow() {
		return this->currentSettingsInterface.heightWindow.second;
	}

	void setIsBackgroundMusicPlaying(const bool isBackgroundMusicPlaying) {
		this->currentSettingsInterface.isBackgroundMusicPlaying.second = isBackgroundMusicPlaying;
	}

	const bool getIsBackgroundMusicPlaying() {
		return this->currentSettingsInterface.isBackgroundMusicPlaying.second;
	}

	void setIsWindowFullscreen(const bool isWindowFullscreen) {
		this->currentSettingsInterface.isWindowFullscreen.second = isWindowFullscreen;
	}

	const bool getIsWindowFullscreen() {
		return this->currentSettingsInterface.isWindowFullscreen.second;
	}

	void setPlayerGender(const PlayerGender& playerGender) {
		this->currentSettingsInterface.playerGender.second = playerGender;
	}

	const PlayerGender& getPlayerGender() {
		return this->currentSettingsInterface.playerGender.second;
	}
};