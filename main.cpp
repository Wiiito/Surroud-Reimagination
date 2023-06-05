#include <SFML/Graphics.hpp>
#include <iostream>

#include "src/headers/engine.hpp"

void print() { std::cout << "print"; }

int main() {
  Engine gameEngine;

  Scene cena("cena");
  cena.add(print);
  gameEngine.pushScene(&cena);
  gameEngine.setCurrentScene("cena");

  while (gameEngine.getIsWindowOpen()) {
    gameEngine.updateGame();
  }
}