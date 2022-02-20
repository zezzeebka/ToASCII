#ifndef BACKGROUND_H
#define BACKGROUND_H
#include <SFML/Graphics.hpp>

class Background
{
private:
    sf::Image* _defaultImage;
    sf::Image* _changedImage;
    sf::Texture* _backTexture1;
    sf::Sprite* _backSrpite;
    sf::Font* _font;
    sf::Text* _text;
public:
    Background();
    void Update();
    void changePixels(int heigth, int width);
    void toTest(int heigth, int width);
    sf::Sprite& GetSprite();
    sf::Text& GetText();
};

#endif // BACKGROUND_H
