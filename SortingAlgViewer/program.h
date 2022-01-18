#pragma once
#include <vector>
#include "listElement.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <chrono>

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
	std::vector<listElement> makeList(int numLines);
	void handleEvents();
	void handleMouseClick();
	void updateLines();
	int calcFPS(std::chrono::time_point<std::chrono::high_resolution_clock>& stored);
};
