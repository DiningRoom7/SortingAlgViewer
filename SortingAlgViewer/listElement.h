#pragma once
#include <SFML/Graphics.hpp>
#include "settings.h"

class listElement {
public:
	listElement(const int=0, const int=0);
	~listElement();

	//Getters & Setters
	void setPos(const double x, const double y);
	void setValue(const int val);
	int getValue();
	void setIndex(const int index);
	int getIndex();
	//Rendering
	void draw(sf::RenderWindow& window);

private:
	int m_value, m_index;
	sf::RectangleShape m_rect;

	//Helper methods
	inline int indexToXPos(int index);
	inline int valToYPos(int val);
};