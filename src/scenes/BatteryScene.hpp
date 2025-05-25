#include "../Game.hpp"
#include "Scene.hpp"
#include <SFML/Graphics.hpp>
#include "../input/KeyMap.hpp"

class BatteryScene : public Scene {
public:
    BatteryScene(Game& game);

    void handleEvent(const sf::Event& event, sf::RenderWindow& window) override;
    void fixedUpdate() = 0;
    void update(const sf::Time& dt) override;
    void draw(sf::RenderWindow& window) override;

private:
    Game& game;
    sf::CircleShape player;
    KeyMap keyMap;
};
