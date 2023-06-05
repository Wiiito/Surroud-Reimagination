#include "headers/engine.hpp"

using namespace sf;

// Functions

/**
 * Initialize game variables @paragraph
 * - Init pointers with values: @paragraph
 *  - Window
 * @public
 * @returns void
 */
void Engine::initVariables() {
  // Window pointers initialization
  this->pWindow = nullptr;
  this->pVideoMode = nullptr;

  this->currentScene = nullptr;
  this->scenesMap = {};

  initWindow();
}

/**
 * Initialize window @paragraph
 * - Create window object and appends it adress to window pointer
 * @private
 * @returns void
 */
void Engine::initWindow() {
  this->pVideoMode = new VideoMode(1280, 720);
  this->pWindow =
      new RenderWindow(*this->pVideoMode, "Surround Reimagined", Style::Close | Style::Titlebar);
}

/**
 * Pool window events
 *
 * @returns void
 * @private
 */
void Engine::poolEvents() {
  while (this->pWindow->pollEvent(this->event)) {
    if (this->event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
      this->pWindow->close();
    }
  }
}

/**
 * Updates game logic
 *
 * @returns void
 * @public
 */
void Engine::updateGame() {
  this->poolEvents();
  this->currentScene->run();
}

// Get / Sets

/**
 * Returns window state
 *
 * @returns bool, true for window open
 * @public
 */
bool Engine::getIsWindowOpen() { return this->pWindow->isOpen(); }

// Constructors / Destructors

Engine::Engine() { initVariables(); }

Engine::~Engine() {}

/**
 * Pushes a Scene to engines collection of scene @paragraph
 * - Puts its adress into a hashMap, so can be calledlater by its name
 *
 * @returns void
 * @param cena Scene address to be added to collection
 * @public
 */
void Engine::pushScene(Scene* cena) {
  scenesMap.insert(std::pair<std::string, Scene*>(cena->getName(), cena));
}

/**
 * Sets current scene
 * @returns void
 * @param name Scene name to be set to current scene
 * @public
 */
void Engine::setCurrentScene(std::string name) { currentScene = scenesMap[name]; }