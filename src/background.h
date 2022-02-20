#ifndef BACKGROUND_H
#define BACKGROUND_H
#include <SFML/Graphics.hpp>

class Background
{
private:
    sf::Image* _defaultImage;
    sf::Font* _font;
    sf::Text* _text;
public:
    Background();
    ~Background();
    Background(std::string filename, int fontSize);
    void Update();
    void toTest(int heigth, int width);
    sf::Sprite& GetSprite();
    sf::Text& GetText();
};

#endif // BACKGROUND_H
