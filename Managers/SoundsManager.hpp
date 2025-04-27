#pragma once
#include "../main.hpp"

#include "../Utils/Initializer.hpp"

// paths::previousDirectory BUG

class SoundsBuffersManager {
private:
	sf::SoundBuffer mEnterElementBuffer;
	sf::SoundBuffer mWalkGrassBuffer;
public:
	SoundsBuffersManager() {
		initializer::soundBufferInitialize(mEnterElementBuffer, paths::previousDirectory + paths::sounds::ENTER_ELEMENT);
		initializer::soundBufferInitialize(mWalkGrassBuffer, paths::previousDirectory + paths::sounds::WALK_GRASS);
	}

	const sf::SoundBuffer& getEnterElementBuffer() const {
		return this->mEnterElementBuffer;
	}

	const sf::SoundBuffer& getWalkGrassBuffer() const {
		return this->mWalkGrassBuffer;
	}
};

class SoundsManager {
private:
	sf::Sound mEnterElement;
	sf::Sound mWalkGrass;
public:
	SoundsManager(const SoundsBuffersManager* soundsBuffersManager) : mEnterElement(soundsBuffersManager->getEnterElementBuffer()), mWalkGrass(soundsBuffersManager->getWalkGrassBuffer()) {}

	void setSoundsVolume(int volume) {
		this->mEnterElement.setVolume(volume);
		this->mWalkGrass.setVolume(volume);
	}

	sf::Sound& getEnterElement() {
		return this->mEnterElement;
	}

	sf::Sound& getWalkGrass() {
		return this->mWalkGrass;
	}
};