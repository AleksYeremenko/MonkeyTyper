#include "StateManager.h"
#include "GameState.h"

void StateManager::changeState(GameState newState) {
    currentState = newState;
}

GameState StateManager::getCurrentState() const {
    return currentState;
}
