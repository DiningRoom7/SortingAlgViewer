#include "program.h"
#include "settings.h"

//Constructor and destructor
program::program() {
	lines = makeList(238);
	window.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Sorting Algorithm Viewer", 7U, sf::ContextSettings(0, 0, 0));
}
program::~program() {
	
}

void program::mainLoop() {
	while (window.isOpen()) {
		window.clear();
		handleEvents();
		drawLines();
		window.display();
	}
}

void program::handleEvents() {
	sf::Event event;
	while (window.pollEvent(event)) {
		switch (event.type) {
		case (sf::Event::Closed):
			window.close();
			break;

		default:
			break;
		}
	}
}


//Private methods
std::list<listElement> program::makeList(int numLines) {
	auto lines = std::list<listElement>(numLines+1);
	for (int i = 0, xpos=5; i < numLines; i++, xpos+=5) {
		listElement e(i*3);
		e.setPos(xpos, WINDOW_HEIGHT-i*3-5);
		lines.push_back(e);
	}
	return lines;
}

void program::drawLines() {
	for (auto iter = lines.begin(); iter != lines.end(); iter++) {
		(*iter).draw(window);
	}
}