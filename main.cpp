#include <SFML/Graphics.hpp>
#include <iostream>

#include "src/headers/sceneCollection.hpp"

// Delete na current
// Callback q inicia o obj do game

int main() {
  Engine gameEngine;

  sf::RenderWindow *pWindow = gameEngine.getWindow();

  Game *game = new Game;
  TitleScreen *titleScreen = new TitleScreen(&gameEngine);

  Scene gameScene("game");
  gameScene.setInstanceFunction([&game]() -> void {
    delete (game);
    game = new Game;
  });
  gameScene.add([game]() -> void {
    game->update();
    game->render();
  });
  gameEngine.pushScene(&gameScene);

  Scene titleScene("title");
  titleScene.setInstanceFunction([&titleScreen, &gameEngine]() -> void {
    delete (titleScreen);
    titleScreen = new TitleScreen(&gameEngine);
  });
  titleScene.add([titleScreen]() -> void { titleScreen->update(); });
  titleScene.add([&titleScreen, pWindow]() -> void { titleScreen->render(pWindow); });
  gameEngine.pushScene(&titleScene);

  gameEngine.setCurrentScene("title");

  while (gameEngine.getIsWindowOpen()) {
    gameEngine.updateGame();
  }
}
