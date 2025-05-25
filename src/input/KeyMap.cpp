#include "Input/KeyMap.hpp"

KeyMap::KeyMap() {
    map[sf::Keyboard::Key::A] = PlayerAction::MoveLeft;
    map[sf::Keyboard::Key::D] = PlayerAction::MoveRight;
    map[sf::Keyboard::Key::W] = PlayerAction::MoveUp;
    map[sf::Keyboard::Key::S] = PlayerAction::MoveDown;
}

std::optional<PlayerAction> KeyMap::getAction(sf::Keyboard::Key key) const {
    auto it = map.find(key);
    if (it != map.end()) return it->second;
    return std::nullopt;
}
