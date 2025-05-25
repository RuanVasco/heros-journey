#include "../Game.hpp"
#include "Scene.hpp"
#include "BatteryScene.hpp"
#include <SFML/Graphics/Text.hpp>

class MenuScene : public Scene {
public:
    MenuScene(Game& game);

    void handleEvent(const sf::Event& event, sf::RenderWindow& window) override;
    void fixedUpdate() = 0;
    void update(const sf::Time& dt) override;
    void draw(sf::RenderWindow& window) override;
private:
    Game& game;
    std::vector<sf::Text> menuItems;
    bool hovering = false;
};
