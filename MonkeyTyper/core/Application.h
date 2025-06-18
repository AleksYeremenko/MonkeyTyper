#pragma once
#include <SFML/Graphics.hpp>
#include "StateManager.h"
#include "GameState.h"


#include "../states/MenuState.h"
#include "../states/GameStatePlay.h"
#include "../states/HighScoreState.h"
#include "../states/SettingsState.h"
#include "../states/ResultState.h"
#include "../states/PauseState.h"
#include "../states/ExitConfirmState.h"

class Application {
public:
    Application();
    void run();

private:
    void processEvents();
    void update();
    void render();

    sf::RenderWindow window;
    StateManager stateManager;

    MenuState menuState;
    GameStatePlay gameState;
    HighScoreState highScoreState;
    SettingsState settingsState;
    ResultState resultState;
    PauseState pauseState;
    ExitConfirmState exitConfirmState;
};
