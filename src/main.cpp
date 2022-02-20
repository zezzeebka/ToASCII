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
                switch ( event.type )
                {
                case sf::Event::Closed:
                    window.close();
                    break;

                case sf::Event::MouseButtonPressed:
                {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                    sf::Vector2f mousePosF ( static_cast<float>( mousePos.x ), static_cast<float>( mousePos.y ) );
                    if (object_list[0][1]->getGlobalBounds().contains( mousePosF ) && startScreen->getActivity() == 1)
                    {
                        startScreen->setActivity(0);
                        startScreen->setFile();
                        //window.close();
                    }
                    break;
                }
                }
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
