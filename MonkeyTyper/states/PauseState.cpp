#include "PauseState.h"
#include <iostream>

void PauseState::init(StateManager* manager, sf::RenderWindow* win) {
    stateManager = manager;
    window = win;

    if (!font.loadFromFile("assets/ARIAL.TTF")) {
        std::cerr << "Failed to load font!\n";
    }

    pauseText.setFont(font);
    pauseText.setString("Press any key to continue");
    pauseText.setCharacterSize(30);
    pauseText.setFillColor(sf::Color::White);

    overlay.setSize(sf::Vector2f(window->getSize()));
    overlay.setFillColor(sf::Color(0, 0, 0, 128));
}

void PauseState::handleEvent(const sf::Event& event) {
    if (event.type == sf::Event::KeyPressed || event.type == sf::Event::TextEntered) {
        stateManager->changeState(GameState::GAME);
    }
}

void PauseState::update() {

}

void PauseState::render() {
    if (!window) return;

    window->draw(overlay);

    sf::Vector2u size = window->getSize();
    sf::FloatRect textBounds = pauseText.getLocalBounds();
    pauseText.setOrigin(textBounds.width / 2.f, textBounds.height / 2.f);
    pauseText.setPosition(size.x / 2.f, size.y / 2.f);

    window->draw(pauseText);
}
