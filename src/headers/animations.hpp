#pragma once

#include <SFML/Graphics.hpp>

// Animation system

enum AnimationType { idle, moving, jumping };

class Animation {
 private:
  int framesAmount;
  float timeBetween;
  sf::Vector2i startPositionInTexture;

  int currentFrame;
  sf::Clock measureFrameTime;

 public:
  Animation(int frames, float timeBetween, sf::Vector2i startPos);
  ~Animation();

  // Gets
  sf::Vector2i getFramePosition();
};