#include "listElement.h"
#include <SFML/Graphics.hpp>

//Constructor and destructor
listElement::listElement(int val) {
	value = val;
	rect = sf::RectangleShape(sf::Vector2f(4,val));
	rect.setFillColor(sf::Color::White);
}
listElement::~listElement() {

}

void listElement::setPos(double x, double y) {
	rect.setPosition(x, y);
}

void listElement::draw(sf::RenderWindow& window) {
	window.draw(rect);
}