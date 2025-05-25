#include "GameScene.hpp"

GameScene::GameScene(Game& game) : game(game) {
    player.setRadius(30.f);
    player.setFillColor(sf::Color::Green);
    player.setPosition({100.f, 100.f});
}

void GameScene::handleEvent(const sf::Event& event, sf::RenderWindow& window) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) {
        player.move({5.f, 0.f});
    }
}

void GameScene::update() {}

void GameScene::draw(sf::RenderWindow& window) {
    window.draw(player);
}
