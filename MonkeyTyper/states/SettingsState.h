#pragma once
#include <SFML/Graphics.hpp>
#include "../core/StateManager.h"
#include "../core/GameState.h"

enum class Difficulty {
    Easy,
    Medium,
    Hard
};

class SettingsState {
public:
    void init(StateManager* manager, sf::RenderWindow* window);
    void handleEvent(const sf::Event& event);
    void update();
    void render();

    int getTimeLimit() const;
    Difficulty getDifficulty() const;

private:
    StateManager* stateManager = nullptr;
    sf::RenderWindow* window = nullptr;

    sf::Font font;
    sf::Text title;
    sf::Text inputText;
    sf::Text modeTitle;
    sf::Text easy;
    sf::Text medium;
    sf::Text hard;
    sf::Text hint;

    std::string inputBuffer;
    int timeLimit = 30;
    Difficulty selectedDifficulty = Difficulty::Medium;

    bool shouldReturnToMenu = false;
    sf::RectangleShape inputBox;

};
