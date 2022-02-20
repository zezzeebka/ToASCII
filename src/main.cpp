#include <SFML/Graphics.hpp>
#include "background.h"
#include "start-screen.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1600, 900), "SFML works!");

        sf::Clock backClock;

        backClock.restart();
        StartScreen* startScreen = new StartScreen();
        Background* background;

        std::vector< std::vector<sf::Sprite*> > object_list;
        object_list.push_back(startScreen->ToDraw());

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
                background->Update();
            }

            window.clear();

            for(std::vector<sf::Sprite*>& i : object_list)
            {
                for(sf::Sprite* j : i)
                {
                     window.draw(*j);
                }
            }

            window.display();
        }

        return 0;
}
