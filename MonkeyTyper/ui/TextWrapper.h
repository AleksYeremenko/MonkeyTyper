#pragma once
#include <vector>
#include <string>
#include <SFML/Graphics.hpp>

class TextWrapper {
public:
    // Делит текст на строки так, чтобы они не выходили за maxWidth
    static std::vector<std::string> wrapText(
        const std::string& text,
        const sf::Font& font,
        unsigned int fontSize,
        float maxWidth
    );
};
