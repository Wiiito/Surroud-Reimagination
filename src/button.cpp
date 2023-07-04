#include "headers/button.hpp"

using namespace sf;
using std::function;
using std::vector;

// Constructors / Destructors

/**
 * Default constructor, doesn't recive any parameters and start with default values
 */
Button::Button() {}

/**
 * @param size Vector2f with button size
 * @param text Text with button's text
 */
Button::Button(Vector2f size, Text text) {}
Button::Button(Vector2f size, Text text, function<void()> callBack) {}
Button::Button(Vector2f size, Text text, function<void()> callBack, function<void()> hover) {}

Button::~Button() {}

// Functions

/**
 * Draws button on window
 * @param pWindow Window's pointer that the button will be draw
 * @return void
 * @public
 */
void Button::render(RenderWindow *pWindow) {
  // Updates state on mouse pos
  sf::Vector2i mousePos = Mouse::getPosition(*pWindow);

  sf::Color textOriginalColor = this->text.getFillColor();

  // Or hell, mas necessario... :/
  // Procura por possivel encontro com o mouse
  if (this->text.getGlobalBounds().contains(mousePos.x, mousePos.y) ||
      this->outlineRect.getGlobalBounds().contains(mousePos.x, mousePos.y) ||
      this->insideRect.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
    for (auto fn : this->hoverFunctions) {
      fn();
    }

    if (!mouseEntered) {
      this->hoverSound.play();
    }

    mouseEntered = true;

    if (Mouse::isButtonPressed(Mouse::Left)) {
      this->callBack();
      clickSound.play();
    }
  } else {
    mouseEntered = false;
  }

  pWindow->draw(this->outlineRect);
  pWindow->draw(this->insideRect);
  pWindow->draw(this->text);

  this->text.setFillColor(textOriginalColor);
  this->insideRect.setFillColor(this->backgroundColor);
  this->outlineRect.setFillColor(this->outlineColor);
}

// set / get Functions

/**
 * Set button inside size
 * @public
 * @param size Vector2f with button size
 * @return void
 */
void Button::setSize(sf::Vector2f size) { this->insideRect.setSize(size); }

/**
 * Clones the text its recives and display it in the middle of the button
 * @public
 * @param text Text component to be cloned
 * @return void
 */
void Button::setText(sf::Text text) {
  sf::Vector2f pos(this->insideRect.getPosition());
  sf::Vector2f halfSize(this->insideRect.getLocalBounds().width / 2,
                        this->insideRect.getLocalBounds().height / 2);

  this->text = text;
  this->text.setOrigin(this->text.getLocalBounds().width / 2, this->text.getCharacterSize() / 2);

  this->text.setPosition(sf::Vector2f(pos.x + halfSize.x, pos.y + halfSize.y));
}

/**
 * Set button position
 * @public
 * @param pos position in pixels at the screen
 * @return void
 */
void Button::setPosition(sf::Vector2f pos) {
  this->insideRect.setPosition(pos);
  this->outlineRect.setPosition(pos);
}

/**
 * Set button color
 * @public
 * @param color Color of the button
 * @return void
 */
void Button::setBackgroundColor(sf::Color color) { this->insideRect.setFillColor(color); }

/**
 * Set outline size
 * @public
 * @param size Outiline size in pixels
 * @return void
 */
void Button::setOutlineSize(float size) {
  this->outlineSize = size;
  this->outlineRect.setSize(sf::Vector2f(this->insideRect.getSize().x + 2 * size,
                                         this->insideRect.getSize().y + 2 * size));

  this->outlineRect.setOrigin(size, size);
}

/**
 * Set outline color
 * @public
 * @param color
 * @return void
 */
void Button::setOutlineColor(sf::Color color) { this->outlineRect.setFillColor(color); }

/**
 * Set a callback function on click
 * @public
 * @param function function that will be called (lambda)
 * @return void
 */
void Button::setCallbackFunction(function<void()> function) { this->callBack = function; }

// void Button::setHoverFunction() {}
// Ideia inicial era ter uma poder adicionar uma função para hover
// Mas para isso algum atributo teria que ficar publico, decidimos então
// evitar isso

/**
 * New color on hover, can be called multiple types for more effects
 * @public
 * @param elem Element type: TEXT, BACKGROUND, OUTLINE
 * @param newColor color that will be selected
 * @return void
 */
void Button::setColorOnHover(btnElement elem, sf::Color newColor) {
  switch (elem) {
    case TEXT:
      this->hoverFunctions.push_back(
          [this, newColor]() -> void { this->text.setFillColor(newColor); });
      break;

    case BACKGROUND:
      this->hoverFunctions.push_back(
          [this, newColor]() -> void { this->insideRect.setFillColor(newColor); });
      break;

    case OUTLINE:
      this->hoverFunctions.push_back(
          [this, newColor]() -> void { this->outlineRect.setFillColor(newColor); });
      break;
  }
}

/**
 * Set the button origin point
 * @public
 * @param originPos A Vector2F param that has max value 1 and min 0. Recives a % of where may the
 * origin point be located.
 * @return void
 */
void Button::setOrigin(Vector2f originPos) {}

// Sound related

/**
 * Adds a sound that will be played on hover
 * @public
 * @param soundBuffer sf::SoundBuffer with the buffer sound to be played
 * @return void
 */
void Button::setHoverSound(std::string path) {
  this->hoverSoundBuffer.loadFromFile(path);
  this->hoverSound.setBuffer(hoverSoundBuffer);
  this->hoverSound.setVolume(SoundControler::getFormatedMusicVolume());
}

/**
 * Adds a sound that will be played on click
 * @public
 * @param path path to sound
 * @return void
 */
void Button::setClickSound(std::string path) {
  this->clickSoundBuffer.loadFromFile(path);
  this->clickSound.setBuffer(clickSoundBuffer);
  this->hoverSound.setVolume(SoundControler::getFormatedMusicVolume());
}