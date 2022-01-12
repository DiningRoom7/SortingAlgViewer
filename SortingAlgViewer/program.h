#pragma once
#include <list>
#include "listElement.h"

class program {
public:
	program();
	~program();

	void mainLoop();
private:
	std::list<listElement> lines;
	sf::RenderWindow window;

	//Helper methods
	std::list<listElement> makeList(int numLines);
	void handleEvents();
	void drawLines();
};
