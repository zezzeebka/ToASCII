#include <SFML/Graphics.hpp>
#include "start-screen.h"
#include <windows.h>

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

void StartScreen::setFile()
{
    char filename[ MAX_PATH ];

    OPENFILENAME ofn;
    ZeroMemory( &filename, sizeof( filename ) );
    ZeroMemory( &ofn,      sizeof( ofn ) );
    ofn.lStructSize  = sizeof( ofn );
    ofn.lpstrFilter  = "JPEG(.jpg)\0*.jpg\0 PNG(.png)\0*.png\0";
    ofn.lpstrFile    = filename;
    ofn.nMaxFile     = MAX_PATH;
    ofn.lpstrTitle   = "Choose .jpg file";
    ofn.Flags        = OFN_DONTADDTORECENT | OFN_FILEMUSTEXIST;

    if (!GetOpenFileNameA( &ofn ))
    {
        setActivity(1);
    }
}
