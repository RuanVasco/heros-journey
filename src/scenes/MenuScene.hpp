#include "../Game.hpp"
#include "Scene.hpp"
#include <SFML/Graphics/Text.hpp>

class MenuScene : public Scene {
public:
    MenuScene(Game& game);

    void handleInput(sf::RenderWindow& window) override;
    void update() override;
    void draw(sf::RenderWindow& window) override;
private:
    Game& game;
    std::vector<sf::Text> menuItems;
    bool hovering = false;
};
