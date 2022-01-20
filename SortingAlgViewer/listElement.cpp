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

int listElement::getValue() const {
	return m_value;
}

void listElement::setIndex(const int index) {
	m_index = index;
	m_rect.setPosition(indexToXPos(index), valToYPos(m_value));
}

int listElement::getIndex() const{
	return m_index;
}

void listElement::draw(sf::RenderWindow& window) {
	window.draw(m_rect);
}


//Operator Overloads
//Less than overload for std::sort alg
bool listElement::operator<(const listElement e) const {
	return m_value < e.getValue();
}
//Equals overload for std::sort alg
listElement& listElement::operator=(const listElement& e){
	setValue(e.getValue());
	setIndex(e.getIndex());
	return *this;
}


//Private Methods
inline int listElement::indexToXPos(const int index) {
	return index * 5;
}

inline int listElement::valToYPos(const int val) {
	return WINDOW_HEIGHT - val - 5;
}