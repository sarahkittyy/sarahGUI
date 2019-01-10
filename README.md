# sarahGUI
I hate GUI, so one day I decided to write some elements once and for all.

Written in SFML.

Feel free to try to use it, I'm building this on linux.

## Note:
All sources build into a single testing application where I test out the elements. See `Application::run()` for those. The library itself doesn't rely on `Application`, though. 

## Usage
Read `docs/html/index.html` for all methods.

### Example:
```c++
#include "ResourceManager.h"
#include "GuiContainer.h"
#include "GuiComponent.h"
#include "GuiLabel.h"

int main()
{
	ResourceManager manager;
	GuiContainer mainGui(manager);
	mainGui.setPosition(25,25); //sf::Transform//
	
	GuiLabel l(manager);
	mainGui.addChild(&l);
	l.setString("Hello!");
	l.setPosition(50,50);
	l.updateAlignment(GuiLabel::Align::MIDDLE_MIDDLE);

	//...standard SFML window code goes here....
	window.clear(sf::Color::White);
	window.draw(mainGui);
	window.display();
}
```
<img src="https://i.imgur.com/7B2qdz9.png"></img>


## Building:
Just run `make all` in the root directory to build. `make run` has target `all` and also executes the example binary located in `bin/`

SFML needs to be installed.

## Future plans:
* Windows executable build target.