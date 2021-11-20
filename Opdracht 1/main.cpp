#include <iostream>
#include <functional>
#include <SFML/Graphics.hpp>
#include <array>
#include "objects.hpp"

class action {
private:
	std::function< bool() > condition;
	std::function< void() > work;
public:
	action(
	   std::function< bool() > condition, 
	   std::function< void() > work
	) : condition( condition ), 
		work( work ) 
	{}

	action(
		sf::Keyboard::Key key,
		std::function< void() > work
	) :
		condition(
			[ key ]()->bool { return sf::Keyboard::isKeyPressed( key ); }
		),
		work(work)
	{}

	action(
		sf::Mouse::Button button,
		std::function< void() > work
	) :
		condition(
			[ button ]()->bool { return sf::Mouse::isButtonPressed( button ); }
		),
		work(work)
	{}

	action( std::function< void() > work ):
		condition(
			[]()->bool { return true; }
		),
		work(work)
	{}

	void operator()(){
		if( condition() ){
			work();
		}
	}
};

int main( int argc, char *argv[] ){
	std::cout << "Starting application 01-05 array of actions\n";

	sf::RenderWindow window{ sf::VideoMode{ 640, 480 }, "SFML window" };
	ball ball{ window, sf::Vector2f{ 320.0, 240.0 } };
	block mblock{window, sf::Vector2f{ 100, 100 }, sf::Vector2f{ 30, 30 }, sf::Color::Blue};
	wall wall_top{ window, sf::Vector2f{ 20, 0 }, sf::Vector2f{ 600, 20 }, sf::Color::Green };
	wall wall_left{ window, sf::Vector2f{ 0, 0 }, sf::Vector2f{ 20, 480 }, sf::Color::Green };
	wall wall_right{ window, sf::Vector2f{ 620, 0 }, sf::Vector2f{ 20, 480 }, sf::Color::Green };
	wall wall_bottom{ window, sf::Vector2f{ 20, 460 }, sf::Vector2f{ 620, 20 }, sf::Color::Green };

	std::array< drawable*, 6 > drawables = { &ball, &mblock, &wall_top, &wall_left, &wall_right, &wall_bottom };

	action actions[] = {
		action( [&](){ ball.move(); }),
		action( sf::Keyboard::Left,  [&](){ mblock.move( sf::Vector2f( -1.0,  0.0 )); }),
		action( sf::Keyboard::Right, [&](){ mblock.move( sf::Vector2f( +1.0,  0.0 )); }),
		action( sf::Keyboard::Up,    [&](){ mblock.move( sf::Vector2f(  0.0, -1.0 )); }),
		action( sf::Keyboard::Down,  [&](){ mblock.move( sf::Vector2f(  0.0, +1.0 )); }),
	// 	action( sf::Mouse::Left,     [&](){ my_ball.jump( sf::Mouse::getPosition( window )); })
	};

	while (window.isOpen()) {
		for( auto & action : actions ){
			action();
		}

		window.clear();
		for( auto & object : drawables){
			object->draw();
		}
		window.display();

		sf::sleep( sf::milliseconds( 20 ));

        sf::Event event;		
	    while( window.pollEvent(event) ){
			if( event.type == sf::Event::Closed ){
				window.close();
			}
		}	
	}

	std::cout << "Terminating application\n";
	return 0;
}

