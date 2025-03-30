#pragma once
#include "../main.hpp"

namespace consts {
	const int HEIGHT_WINDOW = 1080;
	const int WIDTH_WINDOW = 1920;

	namespace signs {
		const std::string EMPTY = "0";
		const std::string PLAYER = "3";

		namespace rocks {
			const std::string STANDART_ROCK = "2";
		}

		namespace grass {
			const std::string LIGHTEN_GRASS = "1";
		}

		namespace trees {
			const std::string SMALL_DARK_TREE_TOP = "4";
			const std::string SMALL_DARK_TREE_BOTTOM = "5";
		}
	}

	namespace others {
		const std::string DIVIDING_LINE = "====================";
	}
}