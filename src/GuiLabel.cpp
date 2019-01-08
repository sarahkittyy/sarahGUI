#include "GuiLabel.h"

GuiLabel::GuiLabel()
{
	//Default alignment.
	mTextAlign = TOP_LEFT;
}

void GuiLabel::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	//Transform the 
	states.transform *= getTransform();
	states.transform *= mAlignTransform;
	target.draw(mText, states);

	//Draw all children (Text shouldn't have children?!?)
	for(auto &i : mChildren)
	{
		target.draw(*i, states);
	}
}

void GuiLabel::rm_init(ResourceManager& r)
{
	//Initialize the font, and default text settings.
	mFont = r.getFont("resource/UI/Font/kenvector_future.ttf");
	mText.setFont(*mFont);
	mText.setFillColor(sf::Color::Black);
	mText.setCharacterSize(12);
}

void GuiLabel::setString(std::string newString)
{
	//Set the string & update the alignment.
	mText.setString(newString);
	updateAlignment(mTextAlign);
}

std::string GuiLabel::getString()
{
	return mText.getString();
}

void GuiLabel::setCharacterSize(unsigned short n)
{
	mText.setCharacterSize(n);

	//Update the alignment
	updateAlignment(mTextAlign);
}

void GuiLabel::updateAlignment(Align newAlign)
{
	//Reset alignment
	mAlignTransform = sf::Transform::Identity;
	mTextAlign = newAlign;

	//Fraction of the size of the text to shift by.
	sf::Vector2f factors(0,0);

	//Switch-Case through all align values.
	switch(mTextAlign)
	{
	default:
		break;
	case TOP_LEFT:
		break;
	case TOP_MIDDLE:
		factors.x = 0.5f;
		break;
	case TOP_RIGHT:
		factors.x = 1;
		break;
	case MIDDLE_LEFT:
		factors.y = 0.5f;
		break;
	case MIDDLE_MIDDLE:
		factors.y = 0.5f;
		factors.x = 0.5f;
		break;
	case MIDDLE_RIGHT:
		factors.y = 0.5f;
		factors.x = 1;
		break;
	case BOTTOM_LEFT:
		factors.y = 1;
		break;
	case BOTTOM_MIDDLE:
		factors.y = 1;
		factors.x = 0.5f;
		break;
	case BOTTOM_RIGHT:
		factors.y = 1;
		factors.x = 1;
		break;
	}

	//Get boundaries of text, transformed.
	sf::FloatRect textBounds = getTransform().transformRect(mText.getLocalBounds());

	//Get the scaled width & height.
	sf::Vector2f scaledBounds(
		textBounds.width * factors.x,
		textBounds.height * factors.y
	);

	//Update the transform.
	mAlignTransform.translate(-scaledBounds.x, -scaledBounds.y);
}