#include "drawables.hpp"

drawable::drawable(sf::RenderWindow & window, sf::Vector2f & pos, sf::Vector2f size ) :
    window{ window },
	pos{ pos },
    box{ pos, size }
{}

bool drawable::intersect( const drawable & other){
    if(this->box.intersects(other.box)){
        return true;
    }else{
        return false;
    }
}