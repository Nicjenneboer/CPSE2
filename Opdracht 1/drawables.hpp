#ifndef _DRAWABLES_HPP
#define _DRAWABLES_HPP

#include <SFML/Graphics.hpp>

class drawable {
private:
    

public:
    sf::Vector2f pos;

    drawable(sf::Vector2f pos);

    virtual void draw() {};


};

#endif