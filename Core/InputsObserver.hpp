#pragma once 
#include "../main.hpp"

class InputsObserver {
private: 
	bool mIsLeftMouseButtonPressed;
	bool mIsRightMouseButtonPressed;

	int mMousePositionX;
	int mMousePositionY;

	bool mIsWPressed;
	bool mIsAPressed;
	bool mIsSPressed;
	bool mIsDPressed;

	bool mIsEPressed;

	bool mIsEscapePressed;
	bool mIsEnterPressed;
public: 
	InputsObserver() {
		this->mIsLeftMouseButtonPressed = false;
		this->mIsRightMouseButtonPressed = false;

		this->mMousePositionX = 0;
		this->mMousePositionY = 0;

		this->mIsWPressed = false;
		this->mIsAPressed = false;
		this->mIsSPressed = false;
		this->mIsDPressed = false;

		this->mIsEPressed = false;

		this->mIsEscapePressed = false;
		this->mIsEnterPressed = false;
	}

	void setIsLeftMouseButtonPressed(const bool isLeftMouseButtonPressed) {
		this->mIsLeftMouseButtonPressed = isLeftMouseButtonPressed;
	}
	const bool getIsLeftMouseButtonPressed() {
		return this->mIsLeftMouseButtonPressed;
	}

	void setIsRightMouseButtonPressed(const bool isRightMouseButtonPressed) {
		this->mIsRightMouseButtonPressed = isRightMouseButtonPressed;
	}
	const bool getIsRightMouseButtonPressed() {
		return this->mIsRightMouseButtonPressed;
	}

	void setMousePositionX(const int mousePositionX) {
		this->mMousePositionX = mousePositionX;
	}
	const int getMousePositionX() {
		return this->mMousePositionX;
	}

	void setMousePositionY(const int mousePositionY) {
		this->mMousePositionY = mousePositionY;
	}
	const int getMousePositionY() {
		return this->mMousePositionY;
	}

	// W
	void setIsWPressed(const bool isWPressed) {
		this->mIsWPressed = isWPressed;
	}
	const bool getIsWPressed() {
		return this->mIsWPressed;
	}

	// A
	void setIsAPressed(const bool isAPressed) {
		this->mIsAPressed = isAPressed;
	}
	const bool getIsAPressed() {
		return this->mIsAPressed;
	}

	// S
	void setIsSPressed(const bool isSPressed) {
		this->mIsSPressed = isSPressed;
	}
	const bool getIsSPressed() {
		return this->mIsSPressed;
	}

	// D
	void setIsDPressed(const bool isDPressed) {
		this->mIsDPressed = isDPressed;
	}
	const bool getIsDPressed() {
		return this->mIsDPressed;
	}

	// E
	void setIsEPressed(const bool isEPressed) {
		this->mIsEPressed = isEPressed;
	}
	const bool getIsEPressed() {
		return this->mIsEPressed;
	}

	// Escape
	void setIsEscapePressed(const bool isEscapePressed) {
		this->mIsEscapePressed = isEscapePressed;
	}
	const bool getIsEscapePressed() {
		return this->mIsEscapePressed;
	}

	// Enter
	void setIsEnterPressed(const bool isEnterPressed) {
		this->mIsEnterPressed = isEnterPressed;
	}
	const bool getIsEnterPressed() {
		return this->mIsEnterPressed;
	}
};