#pragma once 
#include "../main.hpp"

#include "../Paths.hpp"
#include "../Constants.hpp"
#include "Wrongs.hpp"

template<typename T>
struct ShapeNumbers {
	T width;
	T height;
	T posX;
	T posY;
};

namespace initializer {
	void textureInitialize(sf::Texture& texture, const std::string& pathToTexture) {
		if (!texture.loadFromFile(pathToTexture)) {
			Wrongs::add(WRONG_WITH_INITIALIZE_TEXTURE);
		}
		else {
			std::cout << consts::others::DIVIDING_LINE << " TEXTURE INITIALIZE CORRECT " << consts::others::DIVIDING_LINE << pathToTexture << std::endl;
		}
	}

	void fontInitialize(sf::Font& font, const std::string& pathToFont) {
		if (!font.openFromFile(pathToFont)) {
			Wrongs::add(WRONG_WITH_INITIALIZE_FONT);
		}
		else {
			std::cout << consts::others::DIVIDING_LINE << " FONT INITIALIZE CORRECT " << consts::others::DIVIDING_LINE << pathToFont << std::endl;
		}
	}

	void soundBufferInitialize(sf::SoundBuffer& soundBuffer, const std::string& pathToSoundBuffer) {
		if (!soundBuffer.loadFromFile(pathToSoundBuffer)) {
			Wrongs::add(WRONG_WITH_INITIALIZE_SOUND_BUFFER);
		}
		else {
			std::cout << consts::others::DIVIDING_LINE << " SOUND BUFFER INITIALIZE CORRECT " << consts::others::DIVIDING_LINE << pathToSoundBuffer << std::endl;
		}
	}

	template<typename T>
	void shapeInitialize(sf::RectangleShape& shape, const ShapeNumbers<T>& numbers, const sf::Texture& texture) {
		shape.setSize(sf::Vector2f((float)numbers.width, (float)numbers.height));
		shape.setPosition(sf::Vector2f((float)numbers.posX, (float)numbers.posY));
		shape.setTexture(&texture);
	};

	template<typename T>
	void shapeInitialize(sf::RectangleShape& shape, const ShapeNumbers<T>& numbers, const sf::Color& color) {
		shape.setSize(sf::Vector2f((float)numbers.width, (float)numbers.height));
		shape.setPosition(sf::Vector2f((float)numbers.posX, (float)numbers.posY));
		shape.setFillColor(color);
	};
}