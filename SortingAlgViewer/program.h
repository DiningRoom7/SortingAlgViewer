#pragma once
#include <vector>
#include "listElement.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <chrono>
#include <thread>

class program {
public:
	program();
	~program();

	void mainLoop();
private:
	int programFPS;
	std::vector<listElement> lines;
	sf::RenderWindow window;

	std::chrono::time_point<std::chrono::high_resolution_clock> storedTimePoint;

	sf::Font font;
	sf::Text text;

	//Helper methods
	//Initialization
	std::vector<listElement> makeList(int numLines);

	//Every Loop
	void handleEvents();
	void handleMouseClick();
	void updateLines();
	int calcFPS(std::chrono::time_point<std::chrono::high_resolution_clock>& stored);

	//List Mutation
	void shuffle(std::vector<listElement>& vect, volatile bool& run);
	//Run as separate thread like this
	//std::thread t = std::thread(&program::shuffle, this, std::ref(lines), std::ref(run));

};
