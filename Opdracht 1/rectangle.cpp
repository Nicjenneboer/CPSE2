#include <SFML/Graphics.hpp>
#include "rectangle.hpp"

rectangle::rectangle( sf::RenderWindow & window, sf::Vector2f pos, sf::Vector2f size ) :
	drawable{ window, pos },
	size{ size }
{}

void rectangle::draw() {
	sf::RectangleShape rectangle;
    rectangle.setPosition(pos);
    rectangle.setSize(size);
	window.draw(rectangle);
}