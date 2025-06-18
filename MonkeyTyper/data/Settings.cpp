#include "Settings.h"

void Settings::setCharacterSize(int size) {
    characterSize = size;
}

int Settings::getCharacterSize() const {
    return characterSize;
}

void Settings::setFullscreen(bool enabled) {
    fullscreen = enabled;
}

bool Settings::isFullscreen() const {
    return fullscreen;
}

void Settings::setResolution(const sf::Vector2u& res) {
    resolution = res;
}

sf::Vector2u Settings::getResolution() const {
    return resolution;
}

void Settings::setUsername(const std::string& name) {
    username = name;
}

std::string Settings::getUsername() const {
    return username;
}
