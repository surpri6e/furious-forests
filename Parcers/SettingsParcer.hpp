#pragma once
#include "../main.hpp"

#include "../Utils/Wrongs.hpp"

// paths::previousDirectory BUG

namespace fs = std::filesystem;

std::map<std::string, std::string> parceSettings() {
	// ѕредположим, что никто не имеет доступа к этому файлу, следовательно никто не сможет изменить его не по правилам, следовательно не возникнет лишних ошибок
	// ѕредположим, что не возникнет никаких ошибок при сохранении файла

	std::ifstream read(paths::previousDirectory + paths::saves::SETTINGS);

	std::string line = "";

	std::map<std::string, std::string> parcedSettings;

	while (std::getline(read, line)) {
		std::string elementOfSettingsInterface = "";
		std::string valueOfSettingsInterface = "";

		// I THINK SLOW ALGORITHM
		std::size_t deep = line.find(' ');

		for (std::size_t i = 0; i < deep; i++) {
			elementOfSettingsInterface.push_back(line[i]);
		}

		for (std::size_t i = deep + 1; i < line.length(); i++) {
			valueOfSettingsInterface.push_back(line[i]);
		}

		parcedSettings.insert(std::make_pair(elementOfSettingsInterface, valueOfSettingsInterface));
	}
	
	read.close();

	return parcedSettings;
}