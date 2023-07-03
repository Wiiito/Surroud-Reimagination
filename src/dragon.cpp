#include "headers/dragon.hpp"

#include <SFML/Graphics.hpp>
#include <iostream>
// #include <ctime>

using namespace sf;
using std::vector;

Dragon::Dragon() {
  offset = 50;
  dragonRectShape.setSize(Vector2f(offset, offset));
  dragonRectShape.setFillColor(Color::Red);

  dragonBody.push_back(Vector2f(0, 0));

  this->makeHead();
}

void Dragon::makeHead() {
  this->baseTexture.loadFromFile("src/assets/imgs/dragon/dragon-base.png");

  this->baseSprite.setTexture(this->baseTexture);
  this->baseSprite.setPosition(Vector2f(50, 80));
  this->baseSprite.setScale(4, 4);

  this->baseSprite.setTextureRect(IntRect(0, 0, 29, 46));
  this->baseSprite.setColor(Color(255, 255, 255, 128));

  this->headTexture.loadFromFile("src/assets/imgs/dragon/dragon-frame00.png");

  this->headSprite.setTexture(this->headTexture);
  this->headSprite.setPosition(Vector2f(50, 50));
  this->headSprite.setScale(4, 4);

  this->headSprite.setTextureRect(IntRect(0, 0, 29, 46));
}

Vector2f Dragon::onGridRandom() {
  return Vector2f(float((rand() % int(screenSize.x) / offset) * offset),
                  float((rand() % int(screenSize.y) / offset) * offset));
}

void Dragon::grow(int x, int y) {
  dragonBody.push_back(Vector2f(float(dragonBody.at(dragonBody.size() - 1).x + x * offset),
                                float(dragonBody.at(dragonBody.size() - 1).y + y * offset)));
}

void Dragon::move(int direction) {
  if (myDirection == 0 && myDirection != 2) {  // 0 is RIGHT
    this->grow(1, 0);
  } else if (myDirection == 1 && myDirection != 3) {  // 1 is UP
    this->grow(0, -1);
  } else if (myDirection == 2 && myDirection != 0) {  // 2 is LEFT
    this->grow(-1, 0);
  } else if (myDirection == 3 && myDirection != 1) {  // 3 is DOWN
    this->grow(0, 1);
  }
}

void Dragon::update(RenderWindow *pWindow) {
  pWindow->draw(this->baseSprite);
  //pWindow->draw(this->headSprite);

  for (int i = 0; i < dragonBody.size(); i++) {
    dragonRectShape.setPosition(dragonBody.at(i).x, dragonBody.at(i).y);
    pWindow->draw(this->dragonRectShape);
  }
}