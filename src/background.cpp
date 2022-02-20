#include "background.h"

Background::Background(std::string filename, int fontSize)
{
    _defaultImage = new sf::Image;
    _defaultImage->loadFromFile(filename);
    _font = new sf::Font;
    _font->loadFromFile("C:/Github/BgMon/data/FUTRFW.ttf");
    _text = new sf::Text;
    _text->setCharacterSize(fontSize);
    _text->setFont(*_font);
    toTest( _defaultImage->getSize().y,_defaultImage->getSize().x);
}

Background::Background()
{

}

Background::~Background()
{

}

void Background::Update()
{

}

void Background::toTest(int heigth, int width)
{
    sf::Color* color = new sf::Color;
    std::string simbols = "+,*;()%.?}=123&#$098";
    std::string _picture;
    int pixelsValue = 0;
    for(int p = 0; p < heigth; p+=10)
    {
        for(int k = 0; k < width; k+=10)
        {
            pixelsValue = 0;
            for(int i = 0; i < 10; i++)
            {
                for(int j = 0; j < 10; j++)
                {
                    *color = _defaultImage->getPixel(k+j, p+i);
                    pixelsValue += (color->r/3 + color->g/3 + color->b/3);
                }
            }
            pixelsValue /= 100;
            _picture += simbols[pixelsValue/25];
        }
        _picture += "\n";
    }
    _text->setString(_picture);
    _text->setColor(sf::Color::White);
    delete color;
}

sf::Sprite& Background::GetSprite()
{
    //return *_backSrpite;
}

sf::Text &Background::GetText()
{
    return *_text;
}


