#pragma once
#include <SFML/Graphics.hpp>
#include "../gameplay/Monkey.h"

class Renderer {
public:
    explicit Renderer(sf::RenderWindow& window);

    void beginFrame();
    void draw(const sf::Drawable& drawable);
    void drawMonkey(const Monkey& monkey); // отрисовка Monkey по API
    void endFrame();

private:
    sf::RenderWindow& window;
};
