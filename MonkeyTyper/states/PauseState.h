#pragma once
#include <SFML/Graphics.hpp>
#include "../core/StateManager.h"

class PauseState {
public:
    void init(StateManager* manager, sf::RenderWindow* window);
    void handleEvent(const sf::Event& event);
    void update();
    void render();

private:
    StateManager* stateManager = nullptr;
    sf::RenderWindow* window = nullptr;

    sf::Font font;
    sf::Text pauseText;
    sf::RectangleShape overlay;
};
