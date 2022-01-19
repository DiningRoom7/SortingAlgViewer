#include "listElement.h"
#include <SFML/Graphics.hpp>

//Constructor and destructor
listElement::listElement(const int val, const int index) {
	m_value = val;
	m_index = index;
	m_rect = sf::RectangleShape(sf::Vector2f(4,val));
	m_rect.setFillColor(sf::Color::White);
	m_rect.setPosition(indexToXPos(index), valToYPos(val));
}
listElement::~listElement() {

}

//Member Functions
void listElement::setPos(const double x, const double y) {
	m_rect.setPosition(x, y);
}

void listElement::setValue(const int val) {
	m_value = val;
	m_rect.setSize(sf::Vector2f(4, val));
}

int listElement::getValue() {
	return m_value;
}

void listElement::setIndex(const int index) {
	m_index = index;
	m_rect.setPosition(indexToXPos(index), valToYPos(m_value));
}

int listElement::getIndex() {
	return m_index;
}

void listElement::draw(sf::RenderWindow& window) {
	window.draw(m_rect);
}


//Private Methods
inline int listElement::indexToXPos(const int index) {
	return index * 5;
}

inline int listElement::valToYPos(const int val) {
	return WINDOW_HEIGHT - val - 5;
}