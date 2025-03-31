#pragma once 
#include "../main.hpp"

enum WrongsInterface {
	WRONG_WITH_INITIALIZE_TEXTURE,
	WRONG_WITH_OPEN_SETTINGS
};

std::map<WrongsInterface, std::string> pairsOfWrongsInterface = {
	{WRONG_WITH_INITIALIZE_TEXTURE, "WRONG_WITH_INITIALIZE_TEXTURE"},
	{WRONG_WITH_OPEN_SETTINGS, "WRONG_WITH_OPEN_SETTINGS"},
};

std::string fromWrongsInterfaceToString(const WrongsInterface& wrongsInterface) {
	return pairsOfWrongsInterface[wrongsInterface];
}

class Wrongs {
private:
	inline static int wrongsCounter = 0;
public:
	static void add(const WrongsInterface& wrongsInterface) {
		wrongsCounter++;

		if (wrongsInterface == 0) {
			std::cerr << consts::others::DIVIDING_LINE << " " << fromWrongsInterfaceToString(wrongsInterface) << " " << consts::others::DIVIDING_LINE << std::endl;
		}

		if (wrongsInterface == 1) {
			std::cerr << consts::others::DIVIDING_LINE << " " << fromWrongsInterfaceToString(wrongsInterface) << " " << consts::others::DIVIDING_LINE << std::endl;
			Wrongs::printWrongsCounter();
			exit(wrongsInterface);
		}
	}

	static void printWrongsCounter() {
		std::cout << "WRONGS COUNTER = " << wrongsCounter << std::endl;
	}
};