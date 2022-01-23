#include "program.h"
#include "settings.h"
#include <algorithm>
#include <random>
#include <iostream>
#include <list>

//Constructor and destructor
program::program() : programFPS(0) {
	lines = makeList(239);
	window.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Sorting Algorithm Viewer", 7U, sf::ContextSettings(0, 0, 0));
	storedTimePoint = std::chrono::high_resolution_clock::now();

	font.loadFromFile("arial.ttf");
	text = sf::Text("", font);
	text.setFillColor(sf::Color::Red);

	UIElements = std::vector<UIButton>();
	UIEventQueue = std::queue<sf::Event>();

	UIElements.push_back(UIButton(shuffle,
								  "Shuffle",
								  sf::Vector2f(100,50),
								  sf::Vector2f(100,0)));
	UIElements.push_back(UIButton(SelectionSort::selectionSort,
								  "Selection\nSort",
								  sf::Vector2f(125,70),
								  sf::Vector2f(210,0)));
	UIElements.push_back(UIButton(InsertionSort::insertionSort,
								  "Insertion\nSort",
								  sf::Vector2f(120, 70),
								  sf::Vector2f(345, 0)));
	UIElements.push_back(UIButton(MergeSort::mergeSort,
								  "Merge\nSort",
								  sf::Vector2f(90, 70),
								  sf::Vector2f(475, 0)));
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
	std::thread GUIThread(&program::GUIMain, this, std::ref(UIEventQueue), std::ref(run));
	//std::thread shuffleThread(&program::shuffle, this, std::ref(lines), std::ref(run));
	while (window.isOpen()) {
		programFPS = calcFPS(storedTimePoint);
		text.setString(std::to_string(programFPS));

		window.clear();    //Clear the window
		window.draw(text);
		handleEvents();    //Hadle any events for this frame
		updateLines();     //update the list of lines
		GUIDraw();         //Draw the GUI elements
		window.display();  //draw any updates to the window
	}
	run = false;
	//shuffleThread.join();
	GUIThread.join();
}

//Every Loop
void program::handleEvents() {
	sf::Event event;
	while (window.pollEvent(event)) {
		//Not sure if else if chain is the way to do this
		//Switch statemet was too restrictive
		if (event.type == sf::Event::Closed) window.close();
		else if (event.type == sf::Event::MouseButtonPressed) UIEventQueue.push(event);

	}
}

void program::updateLines() {
	for (auto& line : lines) {
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


//GUI Methods
void program::GUIMain(std::queue<sf::Event>& eventQueue, volatile bool& run) {
	while (run) {
		if (eventQueue.empty() != true) {
			sf::Event e = eventQueue.front();
			for (auto element : UIElements) {
				if (element.getBoundingRect().contains(e.mouseButton.x, e.mouseButton.y)) {
					element.onClick(lines);
				}
			}
			eventQueue.pop();
		}
	}
}

void program::GUIDraw() {
	for (auto& e : UIElements) e.draw(window);
}





//List Mutation Methods
void shuffle(std::vector<listElement>& lines) {
	auto tp = std::chrono::high_resolution_clock().now(); //get current time
	while (std::chrono::high_resolution_clock().now() - tp < std::chrono::milliseconds(500)) {
		std::random_shuffle(lines.begin(), lines.end());
		int i = 0;
		for (auto& e : lines) {
			e.setIndex(i++);
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(50));
	}
}

void sort(std::vector<listElement>& lines) {
	std::sort(lines.begin(), lines.end() );
	int i = 0;
	for (auto& e : lines) {
		e.setIndex(i++);
	}
}


