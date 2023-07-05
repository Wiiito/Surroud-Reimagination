#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "animations.hpp"

using namespace sf;
using std::vector;

class Dragon {
private:
    vector<Vector2f> dragonBody;
    Vector2f screenSize;
    RectangleShape dragonRectShape;
    int offset;
    int myDirection = -1;
    Keyboard::Key keys[4];

    Texture headTexture;
    Sprite headSprite;
    Sprite baseSprite;

    Animation *headAnimation;

    void grow(int x, int y);
    void makeHead();

public:
    Dragon(Color color, int part);
    Vector2f onGridRandom(int part);
    void move();
    void draw(RenderWindow *pWindow);
    void update();
    void setKeys(Keyboard::Key* keys);
    Keyboard::Key getKey(int index);
    void setDirection(int direction);
};