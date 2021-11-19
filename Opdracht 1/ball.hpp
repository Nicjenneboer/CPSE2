#ifndef _BALL_HPP
#define _BALL_HPP

#include <SFML/Graphics.hpp>
#include "drawables.hpp"

class ball : public drawable{
public:

	ball( sf::Vector2f pos, float size = 30.0 );

	

	void draw( sf::RenderWindow & window ) const;

	void move( sf::Vector2f delta );

	void jump( sf::Vector2f target );
	void jump( sf::Vector2i target );

private:
	float size;
};

#endif
