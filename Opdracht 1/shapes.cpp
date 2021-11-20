#include <SFML/Graphics.hpp>
#include "shapes.hpp"

circle::circle( sf::RenderWindow & window, sf::Vector2f pos, float radius ) :
	drawable{window, pos, sf::Vector2f{radius*2, radius*2}},
	radius{radius}
{}

void circle::draw() {
	shape.setRadius(radius);
	shape.setPosition(box.left, box.top);
	window.draw(shape);
}

rectangle::rectangle( sf::RenderWindow & window, sf::Vector2f pos, sf::Vector2f size ) :
	drawable{ window, pos, size },
	size{ size }
{}

void rectangle::draw() {
	sf::RectangleShape rectangle;
    rectangle.setPosition(pos);
    rectangle.setSize(size);
	window.draw(rectangle);
}

