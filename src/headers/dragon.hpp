#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

using namespace sf;
using std::vector;

class Dragon {
private:
    vector<Vector2f> dragonBody;
    Vector2f screenSize;
    RectangleShape dragonRectShape;
    int offset;
    int myDirection = 0;
    Keyboard::Key keys[4];

    Texture headTexture;
    Texture baseTexture;

    Sprite headSprite;
    Sprite baseSprite;

    void grow(int x, int y);
    void makeHead();

public:
    Dragon();
    Vector2f onGridRandom();
    void move();
    void update(RenderWindow *pWindow);
    void setKeys(Keyboard::Key* keys);
    Keyboard::Key getKey(int index);
    void setDirection(int direction);
};