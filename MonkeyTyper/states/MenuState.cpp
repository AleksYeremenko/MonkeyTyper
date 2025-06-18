#include "MenuState.h"
#include <iostream>
#include "GameStatePlay.h"

void MenuState::init(StateManager* manager, sf::RenderWindow* win) {
    stateManager = manager;
    window = win;

    if (!font.loadFromFile("assets/ARIAL.TTF")) {
        std::cerr << "Failed to load font!" << std::endl;
    }

    title.setFont(font);
    title.setString("Monkey Typer");
    title.setCharacterSize(50);
    title.setFillColor(sf::Color::White);
    title.setPosition(200.f, 100.f);

    std::vector<std::string> labels = {"Start", "High Score", "Settings", "Exit"};
    for (const auto& label : labels) {
        sf::Text item(label, font, 40);
        item.setFillColor(sf::Color::White);
        menuItems.push_back(item);
    }

    updateMenuVisuals();
}

void MenuState::handleEvent(const sf::Event& event) {
    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Up) {
            selectedItem = (selectedItem - 1 + menuItems.size()) % menuItems.size();
            updateMenuVisuals();
        } else if (event.key.code == sf::Keyboard::Down) {
            selectedItem = (selectedItem + 1) % menuItems.size();
            updateMenuVisuals();
        } else if (event.key.code == sf::Keyboard::Enter || event.key.code == sf::Keyboard::E) {
            switch (selectedItem) {
                case 0:
                    if (stateManager->gameState && stateManager->settingsState) {
                        stateManager->gameState->init(stateManager, window);
                    }
                    stateManager->changeState(GameState::GAME);
                    break;

                case 1: stateManager->changeState(GameState::HIGHSCORE); break;
                case 2: stateManager->changeState(GameState::SETTINGS); break;
                case 3: window->close(); break;
            }
        }
    }
}

void MenuState::update() {

}

void MenuState::render() {
    if (!window) return;

    window->draw(title);

    for (size_t i = 0; i < menuItems.size(); ++i) {
        sf::Text& item = menuItems[i];

        sf::FloatRect bounds = item.getLocalBounds();
        item.setOrigin(bounds.width / 2.f, bounds.height / 2.f);
        item.setPosition(window->getSize().x / 2.f, 250.f + i * 60.f);

        window->draw(item);
    }
}

void MenuState::updateMenuVisuals() {
    for (size_t i = 0; i < menuItems.size(); ++i) {
        menuItems[i].setFillColor(i == selectedItem ? sf::Color::Red : sf::Color::White);
    }
}
