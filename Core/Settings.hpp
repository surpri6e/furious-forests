#pragma once 
#include "../main.hpp"

#include "../Parcers/SettingsParcer.hpp"

// paths::previousDirectory BUG

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
	SettingsInterface mCurrentSettingsInterface;
	// На будущее, когда буду обрабатывать ошибки записи-чтения файлов
	SettingsInterface mDefaultSettingsInterface;
public:
	Settings() {
		this->mDefaultSettingsInterface.framerateLimit = std::make_pair("framerateLimit", 60); 
		this->mDefaultSettingsInterface.heightWindow = std::make_pair("heightWindow", consts::HEIGHT_SCREEN); 
		this->mDefaultSettingsInterface.widthWindow = std::make_pair("widthWindow", consts::WIDTH_SCREEN);
		this->mDefaultSettingsInterface.isBackgroundMusicPlaying = std::make_pair("isBackgroundMusicPlaying", true); 
		this->mDefaultSettingsInterface.isWindowFullscreen = std::make_pair("isWindowFullscreen", true); 
		this->mDefaultSettingsInterface.playerGender = std::make_pair("playerGender", MALE);

		auto parcedSettings = parceSettings();

		this->mCurrentSettingsInterface = this->mDefaultSettingsInterface;

		if (parcedSettings.empty()) {
			this->save();
		}
		else {
			this->mCurrentSettingsInterface.framerateLimit.second = std::stoi(parcedSettings[this->mCurrentSettingsInterface.framerateLimit.first]);
			this->mCurrentSettingsInterface.heightWindow.second = std::stoi(parcedSettings[this->mCurrentSettingsInterface.heightWindow.first]);
			this->mCurrentSettingsInterface.widthWindow.second = std::stoi(parcedSettings[this->mCurrentSettingsInterface.widthWindow.first]);
			this->mCurrentSettingsInterface.isBackgroundMusicPlaying.second = (bool)std::stoi(parcedSettings[this->mCurrentSettingsInterface.isBackgroundMusicPlaying.first]);
			this->mCurrentSettingsInterface.isWindowFullscreen.second = (bool)std::stoi(parcedSettings[this->mCurrentSettingsInterface.isWindowFullscreen.first]);
			this->mCurrentSettingsInterface.playerGender.second = (PlayerGender)std::stoi(parcedSettings[this->mCurrentSettingsInterface.playerGender.first]);
		}
	};

	void save() {
		// Функция гарантирует, что файл будет находиться в нужной директории и существовать

		std::ofstream write(paths::previousDirectory + paths::saves::SETTINGS, std::ios::out);

		if (!write.is_open()) {
			// Обработку закрытия каналов и прочего делать непосредственно в Wrongs
			write.close();
			Wrongs::add(WRONG_WITH_SAVE_SETTINGS);
		}
		else {
			write << this->mCurrentSettingsInterface.framerateLimit.first << " " << this->mCurrentSettingsInterface.framerateLimit.second << std::endl;
			write << this->mCurrentSettingsInterface.heightWindow.first << " " << this->mCurrentSettingsInterface.heightWindow.second << std::endl;
			write << this->mCurrentSettingsInterface.widthWindow.first << " " << this->mCurrentSettingsInterface.widthWindow.second << std::endl;
			write << this->mCurrentSettingsInterface.isBackgroundMusicPlaying.first << " " << this->mCurrentSettingsInterface.isBackgroundMusicPlaying.second << std::endl;
			write << this->mCurrentSettingsInterface.isWindowFullscreen.first << " " << this->mCurrentSettingsInterface.isWindowFullscreen.second << std::endl;
			write << this->mCurrentSettingsInterface.playerGender.first << " " << this->mCurrentSettingsInterface.playerGender.second << std::endl;
		}

		write.close();
	}

	const SettingsInterface& getDefaultSettingsInterface() {
		return this->mDefaultSettingsInterface;
	}

	void setFramerateLimit(const int framerateLimit) {
		this->mCurrentSettingsInterface.framerateLimit.second = framerateLimit;
	}
	const int getFramerateLimit() {
		return this->mCurrentSettingsInterface.framerateLimit.second;
	}

	void setWidthWindow(const int widthWindow) {
		this->mCurrentSettingsInterface.widthWindow.second = widthWindow;
	}
	const int getWidthWindow() {
		return this->mCurrentSettingsInterface.widthWindow.second;
	}

	void setHeightWindow(const int heightWindow) {
		this->mCurrentSettingsInterface.heightWindow.second = heightWindow;
	}
	const int getHeightWindow() {
		return this->mCurrentSettingsInterface.heightWindow.second;
	}

	void setIsBackgroundMusicPlaying(const bool isBackgroundMusicPlaying) {
		this->mCurrentSettingsInterface.isBackgroundMusicPlaying.second = isBackgroundMusicPlaying;
	}
	const bool getIsBackgroundMusicPlaying() {
		return this->mCurrentSettingsInterface.isBackgroundMusicPlaying.second;
	}

	void setIsWindowFullscreen(const bool isWindowFullscreen) {
		this->mCurrentSettingsInterface.isWindowFullscreen.second = isWindowFullscreen;
	}
	const bool getIsWindowFullscreen() {
		return this->mCurrentSettingsInterface.isWindowFullscreen.second;
	}

	void setPlayerGender(const PlayerGender& playerGender) {
		this->mCurrentSettingsInterface.playerGender.second = playerGender;
	}
	const PlayerGender& getPlayerGender() {
		return this->mCurrentSettingsInterface.playerGender.second;
	}
};