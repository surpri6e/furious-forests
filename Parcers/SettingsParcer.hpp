#pragma once
#include "../main.hpp"

#include "../Paths.hpp"
#include "../Constants.hpp"
#include "../Utils/Wrongs.hpp"

namespace fs = std::filesystem;

enum SettingsInterface {
	WIDTH_WINDOW,
	HEIGHT_WINDOW,
	FRAMERATE_LIMIT,
	IS_WINDOW_FULLSCREEN,
	IS_BACKGROUND_MUSIC_PLAYING,
	PLAYER_GENDER,
};

void setDefaultSettings(std::ofstream& draw) {
	draw << std::to_string(consts::WIDTH_SCREEN) << std::endl;
	draw << std::to_string(consts::HEIGHT_SCREEN) << std::endl;
	draw << "60" << std::endl;
	draw << "TRUE" << std::endl;
	draw << "TRUE" << std::endl;
	draw << "MALE" << std::endl;
}

std::map<SettingsInterface, std::string> parceSettings() {
	std::ofstream draw;
	std::ifstream read;

	// DEBUG MODE
	if (!fs::exists(paths::previousDirectory + paths::saves::SETTINGS)) {
		draw.open(paths::previousDirectory + paths::saves::SETTINGS);

		if (!draw.is_open()) {
			draw.close();
			Wrongs::add(WRONG_WITH_OPEN_SETTINGS);
		}
		else {
			setDefaultSettings(draw);
		}
	}

	// ѕредположим, что никто не имеет доступа к этому файлу, следовательно никто не сможет изменить его не по правилам, следовательно не возникнет лишних ошибок
	// ѕредположим, что не возникнет никаких ошибок при сохранении файла

	// DEBUG MODE
	read.open(paths::previousDirectory + paths::saves::SETTINGS);

	int counter = 0;
	std::string line = "";

	std::map<SettingsInterface, std::string> parcedSettings;

	while (std::getline(read, line)) {
		parcedSettings.insert(std::make_pair((SettingsInterface)counter, line));
		counter++;
	}
	
	read.close();
	draw.close();

	return parcedSettings;
}