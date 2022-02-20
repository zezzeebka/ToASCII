#include "background.h"

Background::Background()
{
    _defaultImage = new sf::Image;
    _defaultImage->loadFromFile("C:/Github/BgMon/data/Image.jpg");
    _font = new sf::Font;
    _font->loadFromFile("data/FUTRFW.ttf");
    _text = new sf::Text;
    _text->setCharacterSize(10);
    _text->setFont(*_font);
    toTest( _defaultImage->getSize().y,_defaultImage->getSize().x);
    changePixels(_defaultImage->getSize().x, _defaultImage->getSize().y);
    _backTexture1 = new sf::Texture;
    _backTexture1->loadFromImage(*_defaultImage);
    _backSrpite = new sf::Sprite;
    _backSrpite->setTexture(*_backTexture1);
}

void Background::Update()
{

}

void Background::changePixels(int width, int heigth)
{
    sf::Color* color = new sf::Color;
    for(int i = 0; i < heigth; i++)
    {
        for(int j = 0; j < width; j++)
        {
            *color = _defaultImage->getPixel(j, i);
            color->r += 150;
            color->g += 100;
            color->b += 200;
            _defaultImage->setPixel(j, i, *color);
        }
    }
    delete color;
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
    return *_backSrpite;
}

sf::Text &Background::GetText()
{
    return *_text;
}


