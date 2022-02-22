
#include "UIButton.h"

UIButton::UIButton(std::function<void(std::vector<listElement>& vect)> fn, std::string text,sf::Vector2f size,sf::Vector2f pos,sf::Color textColor,sf::Color boxColor) {
	m_fn = fn;
	m_font = sf::Font();
	m_font.loadFromFile("arial.ttf");
	m_text = sf::Text(text, m_font);
	m_text.setFillColor(textColor);
	m_text.setPosition(pos);
	m_rect = sf::RectangleShape(size);
	m_rect.setPosition(pos);
	m_rect.setFillColor(boxColor);
}
UIButton::UIButton(const UIButton& button) {
	m_fn = button.getFunction();
	m_font = sf::Font();
	m_font.loadFromFile("arial.ttf");
	m_text = sf::Text(button.getText(), m_font);
	m_text.setFillColor(sf::Color::Black);
	m_text.setPosition(button.getPos());
	m_rect = button.getRect();
}


//Getters & Setters
std::string UIButton::getText() const {
	//return m_text.getString();
	return std::string("button");
}
void UIButton::setText(const std::string text) {
	m_text.setString(text);
}

sf::RectangleShape UIButton::getRect() const {
	return m_rect;
}
void UIButton::setRect(const sf::RectangleShape rect) {
	m_rect = rect;
}

sf::Rect<float> UIButton::getBoundingRect() const {
	return m_rect.getGlobalBounds();
}

sf::Vector2f UIButton::getSize() const{
	return m_rect.getSize();
}
void UIButton::setSize(const sf::Vector2f size) {
	m_rect.setSize(size);
}

sf::Vector2f UIButton::getPos() const {
	return m_rect.getPosition();
}
void UIButton::setPos(const sf::Vector2f pos) {
	m_rect.setPosition(pos);
	m_text.setPosition(textPos(pos));
}

std::function<void(std::vector<listElement>&)> UIButton::getFunction() const{
	return m_fn;
}


//Rendering Methods
void UIButton::draw(sf::RenderWindow& window) {
	window.draw(m_rect);
	window.draw(m_text);
}

//Event Driven
void UIButton::onClick(std::vector<listElement>& vect) {
	std::async(m_fn, std::ref(vect));
}



//Private Methods
//Calculate where the text should be positioned to be in the center of the button
sf::Vector2f UIButton::textPos(sf::Vector2f pos) {
	int x = pos.x, y = pos.y;
	return pos;
}