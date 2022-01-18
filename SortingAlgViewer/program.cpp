#include "program.h"
#include "settings.h"

//Constructor and destructor
program::program() : programFPS(0){
	lines = makeList(238);
	window.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Sorting Algorithm Viewer", 7U, sf::ContextSettings(0, 0, 0));
	storedTimePoint = std::chrono::high_resolution_clock::now();

	font.loadFromFile("arial.ttf");
	text = sf::Text("", font);
	text.setFillColor(sf::Color::Red);
}
program::~program() {
	
}

void program::mainLoop() {
	while (window.isOpen()) {
		programFPS = calcFPS(storedTimePoint);
		text.setString(std::to_string(programFPS));

		window.clear();    //Clear the window
		window.draw(text);
		handleEvents();    //Hadle any events for this frame
		updateLines();     //update the list of lines
		window.display();  //draw any updates to the window
	}
}

//Private Methods
void program::handleEvents() {
	sf::Event event;
	while (window.pollEvent(event)) {
		//Not sure if else if chain is the way to do this
		//Switch statemet was too restrictive
		if (event.type == sf::Event::Closed) window.close();
		else if (event.type == sf::Event::MouseButtonPressed) handleMouseClick();

	}
}

void program::handleMouseClick() {

}

std::vector<listElement> program::makeList(int numLines) {
	auto lines = std::vector<listElement>(numLines+1);
	for (int i = 0, xpos=5; i < numLines; i++, xpos+=5) {
		listElement e(i*3);
		e.setPos(xpos, WINDOW_HEIGHT-i*3-5);
		lines.push_back(e);
	}
	return lines;
}

void program::updateLines() {
	for (auto iter = lines.begin(); iter != lines.end(); iter++) {
		(*iter).draw(window);
	}
}

int program::calcFPS(std::chrono::time_point<std::chrono::high_resolution_clock>& stored) {
	auto tp = std::chrono::high_resolution_clock().now(); //get current time
	int nanosecs = std::chrono::duration_cast<std::chrono::nanoseconds>(tp - stored).count(); //get the nanosecond difference between stored and current time
	auto fpns = 1. / nanosecs; //fpns is type double, frames per nanosecond
	int fps = fpns / .000000001; //calculate frames per second
	stored = tp; //current time becomes stored for the next frame
	return fps;
}