#include <SFML/Graphics.hpp>
#include "background.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1600, 1100), "SFML works!");

        sf::Clock backClock;

        backClock.restart();

        Background background;

        while (window.isOpen())
        {
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();
            }

            if (backClock.getElapsedTime() >= sf::milliseconds(600)) {
                backClock.restart();
                background.Update();
            }

            window.clear();

            window.draw(background.GetText());

            window.display();
        }

        return 0;
}
