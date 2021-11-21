#include <SFML/Graphics.hpp>
#include "shapes.hpp"

circle::circle( sf::RenderWindow & window, sf::Vector2f pos, float radius, sf::Color color ) :
	drawable{window, pos, sf::Vector2f{radius*2, radius*2}},
	radius{radius},
	color{color}
{}

void circle::draw() {
	shape.setRadius(radius);
	shape.setPosition(box.left, box.top);
	shape.setFillColor(color);
	window.draw(shape);
}

rectangle::rectangle( sf::RenderWindow & window, sf::Vector2f pos, sf::Vector2f size, sf::Color color ) :
	drawable{ window, pos, size },
	size{ size },
    color{ color }
{}

void rectangle::draw() {
    shape.setPosition(box.left, box.top);
    shape.setSize(size);
    shape.setFillColor(color);
	window.draw(shape);
}

