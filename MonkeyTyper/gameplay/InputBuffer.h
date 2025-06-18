#pragma once
#include <string>
#include <SFML/Window/Event.hpp>

class InputBuffer {
public:
    void handleEvent(const sf::Event& event);
    void clear();
    const std::string& getText() const;

private:
    std::string input;
};
