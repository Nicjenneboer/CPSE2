#include "drawables.hpp"

drawable::drawable(sf::RenderWindow & window, sf::Vector2f & pos ) :
    window{ window },
	pos{ pos }
{}
