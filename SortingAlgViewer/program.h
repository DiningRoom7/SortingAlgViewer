#pragma once
#include <vector>
#include <list>
#include "listElement.h"
#include "UIButton.h"
#include "sortAlgs.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <chrono>
#include <thread>
#include <queue>
#include <functional>

class program {
public:
	program();
	~program();

	void mainLoop();
private:
	int programFPS;
	std::vector<listElement> lines;
	std::vector<UIButton> UIElements;
	std::queue<sf::Event> UIEventQueue;
	sf::RenderWindow window;

	std::chrono::time_point<std::chrono::high_resolution_clock> storedTimePoint;

	sf::Font font;
	sf::Text text;

	//Helper methods
	//Initialization
	std::vector<listElement> makeList(int numLines);

	//Every Loop
	void handleEvents();
	void updateLines();
	int calcFPS(std::chrono::time_point<std::chrono::high_resolution_clock>& stored);

	//GUI Thread Methods
	void GUIMain(std::queue<sf::Event>& eventQueue, volatile bool& run);
	void GUIDraw();
	 
};

//List Mutation Functions
void shuffle(std::vector<listElement>& lines);
void sort(std::vector<listElement>& lines);
