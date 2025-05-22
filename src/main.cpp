#include <SFML/Graphics.hpp>
#include <iostream>

int main() {

    sf::RenderWindow window(sf::VideoMode({800, 600}), "Journey Hero");
    sf::Font font;

    if (!font.openFromFile("fonts/arial.ttf")) {
        std::cerr << "Erro ao carregar fonte arial.ttf\n";
        return -1;
    }

    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        sf::CircleShape circle(100.f);
        circle.setFillColor(sf::Color::Green);
        circle.setPosition(sf::Vector2f(350.f, 250.f));

        sf::Text text(font);
        text.setString("Jogar");
        text.setCharacterSize(24);
        text.setFillColor(sf::Color::Red);
        text.setStyle(sf::Text::Bold | sf::Text::Underlined);
        window.draw(text);

        window.display();
    }

    return 0;
}
