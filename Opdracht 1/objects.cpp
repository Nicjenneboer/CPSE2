#include <SFML/Graphics.hpp>
#include "objects.hpp"

ball::ball( sf::RenderWindow & window, sf::Vector2f pos, float radius, sf::Color color) :
	circle{window, pos, radius, color}
{}

void ball::move(){
	box.left+=direction.x * speed;
	box.top+=direction.y * speed;
}

void ball::change_direction(const drawable & object){
	sf::Rect< float > tmp = sf::Rect< float >{ box.left+(direction.x*-1 * speed), 
												   box.top+direction.y * speed, 
												   box.width, 
												   box.height };
	if (tmp.intersects(object.box)){
		direction.y*=-1;
	}else{
		direction.x*=-1;
	}

}

wall::wall(  sf::RenderWindow & window, sf::Vector2f pos, sf::Vector2f size, sf::Color color ) :
    rectangle{window, pos, size, color}
{}

block::block(  sf::RenderWindow & window, sf::Vector2f pos, sf::Vector2f size, sf::Color color ) :
    rectangle{window, pos, size, color}
{}

void block::move( const sf::Vector2f & delta ){
		box.left += delta.x * speed;
		box.top += delta.y * speed;
	}