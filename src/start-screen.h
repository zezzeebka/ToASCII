#ifndef STARTSCREEN_H
#define STARTSCREEN_H
#include <SFML/Graphics.hpp>
#include <iostream>

class StartScreen
{
private:
    sf::Texture* ScreenTexture;
    sf::Texture* ButtonTexture;
    sf::Sprite* Screen;
    sf::Sprite* ButtonSprite;
    std::vector<sf::Sprite*> Box;
public:
    StartScreen();
    ~StartScreen();
    std::vector<sf::Sprite*> ToDraw();
};

#endif // STARTSCREEN_H
