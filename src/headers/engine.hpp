#include <SFML/Graphics.hpp>

class Engine {
 private:
  // Atributes
  sf::VideoMode* pVideoMode;
  sf::RenderWindow* pWindow;

  sf::Event event;

  // Functions
  void initWindow();
  void poolEvents();

 public:
  // Constructors / Destructors
  Engine();
  ~Engine();

  // Functions
  void initVariables();

  void update();
  void render();

  // Get / Set Functions
  bool getIsWindowOpen();
};
