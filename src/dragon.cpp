#include "headers/dragon.hpp"

#include <SFML/Graphics.hpp>
#include <iostream>
#include <ctime>

using namespace sf;
using std::vector;

Dragon::Dragon(Color color, int part) {
  this->headAnimation = new Animation(8, 0.1f, Vector2i(0, 0));
  this->screenSize = Vector2f(1280, 720);
  offset = 40;
  
  dragonRectShape.setSize(Vector2f(offset, offset));
  dragonRectShape.setFillColor(color);

  dragonBody.push_back(this->onGridRandom(part));
  this->makeHead();
}

void Dragon::makeHead() {
  this->headTexture.loadFromFile("src/assets/imgs/dragon/dragon.png");

  this->headSprite.setTexture(this->headTexture);
  this->headSprite.setPosition(dragonBody.at(dragonBody.size() - 1));
  this->headSprite.setScale(
    this->headSprite.getScale().x / 33 * offset, 
    this->headSprite.getScale().y / 33 * offset 
  );
  this->headSprite.setOrigin(this->headSprite.getScale().x * 4.125, 0);

  this->baseTexture.loadFromFile("src/assets/imgs/dragon/dragon-base.png");

  this->baseSprite.setTexture(this->headTexture);
  this->baseSprite.setPosition(this->headSprite.getPosition());

  this->baseSprite.setTextureRect(IntRect(344, 0, 43, 43));
  this->baseSprite.setScale(this->headSprite.getScale());
  this->baseSprite.setOrigin(this->headSprite.getOrigin());
  this->baseSprite.setColor(this->dragonRectShape.getFillColor());
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
    this->headSprite.setRotation(270);
    this->headSprite.setOrigin(38, 0);
    break;
  case 1:
    this->grow(0, -1);
    this->headSprite.setRotation(180);
    this->headSprite.setOrigin(38, 33);
    break;
  case 2:
    this->grow(-1, 0);
    this->headSprite.setRotation(90);
    this->headSprite.setOrigin(5, 33);
    break;
  case 3:
    this->grow(0, 1);
    this->headSprite.setRotation(0);
    this->headSprite.setOrigin(this->headSprite.getScale().x * 4.125, 0);
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

void Dragon::update() {
  this->move();

  this->headSprite.setPosition(dragonBody.at(this->dragonBody.size() - 1));
  this->baseSprite.setPosition(this->headSprite.getPosition());
  this->baseSprite.setRotation(this->headSprite.getRotation());
  this->baseSprite.setOrigin(this->headSprite.getOrigin());

  this->headSprite.setTextureRect(IntRect(
    43 * headAnimation->getFramePosition().x,
    0, 43, 43
  ));
}

void Dragon::draw(RenderWindow *pWindow) {
    for (int i = 0; i < dragonBody.size() - 1; i++) {
        dragonRectShape.setPosition(dragonBody.at(i).x, dragonBody.at(i).y);
        pWindow->draw(this->dragonRectShape);
    } 
    pWindow->draw(this->headSprite);
    pWindow->draw(this->baseSprite);
}