#pragma once 
#include "../main.hpp"

#include "../Parcers/SettingsParcer.hpp"

/*
enum SettingsInterface {
	WIDTH_WINDOW,
	HEIGHT_WINDOW,
	FRAMERATE_LIMIT,
	IS_WINDOW_FULLSCREEN,
	IS_BACKGROUND_MUSIC_PLAYING,
	PLAYER_GENDER,
};
*/

// Вынести в более общее место
enum PlayerGender {
	MALE,
	FEMALE
};

class Settings {
private:
	int widthWindow;
	int heightWindow;
	int FRAMERATE_LIMIT;
	bool isWindowFullscreen;
	bool IS_BACKGROUND_MUSIC_PLAYING;
	PlayerGender PLAYER_GENDER;
public:
	Settings() {};

	Settings(std::map<SettingsInterface, std::string>& parcedSettings) {
		this->widthWindow = std::stoi(parcedSettings[WIDTH_WINDOW]);
		this->heightWindow = std::stoi(parcedSettings[HEIGHT_WINDOW]);
		this->isWindowFullscreen = parcedSettings[IS_WINDOW_FULLSCREEN] == "TRUE" ? true : false;
	}

	int getWidthWindow() {
		return this->widthWindow;
	}

	int getHeightWindow() {
		return this->heightWindow;
	}

	bool getIsWindowFullscreen() {
		return this->isWindowFullscreen;
	}
};