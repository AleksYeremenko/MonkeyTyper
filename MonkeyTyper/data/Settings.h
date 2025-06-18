#pragma once
#include <string>
#include <SFML/System/Vector2.hpp>

class Settings {
public:
    void setCharacterSize(int size);
    int getCharacterSize() const;

    void setFullscreen(bool enabled);
    bool isFullscreen() const;

    void setResolution(const sf::Vector2u& resolution);
    sf::Vector2u getResolution() const;

    void setUsername(const std::string& name);
    std::string getUsername() const;

private:
    int characterSize = 30;
    bool fullscreen = false;
    sf::Vector2u resolution = {800, 600};
    std::string username = "Player";
};
