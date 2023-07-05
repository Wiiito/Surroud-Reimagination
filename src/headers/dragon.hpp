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
    int winPart;
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
    bool dragonCollide(vector<Vector2f> pos);
    bool edgesCollide(Vector2f initPos, Vector2f finalPos);
    void reinit();
    void setKeys(Keyboard::Key* keys);
    Keyboard::Key getKey(int index);
    vector<Vector2f> getBody();
    void setDirection(int direction);
};