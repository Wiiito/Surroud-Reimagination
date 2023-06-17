#pragma once

#include <SFML/Graphics.hpp>
#include <map>
#include <string>
#include <vector>

#include "scene.hpp"

class Engine {
 private:
  // Atributtes

  sf::VideoMode* pVideoMode;
  sf::RenderWindow* pWindow;

  sf::Event event;

  // Scene Atributtes

  Scene* currentScene;
  std::map<std::string, Scene*> scenesMap;

  // Functions

  void initWindow();
  void poolEvents();

 public:
  // Constructors / Destructors

  Engine();
  ~Engine();

  // Functions

  void initVariables();

  void updateGame();

  // Scene Functions

  void pushScene(Scene* cena);
  void setCurrentScene(std::string name);

  // Get / Set Functions

  bool getIsWindowOpen();
  sf::RenderWindow* getWindow();
};
