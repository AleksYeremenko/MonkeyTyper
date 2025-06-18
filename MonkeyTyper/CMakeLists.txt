cmake_minimum_required(VERSION 3.25)
project(MonkeyTyper)

set(CMAKE_CXX_STANDARD 20)
set(BUILD_SHARED_LIBS FALSE)

include(FetchContent)

# Загрузка SFML из GitHub
FetchContent_Declare(
    SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG        2.6.1
)

# Загрузка fmt из GitHub
FetchContent_Declare(
    fmt
    GIT_REPOSITORY https://github.com/fmtlib/fmt.git
    GIT_TAG        10.2.1
)

FetchContent_MakeAvailable(SFML fmt)

add_executable(MonkeyTyper
        main.cpp
        gameplay/Monkey.cpp
        core/Application.cpp
        core/StateManager.cpp
        core/StateManager.h
        core/GameState.h
        states/MenuState.cpp
        states/MenuState.h
        states/GameStatePlay.cpp
        states/GameStatePlay.h
        states/HighScoreState.cpp
        states/HighScoreState.h
        states/SettingsState.cpp
        states/SettingsState.h
        states/ResultState.cpp
        states/ResultState.h
        states/PauseState.cpp
        states/PauseState.h
        states/ExitConfirmState.cpp
        states/ExitConfirmState.h
        gameplay/WordGenerator.cpp
        gameplay/WordGenerator.h
        gameplay/InputBuffer.cpp
        gameplay/InputBuffer.h
        ui/Renderer.cpp
        ui/Renderer.h
        ui/TextWrapper.cpp
        ui/TextWrapper.h
        data/HighScoreManager.cpp
        data/HighScoreManager.h
        data/Settings.cpp
        data/Settings.h
)



target_link_libraries(MonkeyTyper
    sfml-graphics
    sfml-window
    sfml-system
    sfml-audio
    sfml-network
    fmt::fmt
)

target_compile_definitions(MonkeyTyper PRIVATE SFML_STATIC)
