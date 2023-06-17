#include <SFML/Graphics.hpp>
#include <iostream>

#include "../headers/button.hpp"
#include "../headers/engine.hpp"

class TitleScreen {
  // Start button
  Button startButton;
  void initStartButton() {
    startButton.setSize(sf::Vector2f(100, 60));
    startButton.setBackgroundColor(sf::Color(255, 255, 255));
    startButton.setPosition(sf::Vector2f(0, 0));
  }

  Button settingsButton;
  void initSettingsButton() {
    settingsButton.setSize(sf::Vector2f(100, 60));
    settingsButton.setBackgroundColor(sf::Color(255, 255, 255));
    settingsButton.setPosition(sf::Vector2f(0, 70));
    settingsButton.setOutlineSize(5);
    settingsButton.setOutlineColor(sf::Color::Red);
  }

  sf::Font fonte;
  void initFonte() { fonte.loadFromFile("src/assets/fonts/JandaManateeSolid.ttf"); }

  void initVariables() {
    initFonte();
    initStartButton();
    initSettingsButton();
  }

 public:
  TitleScreen() { initVariables(); }
  void update() {}
  void render(sf::RenderWindow *pWindow) {
    this->startButton.render(pWindow);
    this->settingsButton.render(pWindow);
  }
};