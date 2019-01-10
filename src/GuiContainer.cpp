#include "GuiContainer.h"

GuiContainer::GuiContainer(ResourceManager& r)
{
	//Retrieve the panel texture.
	mTexture = r.getTexture("resource/UI/PNG/grey_panel.png");

	//Set the rectangle's tecture & update it's size to fit.
	mRect.setTexture(mTexture);
	mRect.setSize((sf::Vector2f)mTexture->getSize());
}

void GuiContainer::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	target.draw(mRect, states);

	//Draw all children.
	//(They'll all be translated by this->getTransform())
	for(const auto &i : mChildren)
	{
		target.draw(*i, states);
	}
}