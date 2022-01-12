#pragma once
#include <SFML/Graphics.hpp>

class listElement {
public:
	listElement(int=0);
	~listElement();

	void setPos(double x, double y);
	void draw(sf::RenderWindow& window);

	//Operator overloads
private:
	int value;
	sf::RectangleShape rect;
};