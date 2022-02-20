#ifndef STARTSCREEN_H
#define STARTSCREEN_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <windows.h>

class StartScreen
{
private:
    sf::Texture* ScreenTexture;
    sf::Texture* ButtonTexture;
    sf::Sprite* Screen;
    sf::Sprite* ButtonSprite;
    std::vector<sf::Sprite*> Box;
    bool isButtonActive = 1;
    char filename[ MAX_PATH ];
public:
    StartScreen();
    ~StartScreen();

    std::vector<sf::Sprite*> ToDraw();

    bool getActivity();
    void setActivity(bool activity);

    void setFile();
};

#endif // STARTSCREEN_H
