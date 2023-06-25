#include <functional>
#include <string>
#include <vector>

class Scene {
 private:
  // Attributes
  std::string sceneName;
  std::vector<std::function<void()>> functionSet;
  std::function<void()> instanceFunction;

 public:
  // Constructors / Destructors

  Scene(std::string name);
  Scene(std::string name, std::function<void()> func);
  ~Scene();

  // Functions

  void instantiate();
  void add(std::function<void()> func);
  void run();

  // Get/Set Functions

  std::string getName();

  void setInstanceFunction(std::function<void()> func);
};
