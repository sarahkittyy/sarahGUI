#include "Application.h"

Application::Application() :
	mWindow(sf::VideoMode(1000,600), "Gui Testing")
{
	//Init window default values
	mWindow.setFramerateLimit(60);

	//Init KeyManager's window instance.
	KeyManager::setWindowReference(&mWindow);
}

int Application::run()
{
	GuiContainer baseGui;
	mResource.initObject(baseGui);
	baseGui.setPosition(25,25);

	GuiButton b;
	mResource.initObject(b);
	baseGui.addChild(&b);
	b.setPosition(25,25);

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
		baseGui.updateRecursive();

		//DRAWING
		mWindow.clear(sf::Color(0x3399ff));
		mWindow.draw(baseGui);
		mWindow.display();
	}

	return 0;
}