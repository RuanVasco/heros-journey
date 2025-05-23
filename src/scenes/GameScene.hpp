#pragma once
#include <memory>
#include <SFML/Graphics.hpp>

class Scene;

class Game {
public:
    Game(unsigned width, unsigned height);
    void run();
    void changeScene(std::unique_ptr<Scene> newScene);

private:
    sf::RenderWindow window;
    std::unique_ptr<Scene> currentScene;
};
