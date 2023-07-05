#include "headers/animations.hpp"

// Constructors / Destructors
Animation::Animation(int frames, float timeBetween, sf::Vector2i startPos) {
  this->framesAmount = frames;
  this->timeBetween = timeBetween;
  this->startPositionInTexture = startPos;
  this->currentFrame = 0;
}

Animation::~Animation(){};

// Gets
sf::Vector2i Animation::getFramePosition() {
  if (this->timeBetween <= this->measureFrameTime.getElapsedTime().asSeconds()) {
    this->measureFrameTime.restart();
    currentFrame++;
    if (currentFrame >= framesAmount) currentFrame = 0;
  }

  return sf::Vector2i(this->startPositionInTexture.x + this->currentFrame,
                      this->startPositionInTexture.y);
}