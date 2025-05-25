#include "../Game.hpp"
#include "Scene.hpp"
#include <SFML/Graphics.hpp>

class GameScene : public Scene {
public:
    GameScene(Game& game);

    void handleEvent(const sf::Event& event, sf::RenderWindow& window) override;
    void update() override;
    void draw(sf::RenderWindow& window) override;

private:
    Game& game;
    sf::CircleShape player;
};
