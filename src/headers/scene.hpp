#include <string>
#include <vector>

// Defining function type
typedef void (*Function)();

class Scene {
 private:
  // Attributes
  std::string sceneName;
  std::vector<Function> functionSet;

 public:
  // Constructors / Destructors
  Scene(std::string name);
  ~Scene();

  // Functions
  void add(Function func);
  void run();

  // Get/Set Functions
  std::string getName();
};
