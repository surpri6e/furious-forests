#pragma once 
#include "../main.hpp"

#include "../Parcers/SettingsParcer.hpp"
#include "General.hpp"

// paths::previousDirectory BUG

const std::vector<std::string> presetsPlayerNames = { "Danila", "Lyuda" };
const std::vector<int> presetsFramerateLimits = { 60, 120, 144 };

struct SettingsInterface {
	std::pair<std::string, bool> isWindowFullscreen;

	std::pair<std::string, int> soundsVolume;

	// On a big future
	std::pair<std::string, int> widthWindow;
	std::pair<std::string, int> heightWindow;


	std::pair<std::string, int> framerateLimit;
	std::pair<std::string, std::string> playerName;
};

class Settings {
private:
	SettingsInterface mCurrentSettingsInterface;
	// На будущее, когда буду обрабатывать ошибки записи-чтения файлов
	// SettingsInterface mDefaultSettingsInterface;
public:
	Settings() {
		this->mCurrentSettingsInterface.framerateLimit = std::make_pair("framerateLimit", 60); 

		this->mCurrentSettingsInterface.heightWindow = std::make_pair("heightWindow", consts::HEIGHT_SCREEN);
		this->mCurrentSettingsInterface.widthWindow = std::make_pair("widthWindow", consts::WIDTH_SCREEN);

		this->mCurrentSettingsInterface.soundsVolume = std::make_pair("soundsVolume", 100);
		this->mCurrentSettingsInterface.isWindowFullscreen = std::make_pair("isWindowFullscreen", true);

		this->mCurrentSettingsInterface.playerName = std::make_pair("playerName", "Danila");

		auto parcedSettings = parceSettings();

		if (parcedSettings.empty()) {
			this->save(this->mCurrentSettingsInterface);
		}
		else {
			this->mCurrentSettingsInterface.framerateLimit.second = std::stoi(parcedSettings[this->mCurrentSettingsInterface.framerateLimit.first]);

			this->mCurrentSettingsInterface.heightWindow.second = std::stoi(parcedSettings[this->mCurrentSettingsInterface.heightWindow.first]);
			this->mCurrentSettingsInterface.widthWindow.second = std::stoi(parcedSettings[this->mCurrentSettingsInterface.widthWindow.first]);

			this->mCurrentSettingsInterface.soundsVolume.second = std::stoi(parcedSettings[this->mCurrentSettingsInterface.soundsVolume.first]);
			this->mCurrentSettingsInterface.isWindowFullscreen.second = (bool)std::stoi(parcedSettings[this->mCurrentSettingsInterface.isWindowFullscreen.first]);

			this->mCurrentSettingsInterface.playerName.second = parcedSettings[this->mCurrentSettingsInterface.playerName.first];
		}
	};

	void save(const SettingsInterface newSettings) {
		// Функция гарантирует, что файл будет находиться в нужной директории и существовать

		std::ofstream write(paths::previousDirectory + paths::saves::SETTINGS, std::ios::out);

		if (!write.is_open()) {
			// Обработку закрытия каналов и прочего делать непосредственно в Wrongs
			write.close();
			Wrongs::add(WRONG_WITH_SAVE_SETTINGS);
		}
		else {
			write << newSettings.framerateLimit.first << " " << newSettings.framerateLimit.second << std::endl;
			write << newSettings.heightWindow.first << " " << newSettings.heightWindow.second << std::endl;
			write << newSettings.widthWindow.first << " " << newSettings.widthWindow.second << std::endl;
			write << newSettings.soundsVolume.first << " " << newSettings.soundsVolume.second << std::endl;
			write << newSettings.isWindowFullscreen.first << " " << newSettings.isWindowFullscreen.second << std::endl;
			write << newSettings.playerName.first << " " << newSettings.playerName.second << std::endl;
		}

		this->mCurrentSettingsInterface = newSettings;

		write.close();
	}

	SettingsInterface getCopySettings() {
		return this->mCurrentSettingsInterface;
	}

	const int getFramerateLimit() {
		return this->mCurrentSettingsInterface.framerateLimit.second;
	}

	const int getWidthWindow() {
		return this->mCurrentSettingsInterface.widthWindow.second;
	}

	const int getHeightWindow() {
		return this->mCurrentSettingsInterface.heightWindow.second;
	}

	const bool getSoundsVolume() {
		return this->mCurrentSettingsInterface.soundsVolume.second;
	}

	const bool getIsWindowFullscreen() {
		return this->mCurrentSettingsInterface.isWindowFullscreen.second;
	}

	const std::string getPlayerGender() {
		return this->mCurrentSettingsInterface.playerName.second;
	}
};