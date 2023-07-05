#include <SFML/Graphics.hpp>
#include <iostream>

#include "src/containers/game.hpp"
#include "src/containers/settings.hpp"
#include "src/containers/titleScreen.hpp"
#include "src/headers/sound.hpp"

int SoundControler::effectsVolume = 50;
int SoundControler::musicVolume = 50;
int SoundControler::globalVolume = 50;

/**
 * Todos os ponteiros para objetos do jogo são chamados aqui pois não podem ser retirados da
 * memoria. As cenas são configuradas aqui para evitar "param hell", em resumo, pra saber o que é o
 * que e de onde vem.
 */

int main() {
  std::srand(std::time(nullptr));

  // Initial sound configuration

  Engine gameEngine;

  sf::RenderWindow *pWindow = gameEngine.getWindow();

  // ---- Creating gameScene ----
  Game *game = new Game;
  Scene gameScene("game");
  gameScene.setInstanceFunction([&game]() -> void {
    delete (game);
    game = new Game;
  });
  gameScene.add([game, pWindow, &gameEngine]() -> void {
    game->update(&gameEngine);
    game->render(pWindow);
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

  // ---- Creating Settings Scene ----
  SettingsScreen *settingsScreen = new SettingsScreen(&gameEngine);
  Scene settingsSence("settings");
  settingsSence.setInstanceFunction([&settingsScreen, &gameEngine]() -> void {
    delete (settingsScreen);
    settingsScreen = new SettingsScreen(&gameEngine);
  });
  settingsSence.add([&settingsScreen, pWindow]() -> void { settingsScreen->render(pWindow); });
  gameEngine.pushScene(&settingsSence);

  // Set the initial scene
  gameEngine.setCurrentScene("title");

  // Runs the game
  while (gameEngine.getIsWindowOpen()) {
    gameEngine.updateGame();
  }
}
