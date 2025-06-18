#include "Application.h"
Application::Application()

    : window(sf::VideoMode(800, 600), "Monkey Typer") {

    window.setFramerateLimit(60);


    stateManager.menuState = &menuState;
    stateManager.gameState = &gameState;
    stateManager.highScoreState = &highScoreState;
    stateManager.settingsState = &settingsState;
    stateManager.resultState = &resultState;
    stateManager.pauseState = &pauseState;
    stateManager.exitConfirmState = &exitConfirmState;


    menuState.init(&stateManager, &window);

    highScoreState.init(&stateManager, &window);

    resultState.init(&stateManager, &window);
    pauseState.init(&stateManager, &window);
    exitConfirmState.init(&stateManager, &window);


    stateManager.changeState(GameState::MENU);
    settingsState.init(&stateManager, &window);

}

void Application::run() {
    while (window.isOpen()) {
        processEvents();
        update();
        render();
    }
}

void Application::processEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();

        switch (stateManager.getCurrentState()) {
            case GameState::MENU: menuState.handleEvent(event); break;
            case GameState::GAME: gameState.handleEvent(event); break;
            case GameState::HIGHSCORE: highScoreState.handleEvent(event); break;
            case GameState::SETTINGS: settingsState.handleEvent(event); break;
            case GameState::RESULT: resultState.handleEvent(event); break;
            case GameState::PAUSED: pauseState.handleEvent(event); break;
            case GameState::EXIT_CONFIRMATION: exitConfirmState.handleEvent(event); break;
        }
    }
}

void Application::update() {
    switch (stateManager.getCurrentState()) {
        case GameState::MENU: menuState.update(); break;
        case GameState::GAME: gameState.update(); break;
        case GameState::HIGHSCORE: highScoreState.update(); break;
        case GameState::SETTINGS: settingsState.update(); break;
        case GameState::RESULT: resultState.update(); break;
        case GameState::PAUSED: pauseState.update(); break;
        case GameState::EXIT_CONFIRMATION: exitConfirmState.update(); break;
    }
}

void Application::render() {
    window.clear();

    switch (stateManager.getCurrentState()) {
        case GameState::MENU: menuState.render(); break;
        case GameState::GAME: gameState.render(); break;
        case GameState::HIGHSCORE: highScoreState.render(); break;
        case GameState::SETTINGS: settingsState.render(); break;
        case GameState::RESULT: resultState.render(); break;
        case GameState::PAUSED: pauseState.render(); break;
        case GameState::EXIT_CONFIRMATION: exitConfirmState.render(); break;

    }

    window.display();
}
