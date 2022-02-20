#include <SFML/Graphics.hpp>
#include "start-screen.h"


StartScreen::StartScreen()
{
    ScreenTexture = new sf::Texture();
    ButtonTexture = new sf::Texture();
    ScreenTexture->loadFromFile("data/StartScreen.jpg");
    ButtonTexture->loadFromFile("data/StartButton.jpg");
    Screen = new sf::Sprite(*ScreenTexture);
    ButtonSprite = new sf::Sprite(*ButtonTexture);
    ButtonSprite->setPosition(700, 600);

    Box.push_back(Screen);
    Box.push_back(ButtonSprite);
}

StartScreen::~StartScreen()
{

}

std::vector<sf::Sprite*> StartScreen::ToDraw()
{
    return Box;
}

bool StartScreen::getActivity()
{
    return isButtonActive;
}

void StartScreen::setActivity(bool activity)
{
    isButtonActive = activity;
}
