#include <iostream>

#include "engine.hpp"

class Game {
 public:
  void update() { std::cout << "HaHa "; }
  void render() { std::cout << "HeHe "; }
};

class TitleScreen {
 public:
  void update() { std::cout << "BeBe "; }
  void render() { std::cout << "BaBa "; }
};