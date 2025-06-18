#include "ExitConfirmState.h"
#include <iostream>

void ExitConfirmState::init(StateManager* manager, sf::RenderWindow* win) {
    stateManager = manager;
    window = win;

    if (!font.loadFromFile("assets/ARIAL.TTF")) {
        std::cerr << "Failed to load font!\n";
    }

    confirmText.setFont(font);
    confirmText.setString("Are you sure you want to exit?\nPress Enter to confirm, Esc to cancel.");
    confirmText.setCharacterSize(24);
    confirmText.setFillColor(sf::Color::White);

    backgroundBox.setFillColor(sf::Color(0, 0, 0, 200));
    backgroundBox.setOutlineColor(sf::Color::White);
    backgroundBox.setOutlineThickness(2.f);
}

void ExitConfirmState::handleEvent(const sf::Event& event) {
    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Enter) {
            window->close();
        } else if (event.key.code == sf::Keyboard::Escape) {
            stateManager->changeState(GameState::MENU);
        }
    }
}

void ExitConfirmState::update() {

}

void ExitConfirmState::render() {
    if (!window) return;

    sf::FloatRect bounds = confirmText.getLocalBounds();
    backgroundBox.setSize({bounds.width + 40.f, bounds.height + 40.f});
    backgroundBox.setOrigin(backgroundBox.getSize().x / 2.f, backgroundBox.getSize().y / 2.f);
    backgroundBox.setPosition(window->getSize().x / 2.f, window->getSize().y / 2.f);

    confirmText.setOrigin(bounds.width / 2.f, bounds.height / 2.f);
    confirmText.setPosition(window->getSize().x / 2.f, window->getSize().y / 2.f);

    window->draw(backgroundBox);
    window->draw(confirmText);
}
