#pragma once 
#include "../main.hpp"

#include "../Core/General.hpp"
#include "../Utils/Initializer.hpp"

class AnimationFiller {
private:
	bool mIsMouseEntered;

	std::uint32_t mTimeForAnimationForward;
	std::uint32_t mTimeForAnimationBack;

	sf::RectangleShape& mElement;
	sf::RectangleShape& mElementBackground;
	sf::RectangleShape& mElementMask;

	const int mWidth;
	const int mHeight;

	const int mPosX;
	const int mPosY;

	const std::uint32_t mAnimationDuration;

	float mWidthMask;
public:
	AnimationFiller(
		sf::RectangleShape& element,
		sf::RectangleShape& elementBackground,
		sf::RectangleShape& elementMask,
		const ShapeNumbers<int>& numbers,
		const sf::Texture& texture,
		const sf::Color& backgroundButtonColor,
		const sf::Color& maskButtonColor,
		const std::uint32_t animationDuration = 300
	) :	
		mElement(element), 
		mElementBackground(elementBackground), 
		mElementMask(elementMask), 
		mWidth(numbers.width),
		mHeight(numbers.height),
		mPosX(numbers.posX),
		mPosY(numbers.posY),
		mAnimationDuration(animationDuration) 
	{
		this->mIsMouseEntered = false;
		this->mWidthMask = 0;

		this->mTimeForAnimationForward = 0;
		this->mTimeForAnimationBack = 0;

		initializer::shapeInitialize(
			this->mElement,
			numbers,
			texture
		);

		initializer::shapeInitialize(
			this->mElementBackground,
			numbers,
			backgroundButtonColor
		);

		initializer::shapeInitialize<int>(
			this->mElementMask,
			{ 0, this->mHeight, this->mPosX, this->mPosY },
			maskButtonColor
		);
	}

	// HOW I NEED WORK WIN FLOAT AND INT HERE???
	bool showAnimation(General& G, const bool isShow = true) {
		if (!isShow) return false;

		decltype(auto) inputsObserver = G.getInputsObserver();

		if (!this->mIsMouseEntered) {
			this->mTimeForAnimationForward = G.getClock().getElapsedTime().asMilliseconds();
		}
		if (this->mIsMouseEntered) {
			this->mTimeForAnimationBack = G.getClock().getElapsedTime().asMilliseconds();
		}

		bool mouseOver = sf::IntRect(sf::Vector2i(this->mPosX, this->mPosY), sf::Vector2i(this->mWidth, this->mHeight)).contains(sf::Vector2i(inputsObserver.getMousePositionX(), inputsObserver.getMousePositionY()));

		if (!mouseOver) {
			if (!this->mIsMouseEntered && G.getClock().getElapsedTime().asMilliseconds() - this->mTimeForAnimationBack <= this->mAnimationDuration + 20) { // 20 - something constant
				float progress = (G.getClock().getElapsedTime().asMilliseconds() - this->mTimeForAnimationBack) / (float)this->mAnimationDuration;

				this->mElementMask.setSize(
					sf::Vector2f(
						std::max(this->mWidthMask - (this->mWidth * progress), (float)0),
						(float)this->mHeight
					)
				);
			}

			if (this->mIsMouseEntered) {
				this->mWidthMask = this->mElementMask.getSize().x;
			}

			this->mIsMouseEntered = false;
		}

		if (mouseOver) {
			if (this->mIsMouseEntered && G.getClock().getElapsedTime().asMilliseconds() - this->mTimeForAnimationForward <= this->mAnimationDuration + 20) { // 20 - something constant
				float progress = (G.getClock().getElapsedTime().asMilliseconds() - this->mTimeForAnimationForward) / (float)this->mAnimationDuration;

				this->mElementMask.setSize(
					sf::Vector2f(
						std::min(this->mWidthMask + this->mWidth * progress, (float)this->mWidth),
						(float)this->mHeight
					)
				);
			}

			if (!this->mIsMouseEntered) {
				this->mWidthMask = this->mElementMask.getSize().x;
			}

			this->mIsMouseEntered = true;
		}
		
		return this->mIsMouseEntered;
	}
};
