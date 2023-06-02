#include <SFML/Graphics.hpp>

#include "src/headers/engine.hpp"

int main() {
  Engine gameEngine;

  while (gameEngine.getIsWindowOpen()) {
    gameEngine.update();
    gameEngine.render();
  }
}