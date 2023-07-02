#include <SFML/Graphics.hpp>
#include <iostream>

#include "src/containers/game.hpp"
#include "src/containers/titleScreen.hpp"

/**
 * Todos os ponteiros para objetos do jogo são chamados aqui pois não podem ser retirados da
 * memoria. As cenas são configuradas aqui para evitar "param hell", em resumo, pra saber o que é o
 * que e de onde vem.
 */

int main() {
  Engine gameEngine;

  sf::RenderWindow *pWindow = gameEngine.getWindow();

  // ---- Creating gameScene ----
  Game *game = new Game(pWindow);
  Scene gameScene("game");
  gameScene.setInstanceFunction([&game, pWindow]() -> void {
    delete (game);
    game = new Game(pWindow);
  });
  gameScene.add([game, pWindow]() -> void {
    game->update();
    game->render();
  });
  gameEngine.pushScene(&gameScene);

  // ---- Creating Title Scene ----
  TitleScreen *titleScreen = new TitleScreen(&gameEngine);
  Scene titleScene("title");
  titleScene.setInstanceFunction([&titleScreen, &gameEngine]() -> void {
    delete (titleScreen);
    titleScreen = new TitleScreen(&gameEngine);
  });
  titleScene.add([titleScreen]() -> void { titleScreen->update(); });
  titleScene.add([&titleScreen, pWindow]() -> void { titleScreen->render(pWindow); });
  gameEngine.pushScene(&titleScene);

  // Set the initial scene
  gameEngine.setCurrentScene("title");

  // Runs the game
  while (gameEngine.getIsWindowOpen()) {
    gameEngine.updateGame();
  }
}
