#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include "WordGenerator.h"

class Monkey {
public:
    void init();
    void update(float deltaTime);
    void draw(sf::RenderWindow& window) const;

    std::string getCurrentTargetWord() const;
    void consumeWord();
    void consumeWordApproximate(const std::string& typed);



    void setCurrentInput(const std::string& input);
    std::string getCurrentInput() const { return currentInput; }

    bool checkTypedWord(const std::string& typedWord);

private:
    struct WordEntry {
        sf::Text text;
        float speed = 0.f;
        bool fading = false;
        float alpha = 255.f;
        sf::Clock fadeClock;
    };

    std::vector<WordEntry> textObjects;
    sf::Font font;
    std::string currentInput;

    WordGenerator generator;
    void generateWords();
};
