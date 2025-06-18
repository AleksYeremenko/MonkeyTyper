#include "ResultState.h"
#include <iostream>

void ResultState::init(StateManager* manager, sf::RenderWindow* win) {
    stateManager = manager;
    window = win;

    if (!font.loadFromFile("assets/ARIAL.TTF")) {
        std::cerr << "Failed to load font!\n";
    }

    resultText.setFont(font);
    resultText.setCharacterSize(30);
    resultText.setFillColor(sf::Color::White);
    resultText.setPosition(100.f, 300.f);
    backHint.setFont(font);
    backHint.setCharacterSize(20);
    backHint.setFillColor(sf::Color::White);
    backHint.setPosition(100.f, 500.f);
    backHint.setString("Press ESC to return to menu");


}

void ResultState::setResult(int wordsTyped) {
    resultText.setString("Words Typed: " + std::to_string(wordsTyped));
}

void ResultState::handleEvent(const sf::Event& event) {
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
        stateManager->changeState(GameState::MENU);
    }
}

void ResultState::update() {

}

void ResultState::render() {
    if (!window) return;

    window->draw(resultText);
    window->draw(memeSprite);
    window->draw(backHint);
}
