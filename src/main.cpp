#include <SFML/Graphics.hpp>
#include <iostream>
#include <optional>
#include <vector>
#include "Game.hpp"

int main() {
    Game game(800, 600, "Hero's Journey");
    game.run();
    return 0;
}
