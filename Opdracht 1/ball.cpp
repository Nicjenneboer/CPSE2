#include <SFML/Graphics.hpp>
#include "ball.hpp"

ball::ball( sf::Vector2f pos, float size ) :
	drawable{pos},
	size{size}
{}
	

void ball::draw( sf::RenderWindow & window ) const {
	sf::CircleShape circle;
	circle.setRadius(size);
	circle.setPosition(pos);
	window.draw(circle);
}

void ball::move( sf::Vector2f delta ){
	pos += delta;
}

void ball::jump( sf::Vector2f target ){
	pos = target;
}

void ball::jump( sf::Vector2i target ){
	jump( sf::Vector2f( 
		static_cast< float >( target.x ), 
		static_cast< float >( target.y )
	));
}
