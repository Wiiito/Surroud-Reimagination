#include "headers/scene.hpp"

// Constructors / Destructors

/**
 * Creates a game scene
 * @param name Give a name to the scene
 */
Scene::Scene(std::string name) { this->sceneName = name; }

Scene::~Scene() {}

// Functions

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
