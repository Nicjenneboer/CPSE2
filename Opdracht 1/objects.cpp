#include <SFML/Graphics.hpp>
#include "objects.hpp"

ball::ball( sf::RenderWindow & window, sf::Vector2f pos, float radius) :
	circle{window, pos, radius}
{}

void ball::move(){
	box.left+=direction.x * speed;
	box.top+=direction.y * speed;
}

wall::wall(  sf::RenderWindow & window, sf::Vector2f pos, sf::Vector2f size ) :
    rectangle{window, pos, size}
{}