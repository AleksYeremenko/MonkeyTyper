#include "SettingsState.h"
#include <iostream>

void SettingsState::init(StateManager* manager, sf::RenderWindow* win) {
    stateManager = manager;
    window = win;

    font.loadFromFile("assets/ARIAL.TTF");

    title.setFont(font);
    title.setString("Set Game Time (1-180 sec)");
    title.setCharacterSize(24);
    title.setFillColor(sf::Color::White);
    title.setPosition(40.f, 30.f);

    inputText.setFont(font);
    inputText.setCharacterSize(24);
    inputText.setFillColor(sf::Color::Green);
    inputText.setPosition(40.f, 80.f);

    inputBox.setSize({200.f, 35.f});
    inputBox.setPosition(inputText.getPosition().x - 5.f, inputText.getPosition().y - 5.f);
    inputBox.setFillColor(sf::Color(30, 30, 30));
    inputBox.setOutlineColor(sf::Color::White);
    inputBox.setOutlineThickness(2.f);
    inputText.setPosition(50.f, 85.f);
    inputText.setFillColor(sf::Color::Green);
    inputText.setPosition(50.f, 85.f);
    inputBox.setFillColor(sf::Color::Red);



    modeTitle.setFont(font);
    modeTitle.setString("Select Difficulty:");
    modeTitle.setCharacterSize(20);
    modeTitle.setFillColor(sf::Color::White);
    modeTitle.setPosition(40.f, 130.f);

    easy.setFont(font);
    easy.setCharacterSize(20);
    easy.setPosition(60.f, 170.f);

    medium.setFont(font);
    medium.setCharacterSize(20);
    medium.setPosition(60.f, 210.f);

    hard.setFont(font);
    hard.setCharacterSize(20);
    hard.setPosition(60.f, 250.f);

    hint.setFont(font);
    hint.setString("(1-3: mode, Enter: OK, Esc: cancel)");
    hint.setCharacterSize(16);
    hint.setFillColor(sf::Color(200, 200, 200));
    hint.setPosition(40.f, 330.f);
}

void SettingsState::handleEvent(const sf::Event& event) {
    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Escape) {
            shouldReturnToMenu = true;
        } else if (event.key.code == sf::Keyboard::Enter) {
            if (!inputBuffer.empty()) {
                int val = std::stoi(inputBuffer);
                if (val >= 1 && val <= 180) {
                    timeLimit = val;
                    std::cout << "Time limit set to: " << timeLimit << " seconds\n";
                } else {
                    std::cout << "Invalid value (1–180 sec)\n";
                }
            }
            shouldReturnToMenu = true;
        } else if (event.key.code == sf::Keyboard::Up) {
            if (selectedDifficulty == Difficulty::Medium)
                selectedDifficulty = Difficulty::Easy;
            else if (selectedDifficulty == Difficulty::Hard)
                selectedDifficulty = Difficulty::Medium;
        }
        else if (event.key.code == sf::Keyboard::Down) {
            if (selectedDifficulty == Difficulty::Easy)
                selectedDifficulty = Difficulty::Medium;
            else if (selectedDifficulty == Difficulty::Medium)
                selectedDifficulty = Difficulty::Hard;
        }

    } else if (event.type == sf::Event::TextEntered) {
        if (std::isdigit(event.text.unicode)) {
            inputBuffer += static_cast<char>(event.text.unicode);
        } else if (event.text.unicode == 8 && !inputBuffer.empty()) {
            inputBuffer.pop_back();
        }
    }
}

void SettingsState::update() {
    inputText.setString(inputBuffer);

    easy.setString(selectedDifficulty == Difficulty::Easy ? "[X] Easy" : "[ ] Easy");
    medium.setString(selectedDifficulty == Difficulty::Medium ? "[X] Medium" : "[ ] Medium");
    hard.setString(selectedDifficulty == Difficulty::Hard ? "[X] Hard" : "[ ] Hard");

    if (shouldReturnToMenu) {
        stateManager->changeState(GameState::MENU);
    }
}

void SettingsState::render() {
    if (!window) return;

    window->draw(title);
    window->draw(inputBox);
    window->draw(inputText);
    window->draw(modeTitle);
    window->draw(easy);
    window->draw(medium);
    window->draw(hard);
    window->draw(hint);

}

int SettingsState::getTimeLimit() const {
    return timeLimit;
}

Difficulty SettingsState::getDifficulty() const {
    return selectedDifficulty;
}
