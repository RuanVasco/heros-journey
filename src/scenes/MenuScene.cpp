#include "MenuScene.hpp"

MenuScene::MenuScene(Game& game) : game(game) {
    const std::vector<std::string> labels = {"Jogar", "Ver Pontuação"};

    const sf::Font& font = game.getFont();
    constexpr unsigned CHAR_SIZE = 36;
    constexpr float verticalSpacing = 60.f;

    for (std::size_t i = 0; i < labels.size(); ++i) {
        sf::Text text(font);
        text.setString(labels[i]);
        text.setCharacterSize(CHAR_SIZE);
        text.setFillColor(sf::Color::White);
        text.setStyle(sf::Text::Bold);

        const float blockHeight = labels.size() * verticalSpacing;
        const float startY      = (game.getWindowHeight() - blockHeight) / 2.f;

        sf::FloatRect bounds = text.getLocalBounds();
        text.setOrigin(bounds.getCenter());
        text.setPosition({game.getWindowWidth() / 2.f, startY + i * verticalSpacing});

        menuItems.push_back(text);
    }
}


void MenuScene::handleEvent(const sf::Event& event, sf::RenderWindow& window) {
    if (event.is<sf::Event::MouseMoved>()) {
        hovering = false;
        sf::Vector2f mousePos = static_cast<sf::Vector2f>(sf::Mouse::getPosition(window));
        for (auto& item : menuItems) {
            if (item.getGlobalBounds().contains(mousePos)) {
                item.setFillColor(sf::Color::Yellow);
                hovering = true;
            } else {
                item.setFillColor(sf::Color::White);
            }
        }
        window.setMouseCursor(hovering ? game.getHandCursor() : game.getArrowCursor());
    }

    if (const auto* mouse = event.getIf<sf::Event::MouseButtonPressed>()) {
        if (mouse->button == sf::Mouse::Button::Left) {
            sf::Vector2f mousePos = static_cast<sf::Vector2f>(sf::Mouse::getPosition(window));
            for (auto& item : menuItems) {
                if (item.getGlobalBounds().contains(mousePos)) {
                    if (item.getString() == "Jogar") {
                        game.changeScene(std::make_unique<BatteryScene>(game));
                        return;
                    } else if (item.getString() == "Ver Pontuação") {
                        std::cout << "Abrir placar...\n";
                    }
                }
            }
        }
    }
}

void MenuScene::update(const sf::Time& dt) {}
void BatteryScene::fixedUpdate() {}

void MenuScene::draw(sf::RenderWindow& window) {
    for (const auto& item : menuItems) {
        window.draw(item);
    }
}
