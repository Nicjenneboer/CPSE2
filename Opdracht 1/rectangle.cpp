#include <SFML/Graphics.hpp>
#include "rectangle.hpp"

rectangle::rectangle( sf::Vector2f pos, sf::Vector2f size ) :
	drawable{ pos },
	size{ size }
{}

void rectangle::draw( sf::RenderWindow & window ) const {
	sf::RectangleShape rectangle;
    rectangle.setPosition(pos);
    rectangle.setSize(size);
	window.draw(rectangle);
}