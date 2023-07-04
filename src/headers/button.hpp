#pragma once

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <functional>
#include <string>
#include <vector>

#include "sound.hpp"

enum btnElement { TEXT, BACKGROUND, OUTLINE };

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
  std::vector<std::function<void()>> hoverFunctions;

  // Sounds related
  sf::SoundBuffer hoverSoundBuffer;
  sf::SoundBuffer clickSoundBuffer;
  sf::Sound hoverSound;
  sf::Sound clickSound;

  bool mouseEntered = false;

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
  void setCallbackFunction(std::function<void()> function);
  void setColorOnHover(btnElement elem, sf::Color newColor);
  void setOrigin(sf::Vector2f originPos);

  // Sound related

  void setHoverSound(std::string path);
  void setClickSound(std::string path);
};
