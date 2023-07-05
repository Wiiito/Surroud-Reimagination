#include <iostream>
#include <vector>
#include "../headers/dragon.hpp"
#include "../headers/engine.hpp"
using namespace sf;
using namespace std;
using std::vector;

class Game {
 private:
  Dragon dragons[2] = {Dragon(Color::Blue, 1), Dragon(Color::Red, 0)};
  Keyboard::Key keysDrag1[4] = {Keyboard::Right, Keyboard::Up, Keyboard::Left, Keyboard::Down};
  Keyboard::Key keysDrag2[4] = {Keyboard::D, Keyboard::W, Keyboard::A, Keyboard::S};
  
  float andadinha = 300;
  int contador = 0;
  RectangleShape lines;

 public:
  Game() {
    dragons[0].setKeys(keysDrag1);
    dragons[1].setKeys(keysDrag2);

    lines.setFillColor(Color(68, 68, 68));
  }
  void update() {
      for (int i = 0; i <= 1; i++){
        for (int j = 0; j <= 3; j++){
          if (Keyboard::isKeyPressed(dragons[i].getKey(j))){
            dragons[i].setDirection(j);
          }
        }
      }   

      if (dragons[0].dragonCollide(dragons[1].getBody()) || dragons[0].edgesCollide(Vector2f(0, 0), Vector2f(1280, 720))) {
        dragons[0].reinit();
        dragons[1].reinit();
      } else if (dragons[1].dragonCollide(dragons[0].getBody()) || dragons[1].edgesCollide(Vector2f(0, 0), Vector2f(1280, 720))) {
        dragons[0].reinit();
        dragons[1].reinit();
      }

      if(contador == 0){
        for (int i = 0; i <= 1; i++){
          dragons[i].update();
        }
        
      } else if (contador == andadinha){
        contador = -1;
      }
      contador++;
  }
  void render(sf::RenderWindow *pWindow) {
    for (int i = 0; i <= 1; i++){
      dragons[i].draw(pWindow);
    }

    lines.setSize(Vector2f(1, pWindow->getSize().y));
    for (int i = 0; i <= pWindow->getSize().x / 32; i++){
      lines.setPosition(i * pWindow->getSize().x / 32, 0);
      pWindow->draw(this->lines);
    }

    lines.setSize(Vector2f(pWindow->getSize().x, 1));
    for (int i = 0; i <= pWindow->getSize().y / 32; i++){
      lines.setPosition(0, i * pWindow->getSize().x / 32);
      pWindow->draw(this->lines);
    }
  }
};  