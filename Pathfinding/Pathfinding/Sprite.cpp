#include "Sprite.h"

tx::Sprite::Sprite()
{
}

tx::Sprite::Sprite(std::string aTextureLocation, tz::Vector2f& aPos)
{
	myTextureLocation = aTextureLocation;
	myPos = aPos;
}

tx::Sprite::Sprite(sf::Sprite& aSprite)
{
	mySprite = aSprite;
	myLoadedFlag = true;
	myTextureWidth = aSprite.getTextureRect().width;
	myTextureHeight = aSprite.getTextureRect().height;
}

tx::Sprite::~Sprite()
{
}

void tx::Sprite::LoadTexture(tz::Vector2f aScale = tz::Vector2f(1.0f, 1.0f))
{
	if (myTextureLocation != "" && !myLoadedFlag)
	{
		myTexture.loadFromFile(myTextureLocation);
		mySprite = sf::Sprite(myTexture);
		mySprite.setPosition(sf::Vector2f(myPos.X, myPos.Y));
		std::cout << "Loaded in texture: " << myTextureLocation << std::endl;

		if (aScale.X != 1.0f && aScale.Y != 1.0f) 
		{
			mySprite.setScale(sf::Vector2f(aScale.X, aScale.Y));
		}
		myTextureWidth = mySprite.getTextureRect().width;
		myTextureHeight = mySprite.getTextureRect().height;

		myLoadedFlag = true;
	}
}

void tx::Sprite::SetAnimation(int someColumns, int someRows)
{
}

void tx::Sprite::UpdateAnimation()
{
}

sf::Sprite& tx::Sprite::GetSprite()
{
	return mySprite;
}

tz::Vector2f tx::Sprite::GetPosition()
{
	return myPos;
}

tz::Vector2f tx::Sprite::GetScale()
{
	return myScale;
}

std::string tx::Sprite::GetTextureLocation()
{
	return myTextureLocation;
}

sf::IntRect tx::Sprite::GetFrame()
{
	if (myLoadedFlag && !myAnimationFlag)
	{
		return mySprite.getTextureRect();
	}
	else if (myLoadedFlag && myAnimationFlag)
	{
		return myFrames[myCurrentFrame];
	}

	return sf::IntRect();
}

void tx::Sprite::SetScale(tz::Vector2f aScale)
{
	if (myLoadedFlag) 
	{
		mySprite.setScale(sf::Vector2f(aScale.X, aScale.Y));
	}
	myScale = aScale;
}

void tx::Sprite::SetPosition(tz::Vector2f& aPos)
{
	mySprite.setPosition(sf::Vector2f(aPos.X, aPos.Y));
}

void tx::Sprite::Draw(sf::RenderWindow& aWindow)
{
	aWindow.draw(mySprite);
}
