#include "drawables.hpp"

drawable::drawable(sf::RenderWindow & window, sf::Vector2f & pos, sf::Vector2f size ) :
    window{ window },
	pos{ pos },
    box{ pos, size }
{}
