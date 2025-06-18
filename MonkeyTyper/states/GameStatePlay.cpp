#include "GameStatePlay.h"
#include <iostream>
#include <algorithm>
#include "SettingsState.h"

void GameStatePlay::init(StateManager* manager, sf::RenderWindow* win) {
    stateManager = manager;
    window = win;
    settingsState = manager->settingsState;

    if (settingsState) {
        timeLimit = settingsState->getTimeLimit();
    }

    if (!font.loadFromFile("assets/ARIAL.TTF")) {
        std::cerr << "Failed to load font!" << std::endl;
    }

    timerText.setFont(font);
    timerText.setCharacterSize(30);
    timerText.setFillColor(sf::Color::White);
    timerText.setPosition(10.f, 10.f);

    scoreText.setFont(font);
    scoreText.setCharacterSize(30);
    scoreText.setFillColor(sf::Color::White);
    scoreText.setPosition(10.f, 50.f);

    skipNotification.setFont(font);
    skipNotification.setCharacterSize(20);
    skipNotification.setFillColor(sf::Color::Red);
    skipNotification.setString("Word skipped -5 points");
    skipNotification.setPosition(200.f, 10.f);

    monkey.init();
    isTiming = true;
    startTime = std::chrono::steady_clock::now();
    wordsTyped = 0;
    score = 0;
    showSkipNotification = false;
}

void GameStatePlay::handleEvent(const sf::Event& event) {
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
        stateManager->changeState(GameState::MENU);
    }

    else if (event.type == sf::Event::TextEntered) {
        if (event.text.unicode == ' ') {
            std::string typed = inputBuffer.getText();
            std::string expected = monkey.getCurrentTargetWord();

            if (!typed.empty()) {
                if (monkey.checkTypedWord(typed)) {
                    score += 10;
                } else {
                    int mistakes = 0;
                    for (std::size_t i = 0; i < std::min(typed.size(), expected.size()); ++i) {
                        if (typed[i] != expected[i]) mistakes++;
                    }
                    mistakes += std::abs(static_cast<int>(typed.size()) - static_cast<int>(expected.size()));

                    if (mistakes <= 1) {
                        monkey.consumeWordApproximate(typed);

                    }

                    score = std::max(0, score - 5);
                    showSkipNotification = true;
                    skipClock.restart();
                }
            }

            inputBuffer.clear();
        }

        else if (event.text.unicode >= 32 && event.text.unicode < 127) {
            inputBuffer.handleEvent(event);
            monkey.setCurrentInput(inputBuffer.getText());
        }
    }
}

void GameStatePlay::update() {
    float deltaTime = clock.restart().asSeconds();
    monkey.update(deltaTime);

    auto now = std::chrono::steady_clock::now();
    int elapsed = static_cast<int>(std::chrono::duration_cast<std::chrono::seconds>(now - startTime).count());
    timeRemaining = timeLimit - elapsed;

    if (timeRemaining <= 0) {
        isTiming = false;
        stateManager->changeState(GameState::RESULT);
        return;
    }

    timerText.setString("Time: " + std::to_string(timeRemaining) + " s");
    scoreText.setString("Score: " + std::to_string(score));

    if (showSkipNotification && skipClock.getElapsedTime().asSeconds() > 2.f) {
        showSkipNotification = false;
    }
}

void GameStatePlay::render() {
    window->draw(timerText);
    window->draw(scoreText);

    if (showSkipNotification) {
        window->draw(skipNotification);
    }

    monkey.draw(*window);
}
