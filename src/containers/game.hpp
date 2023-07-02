#include <iostream>

#include "../headers/engine.hpp"
#include "../headers/dragon.hpp"

class Game {
 private:
  RenderWindow *pWindow = nullptr;
  Dragon dragon;
 public:
  Game(RenderWindow *pWindow) {
    this->pWindow = pWindow;
    Dragon dragon;
  };
  void update() { }
  void render() { dragon.update(pWindow);}
};