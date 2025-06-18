#include "Renderer.h"

Renderer::Renderer(sf::RenderWindow& win)
    : window(win) {}

void Renderer::beginFrame() {
    window.clear(sf::Color::Black);
}

void Renderer::draw(const sf::Drawable& drawable) {
    window.draw(drawable);
}

void Renderer::drawMonkey(const Monkey& monkey) {
    monkey.draw(window);
}

void Renderer::endFrame() {
    window.display();
}
