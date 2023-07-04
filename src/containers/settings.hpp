#include <SFML/Graphics.hpp>

#include "../headers/engine.hpp"

class SettingsScreen {
 private:
  Engine *pEngine;

  sf::RectangleShape shape;

 public:
  SettingsScreen(Engine *pEngine) {
    // Engine Pointer
    this->pEngine = pEngine;

    shape.setFillColor(sf::Color::Red);
    shape.setPosition(0, 0);
    shape.setSize(sf::Vector2f(50, 50));
  }

  void render(sf::RenderWindow *pWindow) { pWindow->draw(this->shape); }
};