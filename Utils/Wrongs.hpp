#pragma once 
#include "../main.hpp"

// ADD WRONG_WITH_OPEN_TEXTURES_SIZES IN FUTURE
// ADD WRONG_WITH_SAVE_TEXTURES_SIZES IN FUTURE

enum WrongsList {
	WRONG_WITH_INITIALIZE_TEXTURE,
	WRONG_WITH_OPEN_SETTINGS,
	WRONG_WITH_SAVE_SETTINGS,
	WRONG_WITH_INITIALIZE_FONT,
	WRONG_WITH_INITIALIZE_SOUND_BUFFER
};

std::map<WrongsList, std::string> pairsOfWrongsList = {
	{WRONG_WITH_INITIALIZE_TEXTURE, "WRONG_WITH_INITIALIZE_TEXTURE"},
	{WRONG_WITH_OPEN_SETTINGS, "WRONG_WITH_OPEN_SETTINGS"},
	{WRONG_WITH_SAVE_SETTINGS, "WRONG_WITH_SAVE_SETTINGS"},
	{WRONG_WITH_INITIALIZE_FONT, "WRONG_WITH_INITIALIZE_FONT"},
	{WRONG_WITH_INITIALIZE_SOUND_BUFFER, "WRONG_WITH_INITIALIZE_SOUND_BUFFER"}
};

std::string fromWrongsListToString(const WrongsList& wrongsList) {
	return pairsOfWrongsList[wrongsList];
}

class Wrongs {
private:
	inline static int sWrongsCounter = 0;
public:
	static void add(const WrongsList& wrongsList) {
		sWrongsCounter++;

		if (wrongsList == 0) {
			std::cerr << consts::others::DIVIDING_LINE << " " << fromWrongsListToString(wrongsList) << " " << consts::others::DIVIDING_LINE << std::endl;
			Wrongs::printWrongsCounter();
			exit(wrongsList);
		}

		if (wrongsList == 1) {
			std::cerr << consts::others::DIVIDING_LINE << " " << fromWrongsListToString(wrongsList) << " " << consts::others::DIVIDING_LINE << std::endl;
			Wrongs::printWrongsCounter();
			exit(wrongsList);
		}

		if (wrongsList == 2) {
			std::cerr << consts::others::DIVIDING_LINE << " " << fromWrongsListToString(wrongsList) << " " << consts::others::DIVIDING_LINE << std::endl;
			Wrongs::printWrongsCounter();
			exit(wrongsList);
		}

		if (wrongsList == 3) {
			std::cerr << consts::others::DIVIDING_LINE << " " << fromWrongsListToString(wrongsList) << " " << consts::others::DIVIDING_LINE << std::endl;
			Wrongs::printWrongsCounter();
			exit(wrongsList);
		}

		if (wrongsList == 4) {
			std::cerr << consts::others::DIVIDING_LINE << " " << fromWrongsListToString(wrongsList) << " " << consts::others::DIVIDING_LINE << std::endl;
			Wrongs::printWrongsCounter();
			exit(wrongsList);
		}
	}

	static void printWrongsCounter() {
		std::cout << "WRONGS COUNTER = " << sWrongsCounter << std::endl;
	}
};