#ifndef _DRAWABLES_HPP
#define _DRAWABLES_HPP

#include <SFML/Graphics.hpp>

class drawable {
protected:
    sf::RenderWindow & window;
    sf::Vector2f pos;    

public:
    sf::Rect<float> box;

    drawable(sf::RenderWindow & window, sf::Vector2f & pos, sf::Vector2f size);

    virtual void draw() = 0;

    virtual void move(){};

    bool intersect( const drawable & other){
        return this->box.intersects(other.box);
    }


};

#endif