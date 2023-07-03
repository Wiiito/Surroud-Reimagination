#include <iostream>

#include "../headers/dragon.hpp"
#include "../headers/engine.hpp"

class Game {
 private:
  Dragon dragon;

  sf::RectangleShape Background;

 public:
  Game(sf::RenderWindow *pWindow) {
    Background.setSize(Vector2f(pWindow->getSize().x, pWindow->getSize().y));
    Background.setFillColor(Color::White);
  }
  void update() {}
  void render(sf::RenderWindow *pWindow) {pWindow->draw(this->Background); dragon.update(pWindow); }
};  