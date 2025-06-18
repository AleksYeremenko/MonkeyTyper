#include "TextWrapper.h"
#include <sstream>

std::vector<std::string> TextWrapper::wrapText(
    const std::string& text,
    const sf::Font& font,
    unsigned int fontSize,
    float maxWidth
) {
    std::vector<std::string> lines;
    std::string word;
    std::string line;
    std::istringstream iss(text);

    while (iss >> word) {
        std::string testLine = line + word + " ";
        sf::Text testText(testLine, font, fontSize);

        if (testText.getLocalBounds().width > maxWidth) {
            lines.push_back(line);
            line = word + " ";
        } else {
            line = testLine;
        }
    }

    if (!line.empty()) {
        lines.push_back(line);
    }

    return lines;
}
