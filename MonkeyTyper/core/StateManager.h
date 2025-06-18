#pragma once
#include "GameState.h"

class MenuState;
class GameStatePlay;
class HighScoreState;
class SettingsState;
class ResultState;
class PauseState;
class ExitConfirmState;

class StateManager {
public:
    void changeState(GameState newState);
    GameState getCurrentState() const;


    MenuState* menuState = nullptr;
    GameStatePlay* gameState = nullptr;
    HighScoreState* highScoreState = nullptr;
    SettingsState* settingsState = nullptr;
    ResultState* resultState = nullptr;
    PauseState* pauseState = nullptr;
    ExitConfirmState* exitConfirmState = nullptr;

private:
    GameState currentState = GameState::MENU;
};
