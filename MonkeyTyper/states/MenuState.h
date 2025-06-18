#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include "../core/StateManager.h"
#include "../core/GameState.h"

class MenuState {
public:
    void init(StateManager* manager, sf::RenderWindow* window);
    void handleEvent(const sf::Event& event);
    void update();
    void render();

private:
    void updateMenuVisuals();

    StateManager* stateManager = nullptr;
    sf::RenderWindow* window = nullptr;

    sf::Font font;
    sf::Text title;
    std::vector<sf::Text> menuItems;
    int selectedItem = 0;
};
