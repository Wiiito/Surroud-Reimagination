#include "headers/dragon.hpp"

#include <SFML/Graphics.hpp>
#include <iostream>
// #include <ctime>

using namespace sf;
using std::vector;

Dragon::Dragon(Color color, int part) {
  this->screenSize = Vector2f(1280, 720);
  offset = 40;

  
  dragonRectShape.setSize(Vector2f(offset, offset));
  dragonRectShape.setFillColor(color);

  dragonBody.push_back(this->onGridRandom(part));
  std::cout << dragonBody.at(0).x << ", " << dragonBody.at(0).y << std::endl;
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

Vector2f Dragon::onGridRandom(int part) {
  int midWindX = (part * screenSize.x / 2 / offset) * offset;

  return Vector2f(
    offset + midWindX + ((rand() % int(screenSize.x / 2 - 2 * offset) / offset) * offset),
    offset + ((rand() % int(screenSize.y - 2 * offset) / offset) * offset)
  );
}

void Dragon::grow(int x, int y) {
  dragonBody.push_back(Vector2f(float(dragonBody.at(dragonBody.size() - 1).x + x * offset),
                                float(dragonBody.at(dragonBody.size() - 1).y + y * offset)));
}

void Dragon::move() {
  switch (this->myDirection){
  case 0:
    this->grow(1, 0);
    break;
  case 1:
    this->grow(0, -1);
    break;
  case 2:
    this->grow(-1, 0);
    break;
  case 3:
    this->grow(0, 1);
    break;
  }
}

void Dragon::setKeys(Keyboard::Key* pkeys){
  for (int i = 0; i <= 3; i++){
    this->keys[i] = pkeys[i];
  } 
}

Keyboard::Key Dragon::getKey(int index) {
  return this->keys[index];
}

void Dragon::setDirection(int direction){
  this->myDirection = direction;
}

void Dragon::update(RenderWindow *pWindow) {
  //pWindow->draw(this->baseSprite);
  //pWindow->draw(this->headSprite);

  for (int i = 0; i < dragonBody.size(); i++) {
    dragonRectShape.setPosition(dragonBody.at(i).x, dragonBody.at(i).y);
    pWindow->draw(this->dragonRectShape);
  }

  //std::cout << this->onGridRandom(0).x << ", " << this->onGridRandom(0).y << std::endl;
}