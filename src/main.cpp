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
                if(startScreen->getActivity() == 1){
                    if (object_list[0][1]->getGlobalBounds().contains( mousePosF ))
                    {
                        startScreen->setActivity(0);
                        startScreen->setFile();
                        if(!startScreen->getFilename().empty())
                        {
                            background = new Background(startScreen->getFilename(), std::stoi( startScreen->getText()->getString().toAnsiString() ));
                            object_list.clear();
                        }
                        //window.close();
                    }
                }

                break;
            }
            case sf::Event::MouseWheelScrolled:
            {
                int fontSize = std::stoi( startScreen->getText()->getString().toAnsiString() );
                if(startScreen->getActivity() == 1)
                {
                    if(fontSize > 5 && fontSize < 29)
                    {
                        fontSize += event.mouseWheelScroll.delta;
                    }
                    if(fontSize == 5)
                    {
                        fontSize++;
                    }
                    if(fontSize == 29)
                    {
                        fontSize--;
                    }
                    startScreen->setText(std::to_string(fontSize));
                }
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

        if (startScreen->getActivity() == 1)
        {
            window.draw(*startScreen->getText());
        }
        else
        {
            window.draw(background->GetText());
        }

        window.display();
    }

    return 0;
}
