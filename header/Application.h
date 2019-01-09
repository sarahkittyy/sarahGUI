#pragma once

#include <SFML/Graphics.hpp>

#include "ResourceManager.h"
#include "KeyManager.h"

#include "GuiComponent.h"
#include "GuiContainer.h"
#include "GuiLabel.h"
#include "GuiButton.h"

/**
 * @brief Class to store all application data.
 * 
 */
class Application
{
public:
	/**
	 * @brief Default Constructor
	 * 
	 */
	Application();

	/**
	 * @brief The main application loop.
	 * 
	 * @return int The program's exit code.
	 */
	int run();

private:
	/**
	 * @brief The host application window
	 * 
	 */
	sf::RenderWindow mWindow;

	/**
	 * @brief The global resource manager for all objects.
	 * 
	 */
	ResourceManager mResource;
};