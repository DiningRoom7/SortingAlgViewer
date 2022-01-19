#include "program.h"
#include "settings.h"
#include <algorithm>
#include <random>
#include <iostream>

//Constructor and destructor
program::program() : programFPS(0){
	lines = makeList(239);
	window.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Sorting Algorithm Viewer", 7U, sf::ContextSettings(0, 0, 0));
	storedTimePoint = std::chrono::high_resolution_clock::now();

	font.loadFromFile("arial.ttf");
	text = sf::Text("", font);
	text.setFillColor(sf::Color::Red);
}
program::~program() {
	
}

//Initialization
std::vector<listElement> program::makeList(int numLines) {
	auto lines = std::vector<listElement>();
	for (int i = 0; i < numLines; i++) {
		listElement e(i * 3, i);
		lines.push_back(e);
	}
	return lines;
}

//Main Program Loop
void program::mainLoop() {
	std::srand(unsigned(std::time(0)));
	volatile bool run = true;
	std::thread t = std::thread(&program::shuffle, this, std::ref(lines), std::ref(run));
	while (window.isOpen()) {
		programFPS = calcFPS(storedTimePoint);
		text.setString(std::to_string(programFPS));

		window.clear();    //Clear the window
		window.draw(text);
		handleEvents();    //Hadle any events for this frame
		updateLines();     //update the list of lines
		window.display();  //draw any updates to the window
	}
	run = false;
	t.join();
}

//Every Loop
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



void program::updateLines() {
	for (auto line : lines) {
		line.draw(window);
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


//List Mutation Methods
void program::shuffle(std::vector<listElement>& vect, volatile bool& run) {
	//Not really useful, just repeatedly shuffles the vector of lines
	//Just a demonstration of vector mutation from a different thread
	while (run) {
		std::random_shuffle(vect.begin(), vect.end());
		int i = 0;
		for (auto& e : vect) {
			e.setIndex(i++);
		}
		sf::sleep(sf::milliseconds(0));
	}
}