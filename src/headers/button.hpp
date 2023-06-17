#pragma once

#include <SFML/Graphics.hpp>
#include <functional>

class Button {
 private:
  sf::Vector2f size = sf::Vector2f(0, 0);
  sf::Text text = sf::Text();
  sf::Color backgroundColor = sf::Color(sf::Color::Black);
  sf::Color outlineColor = sf::Color(sf::Color::Black);
  sf::RectangleShape outlineRect = sf::RectangleShape();
  sf::RectangleShape insideRect = sf::RectangleShape();

  float outlineSize = 0.f;

  std::function<void()> callBack = []() -> void {};
  std::function<void()> hover = []() -> void {};

 public:
  // Constructors / Destructors

  Button();
  Button(sf::Vector2f size, sf::Text text);
  Button(sf::Vector2f size, sf::Text text, std::function<void()> callBack);
  Button(sf::Vector2f size, sf::Text text, std::function<void()> callBack,
         std::function<void()> hover);
  ~Button();

  // Functions

  void render(sf::RenderWindow *pWindow);

  // get / set Functions

  void setSize(sf::Vector2f size);
  void setText(sf::Text text);
  void setPosition(sf::Vector2f pos);
  void setBackgroundColor(sf::Color color);
  void setOutlineSize(float size);
  void setOutlineColor(sf::Color color);
  void setCallbackFunction();
  void setHoverFunction();

  void setOrigin(sf::Vector2f originPos);
};
