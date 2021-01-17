#include <iostream>
#include <SFML/Graphics.hpp>

#include "Log.hpp"

int main() {
    Log::init();

    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                window.close();
            } else if (event.type == sf::Event::KeyReleased) {
                LOG_TRACE("something something");
            }

        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}
