#pragma once

#include <SFML/Graphics.hpp>

#include "GuiComponent.h"
#include "ResourceManager.h"

class GuiButton : public GuiComponent
{
public:
	GuiButton();

private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};