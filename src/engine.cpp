#include "headers/engine.hpp"

using namespace sf;

// Functions
void Engine::initVariables() {
  /*
    Public
    @return void

    Initialize game variables
      - Init pointers with values:
        - Window
  */

  // Window pointers initialization
  this->pWindow = nullptr;
  this->pVideoMode = nullptr;
  initWindow();
}

void Engine::initWindow() {
  /*
    Private
    @return void

    Initialize window
     - Create window object and appends it adress to window pointer
  */

  this->pVideoMode = new VideoMode(1280, 720);
  this->pWindow =
      new RenderWindow(*this->pVideoMode, "Surround Reimagined", Style::Close | Style::Titlebar);
}

void Engine::poolEvents() {
  /*
    Private
    @return void

    Pool window events
  */

  while (this->pWindow->pollEvent(this->event)) {
    if (this->event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
      this->pWindow->close();
    }
  }
}

void Engine::update() {
  /*
    Public
    @return void

    Updates game logic
  */
  this->poolEvents();
}

void Engine::render() {
  /*
    Public
    @return void

    Renders game on screen
  */

  this->pWindow->clear();

  this->pWindow->display();
}

// Get / Sets
bool Engine::getIsWindowOpen() { return this->pWindow->isOpen(); }

// Constructors / Destructors

Engine::Engine() { initVariables(); }

Engine::~Engine() {}