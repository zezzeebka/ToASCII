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

    Font = new sf::Font();
    Font->loadFromFile("data/FUTRFW.ttf");

    Text = new sf::Text;
    Text->setCharacterSize(60);
    Text->setFont(*Font);
    Text->setPosition(700, 450);
    Text->setString("12");

    Box.push_back(Screen);
    Box.push_back(ButtonSprite);
}

StartScreen::~StartScreen()
{
    delete ScreenTexture;
    delete ButtonTexture;
    delete Screen;
    delete ButtonSprite;
    delete Font;
    delete Text;
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

    OPENFILENAME ofn;
    ZeroMemory( &filename, sizeof( filename ) );
    ZeroMemory( &ofn,      sizeof( ofn ) );
    ofn.lStructSize  = sizeof( ofn );
    ofn.lpstrFilter  = "JPEG(.jpg)\0*.jpg\0 PNG(.png)\0*.png\0";
    ofn.lpstrFile    = filename;
    ofn.nMaxFile     = MAX_PATH;
    ofn.lpstrTitle   = "Choose .jpg or .png file";
    ofn.Flags        = OFN_DONTADDTORECENT | OFN_FILEMUSTEXIST;

    if (!GetOpenFileNameA( &ofn ))
    {
        setActivity(1);
    }
}

std::string StartScreen::getFilename()
{
    std::string str(filename);
    return str;
}

sf::Text *StartScreen::getText()
{
    return Text;
}

void StartScreen::setText(std::string text)
{
    Text->setString(text);
}
