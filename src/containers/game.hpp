#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <algorithm>
#include <iostream>
#include <vector>

#include "../headers/dragon.hpp"
#include "../headers/engine.hpp"
#include "../headers/sound.hpp"

using namespace sf;
using namespace std;
using std::vector;

class Game {
 private:
  Dragon dragons[2] = {Dragon(Color::Blue, 1), Dragon(Color::Red, 0)};
  Keyboard::Key keysDrag1[4] = {Keyboard::Right, Keyboard::Up, Keyboard::Left, Keyboard::Down};
  Keyboard::Key keysDrag2[4] = {Keyboard::D, Keyboard::W, Keyboard::A, Keyboard::S};

  int player1Points = 0;
  int player2Points = 0;

  sf::Clock gameUpdateClock;  // Os dragões são atualizados conforme esse clock

  sf::Clock gameClock;  // Conta a quanto tempo o jogo esta rolando

  float gameVelocity = 250;

  RectangleShape lines;

  sf::Font timerFonte;
  sf::Text textTime;

  sf::CircleShape points;  // Pontinhos que serão desenhados na tela conforme a quantidade de pontos
                           // de cada jogador

  sf::SoundBuffer killBuffer;
  sf::Sound killSound;

 public:
  Game() {
    dragons[0].setKeys(keysDrag1);
    dragons[1].setKeys(keysDrag2);

    lines.setFillColor(Color(68, 68, 68));

    this->timerFonte.loadFromFile("src/assets/fonts/Yozakura.otf");

    this->textTime.setCharacterSize(40);
    this->textTime.setFont(this->timerFonte);
    this->textTime.setFillColor(sf::Color::White);
    this->textTime.setString("0:00");
    this->textTime.setOrigin(this->textTime.getLocalBounds().width / 2,
                             this->textTime.getLocalBounds().height / 2);
    this->textTime.setPosition(640, 0);

    this->points.setRadius(5.f);
    this->points.setFillColor(sf::Color::Red);
    this->points.setOrigin(this->points.getLocalBounds().width / 2,
                           this->points.getLocalBounds().height / 2);

    this->killBuffer.loadFromFile("src/assets/sounds/kill.ogg");
    this->killSound.setBuffer(killBuffer);
    this->killSound.setVolume(SoundControler::getFormatedEffectsVolume());
  }

  void update(Engine *pEngine) {
    for (int i = 0; i <= 1; i++) {
      for (int j = 0; j <= 3; j++) {
        if (Keyboard::isKeyPressed(dragons[i].getKey(j))) {
          dragons[i].setDirection(j);
        }
      }
    }

    std::vector<Vector2f> noHeadDragon = dragons[0].getBody();
    noHeadDragon.pop_back();

    std::vector<Vector2f> noHeadDragon2 = dragons[1].getBody();
    noHeadDragon2.pop_back();

    if (dragons[0].dragonCollide(dragons[1].getBody()) || dragons[0].dragonCollide(noHeadDragon) ||
        dragons[0].edgesCollide(Vector2f(-1, -1), Vector2f(1280, 720))) {
      dragons[0].reinit();
      dragons[1].reinit();

      this->killSound.play();

      this->player1Points++;
      this->gameVelocity = 250;
      this->gameClock.restart();

    } else if (dragons[1].dragonCollide(dragons[0].getBody()) ||
               dragons[1].dragonCollide(noHeadDragon2) ||
               dragons[1].edgesCollide(Vector2f(-1, -1), Vector2f(1280, 720))) {
      dragons[0].reinit();
      dragons[1].reinit();

      this->killSound.play();

      this->player2Points++;
      this->gameVelocity = 250;
      this->gameClock.restart();
    }

    if (gameUpdateClock.getElapsedTime().asMilliseconds() > this->gameVelocity) {
      for (int i = 0; i < 2; i++) {
        dragons[i].update();
        this->gameVelocity = std::max(this->gameVelocity - 0.5f, 75.f);
      }
      gameUpdateClock.restart();
    }

    if (player1Points > 2 || player2Points > 2) {
      pEngine->setCurrentScene("title");
    }

    this->textTime.setString(
        std::to_string(int(this->gameClock.getElapsedTime().asSeconds())) + ":" +
        std::to_string(int(this->gameClock.getElapsedTime().asMilliseconds() -
                           int(this->gameClock.getElapsedTime().asSeconds()) * 1000) /
                       10));
  }

  void render(sf::RenderWindow *pWindow) {
    lines.setSize(Vector2f(1, pWindow->getSize().y));
    for (int i = 0; i <= pWindow->getSize().x / 32; i++) {
      lines.setPosition(i * pWindow->getSize().x / 32, 0);
      pWindow->draw(this->lines);
    }

    lines.setSize(Vector2f(pWindow->getSize().x, 1));
    for (int i = 0; i <= pWindow->getSize().y / 32; i++) {
      lines.setPosition(0, i * pWindow->getSize().x / 32);
      pWindow->draw(this->lines);
    }

    for (int i = 0; i <= 1; i++) {
      dragons[i].draw(pWindow);
    }

    for (int i = 0; i < player1Points; i++) {
      this->points.setFillColor(sf::Color::Red);
      this->points.setPosition(610 - 15 * i, 25);
      pWindow->draw(this->points);
    }

    for (int i = 0; i < player2Points; i++) {
      this->points.setFillColor(sf::Color::Blue);
      this->points.setPosition(670 + 15 * i, 25);
      pWindow->draw(this->points);
    }

    pWindow->draw(this->textTime);
  }
};