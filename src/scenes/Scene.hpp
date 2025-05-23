#pragma once
#include <SFML/Graphics.hpp>

class Scene {
public:
    virtual ~Scene() = default;

    virtual void handleInput(sf::RenderWindow& window) = 0;
    virtual void update() = 0;
    virtual void draw(sf::RenderWindow& window) = 0;
};