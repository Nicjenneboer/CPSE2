#ifndef _SHAPES_HPP
#define _SHAPES_HPP

#include <SFML/Graphics.hpp>
#include "drawables.hpp"

class circle : public drawable{
private:
	float radius;
	sf::CircleShape shape;
	sf::Color color;

public:

	circle( sf::RenderWindow & window, sf::Vector2f pos, float radius, sf::Color color = sf::Color::White );

	void draw() override;


};

class rectangle : public drawable{

private:
	sf::Vector2f size;
    sf::Color color;
	sf::RectangleShape shape;

public:

	rectangle( sf::RenderWindow & window, sf::Vector2f pos, sf::Vector2f size, sf::Color color = sf::Color::White );

	void draw() override;

};

#endif