#include "GuiButton.h"

GuiButton::GuiButton()
{
	mWasPressed = false;
}

void GuiButton::rm_init(ResourceManager& r)
{
	//Init the textures.
	mTexUnpressed = r.getTexture("resource/UI/PNG/blue_button07.png");
	mTexPressed = r.getTexture("resource/UI/PNG/blue_button08.png");

	//Init the internal rect.
	mRect.setTexture(mTexUnpressed);
	mRect.setSize(sf::Vector2f(50,50));
}

void GuiButton::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	target.draw(mRect, states);
}

void GuiButton::update()
{
	//Set the texture based on pressed state.
	if(isPressed())
	{
		if(!mWasPressed)
			mRect.setTexture(mTexPressed, true);
		mWasPressed = true;
	}
	else if(mWasPressed)
	{
		mRect.setTexture(mTexUnpressed, true);
		mWasPressed = false;
	}
}

bool GuiButton::isPressed()
{
	return (
		//If the mouse is pressed down &..
		KeyManager::getMouseState() == 1 &&
		//..if the mouse is inside the button boundary rect.
		mRect.getLocalBounds().contains
		(
			static_cast<sf::Vector2f> (
				KeyManager::getMousePos()
			)
		)
	);
}