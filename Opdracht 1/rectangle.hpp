#ifndef _RECTANGLE_HPP
#define _RECTANGLE_HPP

#include <SFML/Graphics.hpp>
#include "drawables.hpp"

class rectangle : public drawable{

private:
	sf::Vector2f size;

public:

	rectangle( sf::Vector2f pos, sf::Vector2f size );

	void draw( sf::RenderWindow & window ) const;

	// void move( sf::Vector2f delta );

	// void jump( sf::Vector2f target );
	// void jump( sf::Vector2i target );
};

#endif