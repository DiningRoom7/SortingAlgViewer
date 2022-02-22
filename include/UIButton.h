#pragma once
#include <string>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <functional>
#include <future>
#include "listElement.h"



class UIButton {
public:
	//Constructor
	//The function argument cannot be a member function
	UIButton(std::function<void(std::vector<listElement>&)> fn,
			 std::string text = "Button",
			 sf::Vector2f size = sf::Vector2f(100,50), 
			 sf::Vector2f pos = sf::Vector2f(0,0),
			 sf::Color textColor = sf::Color::Black,
			 sf::Color boxColor = sf::Color::White);
	//Copy Constructor
	//Note that when buttons are inserted into the UIElement vector in program, they are copied
	//Because a brand new object is being made for the vector, the copy constructor is used and not = operator
	//This causes a problem where the new text gets a font pointer to the old button's font
	//When the copy of the button in the vector tries to dereference this pointer it causes an error
	//This copy constructor makes a new font object for the text object to point to
	//This alleviates the problem with trying to access illegal memory locations
	UIButton(const UIButton& button);

	//Getters & Setters
	std::string getText() const;
	void setText(const std::string text);
	sf::RectangleShape getRect() const;
	void setRect(const sf::RectangleShape rect);
	sf::Rect<float> getBoundingRect() const;
	sf::Vector2f getSize() const;
	void setSize(const sf::Vector2f size);
	sf::Vector2f getPos() const;
	void setPos(const sf::Vector2f pos);
	std::function<void(std::vector<listElement>&)> getFunction() const;

	//Rendering Methods
	void draw(sf::RenderWindow& window);

	//Event Driven
	//Member functions do not work
	void onClick(std::vector<listElement>&);


private:
	std::function<void(std::vector<listElement>&)> m_fn;
	sf::RectangleShape m_rect;
	sf::Font m_font;
	sf::Text m_text;
	sf::Color m_boxColor, m_textColor;


	//private methods
	sf::Vector2f textPos(sf::Vector2f pos);
};
