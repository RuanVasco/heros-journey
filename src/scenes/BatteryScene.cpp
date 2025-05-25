#include "BatteryScene.hpp"

BatteryScene::BatteryScene(Game& game) : game(game) {
    player.setRadius(30.f);
    player.setFillColor(sf::Color::Green);
    player.setPosition({100.f, 100.f});
}

void BatteryScene::handleEvent(const sf::Event& event, sf::RenderWindow& window) {}

void BatteryScene::fixedUpdate() {}

void BatteryScene::update(const sf::Time& dt) {
    sf::Vector2f direction{0.f, 0.f};

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
        direction.y -= 1.f;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
        direction.y += 1.f;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
        direction.x -= 1.f;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
        direction.x += 1.f;

    if (direction != sf::Vector2f{0.f, 0.f}) {
        float length = std::sqrt(direction.x * direction.x + direction.y * direction.y);
        direction /= length;
        float speed = 175.f;
        player.move(direction * speed * dt.asSeconds());
    }
}

void BatteryScene::draw(sf::RenderWindow& window) {
    window.draw(player);
}
