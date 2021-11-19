#ifndef _DRAWABLES_HPP
#define _DRAWABLES_HPP

#include <SFML/Graphics.hpp>

class drawable {
protected:
    sf::RenderWindow & window;

    sf::Vector2f pos;    

public:

    drawable(sf::RenderWindow & window, sf::Vector2f & pos);

    virtual void draw() = 0;


};

#endif