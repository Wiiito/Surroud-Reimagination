#include "headers/scene.hpp"

// Constructors / Destructors

/**
 * Creates a game scene
 * @param name Give a name to the scene
 */
Scene::Scene(std::string name) { this->sceneName = name; }

Scene::Scene(std::string name, std::function<void()> func) { this->instanceFunction = func; }

Scene::~Scene() {}

// Functions

/**
 * Instantiate the current scene to memory
 * @public
 * @return void
 */
void Scene::instantiate() { this->instanceFunction(); }

/**
 * Adds a function to the scene.
 * Functions need to be added on the order they need to be executed.
 * @param func Function pointer to be added
 * @returns void
 */
void Scene::add(std::function<void()> func) { this->functionSet.push_back(func); }

/**
 * Runs scene functions
 *
 * @returns void
 */
void Scene::run() {
  for (auto&& fn : functionSet) {
    fn();
  }
}

// Get/Set Functions

/**
 * Gets scene name
 *
 * @returns String, scene name
 */
std::string Scene::getName() { return this->sceneName; }

/**
 * Adds a instace function to initiage the desired object
 * @param func Fuction that will instantiate the object
 * @return void
 */
void Scene::setInstanceFunction(std::function<void()> func) { this->instanceFunction = func; }
