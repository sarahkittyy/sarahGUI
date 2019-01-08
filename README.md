# sarahGUI
I hate GUI, so one day I decided to write some elements once and for all.

Feel free to try to use it, I'm building this on linux.

~~# Note:
I changed one little bit in SFML's source before building- setJoystickEnabled(bool) in sf::Window.
There used to be a bug on windows in which polling the joystick caused the most annoying framerate stutter, but that fixed it.
No clue if it still exists, feel free to remove that call in the ```Application``` class if it is fixed.~~
It was fixed!