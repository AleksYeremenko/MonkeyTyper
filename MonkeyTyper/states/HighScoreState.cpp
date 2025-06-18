#include "HighScoreState.h"
#include <iostream>

void HighScoreState::init(StateManager* manager, sf::RenderWindow* win) {
    stateManager = manager;
    window = win;

    if (!font.loadFromFile("assets/ARIAL.TTF")) {
        std::cerr << "Failed to load font!\n";
    }

    title.setFont(font);
    title.setString("High Scores");
    title.setCharacterSize(40);
    title.setPosition(250.f, 100.f);
    title.setFillColor(sf::Color::White);

    infoText.setFont(font);
    infoText.setString("Feature not implemented yet");
    infoText.setCharacterSize(20);
    infoText.setPosition(150.f, 300.f);
    infoText.setFillColor(sf::Color::White);

    backHint.setFont(font);
    backHint.setString("Press ESC to return to menu");
    backHint.setCharacterSize(20);
    backHint.setPosition(250.f, 500.f);
    backHint.setFillColor(sf::Color::White);

    if (memeTexture.loadFromFile("assets/cryingclown.jpg")) {
        memeSprite.setTexture(memeTexture);
        memeSprite.setPosition(100.f, 350.f);
    }
}

void HighScoreState::handleEvent(const sf::Event& event) {
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
        stateManager->changeState(GameState::MENU);
    }
}

void HighScoreState::update() {

}

void HighScoreState::render() {
    if (!window) return;

    window->draw(title);
    window->draw(infoText);
    window->draw(backHint);
    window->draw(memeSprite);
}
