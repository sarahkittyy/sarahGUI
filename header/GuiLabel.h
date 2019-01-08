#pragma once

#include <SFML/Graphics.hpp>

#include "GuiComponent.h"
#include "ResourceManager.h"

/**
 * @brief GUI component for displaying & updating simple text.
 * 
 */
class GuiLabel : public GuiComponent
{
public:
	/**
	 * @brief Default Constructor
	 * 
	 */
	GuiLabel();

	/**
	 * @brief Alignment enum, for aligning text.
	 * 
	 */
	enum Align
	{
		TOP_LEFT,
		TOP_MIDDLE,
		TOP_RIGHT,
		MIDDLE_LEFT,
		MIDDLE_MIDDLE,
		MIDDLE_RIGHT,
		BOTTOM_LEFT,
		BOTTOM_MIDDLE,
		BOTTOM_RIGHT
	};

	/**
	 * @brief Resource initialization for initObject()
	 * 
	 * @param r The global resource manager.
	 */
	void rm_init(ResourceManager& r);

	/**
	 * @brief Set the text displayed.
	 * 
	 * @param newString The new text to show.
	 */
	void setString(std::string newString);

	/**
	 * @brief Retrieve the currently displayed text.
	 * 
	 * @return std::string The current text.
	 */
	std::string getString();

	/**
	 * @brief Set the font's character size.
	 * 
	 * @param n The new font size.
	 */
	void setCharacterSize(unsigned short n);

	/**
	 * @brief Update the alignment of the text.
	 * 
	 * @param newAlign The new alignment to configure the text to.
	 */
	void updateAlignment(Align newAlign);
private:
	/**
	 * @brief SFML's draw() override.
	 * 
	 */
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	/**
	 * @brief The internal text object.
	 * 
	 */
	sf::Text mText;

	/**
	 * @brief The font for the text.
	 * 
	 */
	sf::Font* mFont;

	/**
	 * @brief The alignment of the text.
	 * 
	 */
	Align mTextAlign;

	/**
	 * @brief The transform calculated by updateTransform().
	 * Applied to the text upon drawing.
	 * 
	 */
	sf::Transform mAlignTransform;
};