#pragma once
#include <SFML/Graphics.hpp>
#include "../core/StateManager.h"

class ResultState {
public:
    void init(StateManager* manager, sf::RenderWindow* window);
    void setResult(int wordsTyped);
    void handleEvent(const sf::Event& event);
    void update();
    void render();

private:
    StateManager* stateManager = nullptr;
    sf::RenderWindow* window = nullptr;

    sf::Font font;
    sf::Text resultText;
    sf::Text backHint;

    sf::Texture memeTexture;
    sf::Sprite memeSprite;
};
