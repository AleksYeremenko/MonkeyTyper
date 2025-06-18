#pragma once
#include <SFML/Graphics.hpp>
#include <chrono>
#include "../core/StateManager.h"
#include "../core/GameState.h"
#include "../gameplay/Monkey.h"
#include "../gameplay/InputBuffer.h"

class GameStatePlay {
public:

    void init(StateManager* manager, sf::RenderWindow* window);
    void handleEvent(const sf::Event& event);
    void update();
    void render();
    int score = 0;
    sf::Text scoreText;

    sf::Text skipNotification;
    sf::Clock skipClock;
    bool showSkipNotification = false;



private:
    SettingsState* settingsState = nullptr;
    void processInput();
    InputBuffer inputBuffer;
    StateManager* stateManager = nullptr;
    sf::RenderWindow* window = nullptr;

    Monkey monkey;

    std::chrono::steady_clock::time_point startTime;
    bool isTiming = false;
    int timeLimit = 30;
    int wordsTyped = 0;

    sf::Font font;
    sf::Text timerText;
    int timeRemaining = 30; // добавить в .h
    sf::Clock clock;

};
