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
   delete _defaultImage;
   delete _font;
   delete _text;
}

void Background::Update()
{

}

void Background::toTest(int heigth, int width)
{
    sf::Color* color = new sf::Color;
    std::string simbols = " +,*;()%.?}=_-:^~98";
    std::string _picture;
    int pixelsValue = 0;
    int fontSize = _text->getCharacterSize();
    for(int p = 0; p < heigth-fontSize; p+=fontSize)
    {
        for(int k = 0; k < width-fontSize; k+=fontSize)
        {
            pixelsValue = 0;
            for(int i = 0; i < fontSize; i++)
            {
                for(int j = 0; j < fontSize; j++)
                {
                    *color = _defaultImage->getPixel(k+j, p+i);
                    pixelsValue += (color->r/3 + color->g/3 + color->b/3);
                }
            }
            pixelsValue /= fontSize*fontSize;
            _picture += simbols[pixelsValue/13];
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


