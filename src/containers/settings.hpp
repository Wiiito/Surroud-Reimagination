#include <SFML/Graphics.hpp>
#include <string>
#include <vector>

#include "../headers/button.hpp"
#include "../headers/engine.hpp"
#include "../headers/rangeButton.hpp"
#include "../headers/sound.hpp"

class SettingsScreen {
 private:
  Engine *pEngine;

  sf::Texture screenBackgroundTexture;
  sf::RectangleShape screenBackgroundRect;
  void initBackground() {
    this->screenBackgroundTexture.loadFromFile("src/assets/imgs/mountainBackground.png");
    this->screenBackgroundTexture.setSmooth(true);

    this->screenBackgroundRect.setSize(sf::Vector2f(1280, 720));
    this->screenBackgroundRect.setTexture(&this->screenBackgroundTexture);
  }

  sf::Font kashimaFonte;
  sf::Font yozakuraFonte;
  void initFonte() {
    this->kashimaFonte.loadFromFile("src/assets/fonts/Kashima.otf");
    this->yozakuraFonte.loadFromFile("src/assets/fonts/Yozakura.otf");
  }

  std::vector<sf::Text> settingsText;
  void initSettingsText() {
    std::string settingsStr = "Settings";
    for (int i = 0; i < settingsStr.size(); i++) {
      sf::Text letrinha;
      letrinha.setString(settingsStr[i]);
      letrinha.setFont(this->kashimaFonte);
      letrinha.setCharacterSize(108);
      letrinha.setFillColor(sf::Color(102, 0, 0));
      letrinha.setPosition(sf::Vector2f(75, 0 + 80 * i));
      settingsText.push_back(letrinha);
    }
  }

  sf::Texture volumeTowerTexture;
  sf::RectangleShape volumeTower;
  void initVolumeTower() {
    this->volumeTowerTexture.loadFromFile("src/assets/imgs/volumes.png");

    this->volumeTower.setSize(sf::Vector2f(483, 698));
    this->volumeTower.setTexture(&this->volumeTowerTexture);
    this->volumeTower.setPosition(sf::Vector2f(412, 32));
  }

  RangeButton masterVolumeRange;
  void initMasterVolume() {
    this->masterVolumeRange.setBackground("src/assets/imgs/WindowBar.png");
    this->masterVolumeRange.setPosition(sf::Vector2f(655, 156));

    this->masterVolumeRange.setButton("src/assets/imgs/Lantern.png");
    this->masterVolumeRange.setButtonOrigin(sf::Vector2f(13, 42));
  }

  RangeButton fxVolumeRange;
  void initFxVolume() {
    this->fxVolumeRange.setBackground("src/assets/imgs/WindowBar.png");
    this->fxVolumeRange.setPosition(sf::Vector2f(655, 318));

    this->fxVolumeRange.setButton("src/assets/imgs/Lantern.png");
    this->fxVolumeRange.setButtonOrigin(sf::Vector2f(13, 42));
  }

  RangeButton musicVolumeRange;
  void initMusicVolume() {
    this->musicVolumeRange.setBackground("src/assets/imgs/WindowBar.png");
    this->musicVolumeRange.setPosition(sf::Vector2f(655, 480));

    this->musicVolumeRange.setButton("src/assets/imgs/Lantern.png");
    this->musicVolumeRange.setButtonOrigin(sf::Vector2f(13, 42));
  }

  Button backButton;
  void initBackButton() {
    Text backText;
    backText.setString("< BACK");
    backText.setFont(this->yozakuraFonte);
    backText.setCharacterSize(50);
    backText.setFillColor(sf::Color(36, 13, 13));

    this->backButton.setPosition(sf::Vector2f(1200, 20));
    this->backButton.setText(backText);

    this->backButton.setCallbackFunction(
        [this]() -> void { this->pEngine->setCurrentScene("title"); });
  }

  void initVariables() {
    this->initFonte();
    this->initBackground();
    this->initSettingsText();
    this->initVolumeTower();
    this->initMasterVolume();
    this->initFxVolume();
    this->initMusicVolume();
    this->initBackButton();
  }

 public:
  SettingsScreen(Engine *pEngine) {
    this->pEngine = pEngine;
    this->initVariables();
  }

  void render(sf::RenderWindow *pWindow) {
    pWindow->draw(this->screenBackgroundRect);

    for (int i = 0; i < settingsText.size(); i++) {
      pWindow->draw(this->settingsText[i]);
    }

    pWindow->draw(this->volumeTower);

    this->backButton.render(pWindow);

    this->masterVolumeRange.render(pWindow);
    this->fxVolumeRange.render(pWindow);
    this->musicVolumeRange.render(pWindow);
  }
};