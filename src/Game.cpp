#include "Game.hpp"
#include "scenes/MenuScene.hpp"

Game::Game(unsigned width, unsigned height, const std::string& title)
    : width(width), height(height), title(title),
    window(sf::VideoMode({width, height}), title),
    arrowCursor(sf::Cursor::Type::Arrow),
    handCursor(sf::Cursor::Type::Hand)
{

    if (!this->font.openFromFile("assets/fonts/arial.ttf")) {
        std::cerr << "Erro ao carregar fonte arial.ttf\n";
        std::exit(1);
    }

    this->currentScene = std::make_unique<MenuScene>(*this);
}

const int Game::getWindowHeight() const {
    return this->window.getSize().y;
}

const int Game::getWindowWidth() const {
    return this->window.getSize().x;
}

const sf::Font& Game::getFont() const {
    return this->font;
}

void Game::changeScene(std::unique_ptr<Scene> newScene) {
    this->currentScene = std::move(newScene);
    window.setMouseCursor(arrowCursor);
}

void Game::run() {
    sf::Clock clock;
    const float fixedTimeStep = 1.f / 60.f;
    float accumulator = 0.f;

    while (window.isOpen()) {
        sf::Time dt = clock.restart();
        accumulator += dt.asSeconds();

        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>())
                window.close();

            if (event.has_value())
                currentScene->handleEvent(*event, window);
        }

        while (accumulator >= fixedTimeStep) {
            currentScene->fixedUpdate();
            accumulator -= fixedTimeStep;
        }

        currentScene->update(dt);

        window.clear();
        currentScene->draw(window);
        window.display();
    }
}
