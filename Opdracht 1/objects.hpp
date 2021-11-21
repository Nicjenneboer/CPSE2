#ifndef _OBJECTS_HPP
#define _OBJECTS_HPP

#include <SFML/Graphics.hpp>
#include "shapes.hpp"


class ball : public circle{
private:
	sf::Vector2f direction = sf::Vector2f{1,1};
	float speed = 5;

public:

	ball( sf::RenderWindow & window, sf::Vector2f pos, float radius, sf::Color color );

	void move();

    void change_direction(const drawable & object);


};

class wall : public rectangle{
private:


public:

    wall( sf::RenderWindow & window, sf::Vector2f pos, sf::Vector2f size,  sf::Color color = sf::Color::White );

};

class block : public rectangle{
private:
    float speed = 2;

public:

    block( sf::RenderWindow & window, sf::Vector2f pos, sf::Vector2f size,  sf::Color color = sf::Color::White );

    void move( const sf::Vector2f & delta );
};

#endif