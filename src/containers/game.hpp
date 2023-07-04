#include <iostream>
#include <vector>
#include "../headers/dragon.hpp"
#include "../headers/engine.hpp"
using namespace sf;
using namespace std;
using std::vector;

class Game {
 private:
  Dragon dragons[2] = {Dragon(), Dragon()};
  Keyboard::Key keysDrag1[4] = {Keyboard::Right, Keyboard::Up, Keyboard::Left, Keyboard::Down};
  Keyboard::Key keysDrag2[4] = {Keyboard::D, Keyboard::W, Keyboard::A, Keyboard::S};
  
  float andadinha = 80;
  int contador = 0;

 public:
  Game() {
    dragons[0].setKeys(keysDrag1);
    dragons[1].setKeys(keysDrag2);
  }
  void update() {
      for (int i = 0; i <= 1; i++){
        for (int j = 0; j <= 3; j++){
          if (Keyboard::isKeyPressed(dragons[i].getKey(j))){
            dragons[i].setDirection(j);
          }
        }
      }

      if(contador == 0){
        for (int i = 0; i <= 1; i++){
          dragons[i].move();
        }
        
      } else if (contador == andadinha){
        contador = -1;
      }
      contador++;
    }
  void render(sf::RenderWindow *pWindow) {
    for (int i = 0; i <= 1; i++){
      dragons[i].update(pWindow);
    }
  }
};  