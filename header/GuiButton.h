#pragma once

#include <SFML/Graphics.hpp>

#include "GuiComponent.h"
#include "ResourceManager.h"
#include "KeyManager.h"

/**
 * @brief Simple GUI Button class.
 * 
 */
class GuiButton : public GuiComponent
{
public:
	/**
	 * @brief Default Constructor.
	 * 
	 */
	GuiButton();

	/**
	 * @brief Called by the ResourceManager for initialization.
	 * 
	 * @param r The global ResourceManager.
	 */
	void rm_init(ResourceManager& r);

	/**
	 * @brief Main update function, call either by a parent object's updateRecursive() or call manually.
	 * 
	 */
	void update();

	/**
	 * @brief Get whether or not the button is being pressed.
	 * 
	 * @return true if the button is pressed. 
	 * @return false otherwise.
	 */
	bool isPressed();

private:
	/**
	 * @brief SFML's internal draw() function.
	 * 
	 */
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	/**
	 * @brief The internal rectangle to be drawn.
	 * 
	 */
	sf::RectangleShape mRect;

	/**
	 * @brief The texture when the button is pressed.
	 * 
	 */
	sf::Texture* mTexPressed;

	/**
	 * @brief The texture when the button is unpressed.
	 * 
	 */
	sf::Texture* mTexUnpressed;

	/**
	 * @brief For update(), prevents multiple repeated calls to setTexture().
	 * 
	 */
	bool mWasPressed;
};