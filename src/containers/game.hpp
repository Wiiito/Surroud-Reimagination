#include <iostream>

#include "../headers/dragon.hpp"
#include "../headers/engine.hpp"

class Game {
 private:
  RenderWindow *pWindow = nullptr;
  Dragon dragon;

 public:
  Game(RenderWindow *pWindow) {
    this->pWindow = pWindow;
    Dragon dragon;
  };

  void update() {}
  void render() { dragon.update(this->pWindow); }
};