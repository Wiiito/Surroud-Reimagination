#include <functional>
#include <string>
#include <vector>

class Scene {
 private:
  // Attributes
  std::string sceneName;
  std::vector<std::function<void()>> functionSet;

 public:
  // Constructors / Destructors

  Scene(std::string name);
  ~Scene();

  // Functions

  void add(std::function<void()> func);
  void run();

  // Get/Set Functions

  std::string getName();
};
