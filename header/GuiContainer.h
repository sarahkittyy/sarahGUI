#pragma once

#include <SFML/Graphics.hpp>

#include "GuiComponent.h"
#include "ResourceManager.h"

/**
 * @brief Base container class, provides an organized border to house more complex GUI elements.
 * 
 */
class GuiContainer : public GuiComponent
{
public:
	/**
	 * @brief Default Constructor
	 * 
	 */
	GuiContainer();

	/**
	 * @brief The resource initialization function.
	 * 
	 * @param r Reference to the global resource manager.
	 */
	void rm_init(ResourceManager& r);
private:

	/**
	 * @brief Override of SFML's draw() function.
	 * 
	 */
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	/**
	 * @brief The rectangle to render.
	 * 
	 */
	sf::RectangleShape mRect;

	/**
	 * @brief The texture of the rectangle.
	 * 
	 */
	sf::Texture* mTexture;
};