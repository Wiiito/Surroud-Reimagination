#include <SFML/Graphics.hpp>
#include <iostream>

#include "src/headers/sceneCollection.hpp"

int main() {
  Engine gameEngine;

  sf::RenderWindow *pWindow = gameEngine.getWindow();

  Game *game = new Game;

  Scene gameScene("game");

  gameScene.add([game]() -> void {
    game->update();
    game->render();
  });

  gameEngine.pushScene(&gameScene);

  TitleScreen *titleScreen = new TitleScreen;

  Scene titleScene("title");

  titleScene.add([titleScreen]() -> void { titleScreen->update(); });
  titleScene.add([titleScreen, pWindow]() -> void { titleScreen->render(pWindow); });

  gameEngine.pushScene(&titleScene);

  gameEngine.setCurrentScene("title");

  while (gameEngine.getIsWindowOpen()) {
    gameEngine.updateGame();
  }
}
