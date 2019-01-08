#include "Application.h"

Application::Application() :
	mWindow(sf::VideoMode(1000,600), "Gui Testing")
{
	//Init window default values
	mWindow.setJoystickEnabled(false);
	mWindow.setFramerateLimit(60);
}

int Application::run()
{
	GuiContainer g;
	mResource.initObject(g);
	g.setPosition(25,25);

	GuiLabel sub;
	mResource.initObject(sub);
	g.addChild(&sub);
	sub.setString("hewwo!");
	sub.setCharacterSize(18);
	sub.setPosition(50,0);
	sub.updateAlignment(GuiLabel::Align::TOP_MIDDLE);

	//Main application loop
	while(mWindow.isOpen())
	{
		sf::Event event;
		while(mWindow.pollEvent(event))
		{
			switch(event.type)
			{
			default:
				break;
			case sf::Event::Closed:
				mWindow.close();
				break;
			case sf::Event::Resized:
				mWindow.setSize(sf::Vector2u(
					event.size.width,
					event.size.height
				));
				break;
			}
		}
		//UPDATES
		KeyManager::update();

		//DRAWING
		mWindow.clear(sf::Color(0x3399ff));
		mWindow.draw(g);
		mWindow.display();
	}

	return 0;
}