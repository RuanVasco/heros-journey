#pragma once

#include <SFML/Graphics.hpp>
#include "scenes/Scene.hpp"
#include <iostream>

class Game {
public:
    Game(unsigned width, unsigned height, const std::string& title);
    void run();

    void changeScene(std::unique_ptr<Scene> newScene);
    const sf::Font& getFont() const;
    const sf::Cursor& getArrowCursor() const { return arrowCursor; }
    const sf::Cursor& getHandCursor()  const { return handCursor; }
    const int getWindowHeight() const;
    const int getWindowWidth() const;
    sf::RenderWindow& getWindow();

private:
    unsigned width, height;
    std::string title;
    sf::RenderWindow window;
    sf::Font font;

    sf::Cursor arrowCursor;
    sf::Cursor handCursor;

    std::unique_ptr<Scene> currentScene;
};
