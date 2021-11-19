#include <SFML/Graphics.hpp>
#include "ball.hpp"

ball::ball( sf::RenderWindow & window, sf::Vector2f pos, float size ) :
	drawable{window, pos},
	size{size}
{}
	

void ball::draw() {
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
