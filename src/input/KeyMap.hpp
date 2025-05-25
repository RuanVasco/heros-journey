#pragma once
#include <SFML/Window/Keyboard.hpp>
#include <unordered_map>
#include <optional>

enum class PlayerAction {
    MoveLeft,
    MoveRight,
    MoveUp,
    MoveDown
};

class KeyMap {
public:
    KeyMap();

    std::optional<PlayerAction> getAction(sf::Keyboard::Key key) const;

private:
    std::unordered_map<sf::Keyboard::Key, PlayerAction> map;
};
