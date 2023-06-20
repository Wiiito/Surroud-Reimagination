#include <SFML/Graphics.hpp>
#include <iostream>

#include "../headers/button.hpp"
#include "../headers/engine.hpp"

class TitleScreen {
  // Background

  sf::Texture titleScreenBackgroundTexture;
  sf::RectangleShape titleScreenBackgroundRect;
  void initBackground() {
    this->titleScreenBackgroundTexture.loadFromFile("src/assets/imgs/mountainBackground.png");
    this->titleScreenBackgroundTexture.setSmooth(true);

    this->titleScreenBackgroundRect.setSize(sf::Vector2f(1280, 720));
    this->titleScreenBackgroundRect.setTexture(&this->titleScreenBackgroundTexture);
  }

  // Fontes

  sf::Font harukazeFonte;
  sf::Font yozakuraFonte;
  void initFonte() {
    this->harukazeFonte.loadFromFile("src/assets/fonts/Harukaze.otf");
    this->yozakuraFonte.loadFromFile("src/assets/fonts/Yozakura.otf");
  }

  // Tittle

  sf::Text titleText;
  void initTitleText() {
    this->titleText.setFont(this->harukazeFonte);
    this->titleText.setString("Surround");
    this->titleText.setCharacterSize(300);
    this->titleText.setOrigin(this->titleText.getLocalBounds().width / 2, 0);
    this->titleText.setFillColor(sf::Color(102, 0, 0));
    this->titleText.setPosition(640, -50);
  }

  // Buttons
  Button startButton;
  void initStartButton() {
    sf::Text startButtonText;
    startButtonText.setFont(yozakuraFonte);
    startButtonText.setString("Start");
    startButtonText.setCharacterSize(130);
    startButtonText.setFillColor(sf::Color(36, 13, 13));

    this->startButton.setPosition(sf::Vector2f(640, 330));
    this->startButton.setText(startButtonText);
  }

  Button settingsButton;
  void initSettingsButton() {
    sf::Text settingsButtonText;
    settingsButtonText.setFont(yozakuraFonte);
    settingsButtonText.setString("Settings");
    settingsButtonText.setCharacterSize(130);
    settingsButtonText.setFillColor(sf::Color(36, 13, 13));

    this->settingsButton.setPosition(sf::Vector2f(640, 450));
    this->settingsButton.setText(settingsButtonText);
  }

  Button quitButton;
  void initQuitButton() {
    sf::Text quitButtonText;
    quitButtonText.setFont(yozakuraFonte);
    quitButtonText.setString("Quit");
    quitButtonText.setCharacterSize(130);
    quitButtonText.setFillColor(sf::Color(36, 13, 13));

    this->quitButton.setPosition(sf::Vector2f(640, 580));
    this->quitButton.setText(quitButtonText);
  }

  void initVariables() {
    this->initBackground();
    this->initFonte();
    this->initTitleText();
    this->initStartButton();
    this->initSettingsButton();
    this->initQuitButton();
  }

 public:
  TitleScreen() { initVariables(); }
  void update() {}
  void render(sf::RenderWindow *pWindow) {
    pWindow->draw(this->titleScreenBackgroundRect);
    pWindow->draw(this->titleText);
    this->startButton.render(pWindow);
    this->settingsButton.render(pWindow);
    this->quitButton.render(pWindow);
  }
};