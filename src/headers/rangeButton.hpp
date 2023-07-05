#include <SFML/Graphics.hpp>
#include <functional>
#include <iostream>
#include <string>

#include "sound.hpp"

enum ButtonReference { MASTER, EFFECTS, MUSIC };

class RangeButton {
 private:
  sf::Texture backgroundTexture;
  sf::RectangleShape background;

  sf::Texture buttonTexture;
  sf::RectangleShape button;

  ButtonReference references = MASTER;

  sf::Vector2f pos;

  void updatePosition();

 public:
  RangeButton();
  ~RangeButton();

  void setBackground(std::string path);
  void setButton(std::string path);
  void setPosition(sf::Vector2f pos);

  void setReference(ButtonReference ref);

  void setButtonOrigin(sf::Vector2f pos);

  void render(sf::RenderWindow *pWindow);
};
