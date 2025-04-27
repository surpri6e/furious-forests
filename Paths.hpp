#pragma once 
#include "main.hpp"

namespace paths {
	const std::string previousDirectory = "../../../";

	namespace textures {
		const std::string directoryName = "textures/";

		const std::string sizes = directoryName + "textures_sizes.txt";

		namespace menu {
			const std::string directoryName = "menu/";

			const std::string BACKGROUND_IMAGE_MENU = paths::textures::directoryName + directoryName + "background_image_menu.png";
			const std::string SETTINGS_BORDER_MENU = paths::textures::directoryName + directoryName + "settings_border_menu.png";
		}

		namespace buttons {
			const std::string directoryName = "buttons/";

			const std::string NEXT_ELEMENT_BUTTON = paths::textures::directoryName + directoryName + "next_element_button.png";
			const std::string SAVE_BUTTON = paths::textures::directoryName + directoryName + "save_button.png";
			const std::string PLAY_BUTTON = paths::textures::directoryName + directoryName + "play_button.png";
			const std::string SETTINGS_BUTTON = paths::textures::directoryName + directoryName + "settings_button.png";
			const std::string EXIT_BUTTON = paths::textures::directoryName + directoryName + "exit_button.png";
		}

		namespace players {
			const std::string directoryName = "players/";

			const std::string MALE_PLAYER = paths::textures::directoryName + directoryName + "male_player.png";
			const std::string FEMALE_PLAYER = paths::textures::directoryName + directoryName + "female_player.png";
		}

		namespace heros {
			const std::string directoryName = "heros/";

			const std::string MERCHANT_HERO = paths::textures::directoryName + directoryName + "merchant_hero.png";
		}

		namespace trees {
			const std::string directoryName = "trees/";

			const std::string SMALL_DARK_TREE = paths::textures::directoryName + directoryName + "small_dark_tree.png";

			const std::string BIG_LIGHT_TREE = paths::textures::directoryName + directoryName + "big_light_tree.png";
			const std::string BIG_DARK_TREE = paths::textures::directoryName + directoryName + "big_dark_tree.png";
		}

		namespace grass {
			const std::string directoryName = "grass/";

			const std::string LIGHT_GRASS = paths::textures::directoryName + directoryName + "light_grass.png";
		}

		namespace rocks {
			const std::string directoryName = "rocks/";

			const std::string STANDART_ROCK = paths::textures::directoryName + directoryName + "standart_rock.png";
		}

		namespace clouds {
			const std::string directoryName = "clouds/";

			const std::string SMALL_CLOUD = paths::textures::directoryName + directoryName + "small_cloud.png";
		}

		namespace icons {
			const std::string directoryName = "icons/";

			const std::string CHECKBOX_FALSE = paths::textures::directoryName + directoryName + "checkbox_false.png";
			const std::string CHECKBOX_TRUE = paths::textures::directoryName + directoryName + "checkbox_true.png";

			const std::string COIN = paths::textures::directoryName + directoryName + "coin.png";
		}

		namespace hud {
			const std::string directoryName = "hud/";

			const std::string XP_BORDER = paths::textures::directoryName + directoryName + "xp_border.png";
			const std::string XP_INSIDE = paths::textures::directoryName + directoryName + "xp_inside.png";
		}
	}

	namespace sounds {
		const std::string directoryName = "sounds/";

		const std::string ENTER_ELEMENT = directoryName + "enter_element.wav";
		const std::string WALK_GRASS = directoryName + "walk_grass.wav";
	}

	namespace musics {
		const std::string directoryName = "musics/";

		const std::string MAIN = directoryName + "main.mp3";
	}

	namespace saves {
		const std::string directoryName = "saves/";

		const std::string SETTINGS = directoryName + "settings.txt";
	}

	namespace fonts {
		const std::string directoryName = "fonts/";

		const std::string MAIN = directoryName + "Sabo-Filled.otf";
	}
}