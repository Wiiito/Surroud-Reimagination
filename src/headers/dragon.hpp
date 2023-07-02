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
    int myDirection;

    Texture headTexture;
    Texture baseTexture;

    Sprite headSprite;
    Sprite baseSprite;

    void grow(int x, int y);

public:
    Dragon();
    Vector2f onGridRandom();
    void move(int direction);
    void update(RenderWindow *pWindow);
};