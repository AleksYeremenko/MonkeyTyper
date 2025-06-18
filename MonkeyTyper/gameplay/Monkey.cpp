#include "Monkey.h"
#include <iostream>
#include <cstdlib>

void Monkey::init() {
    if (!font.loadFromFile("assets/Roboto-Regular.ttf")) {
        std::cerr << "Could not load font!" << std::endl;
    }
    generateWords();
    currentInput.clear();
}

std::string Monkey::getCurrentTargetWord() const {
    return !textObjects.empty() ? textObjects[0].text.getString() : "";
}

void Monkey::consumeWord() {
    if (!textObjects.empty()) {
        textObjects[0].fading = true;
        textObjects[0].fadeClock.restart();
        currentInput.clear();
    }
}

void Monkey::consumeWordApproximate(const std::string& typed) {
    for (auto& word : textObjects) {
        std::string target = word.text.getString();
        int mistakes = 0;
        for (std::size_t i = 0; i < std::min(typed.size(), target.size()); ++i) {
            if (typed[i] != target[i]) mistakes++;
        }
        mistakes += std::abs(static_cast<int>(typed.size()) - static_cast<int>(target.size()));

        if (mistakes <= 1 && !word.fading) {
            word.fading = true;
            word.fadeClock.restart();
            currentInput.clear();
            break;
        }
    }
}



void Monkey::generateWords() {
    WordGenerator generator;
    auto words = generator.getWords(5);
    textObjects.clear();

    for (size_t i = 0; i < words.size(); ++i) {
        WordEntry entry;
        entry.text.setFont(font);
        entry.text.setString(words[i]);
        entry.text.setCharacterSize(30);
        entry.text.setFillColor(sf::Color::White);
        entry.text.setPosition(800.f, 100.f + i * 50.f);
        entry.speed = 50.f + static_cast<float>(rand() % 100);
        entry.fading = false;
        entry.alpha = 255.f;
        textObjects.push_back(entry);
    }
}

void Monkey::setCurrentInput(const std::string& input) {
    currentInput = input;
}

bool Monkey::checkTypedWord(const std::string& typedWord) {
    if (textObjects.empty()) return false;

    std::string expected = textObjects[0].text.getString();
    if (typedWord.empty()) return false;

    if (typedWord == expected) {
        consumeWord();
        return true;
    }

    currentInput.clear();
    return false;
}

void Monkey::update(float deltaTime) {
    for (auto& word : textObjects) {
        sf::Vector2f pos = word.text.getPosition();
        pos.x -= word.speed * deltaTime;
        word.text.setPosition(pos);

        if (word.fading) {
            float elapsed = word.fadeClock.getElapsedTime().asSeconds();
            word.alpha = 255.f * (1.f - std::min(elapsed / 0.4f, 1.f));
            sf::Color c = word.text.getFillColor();
            c.a = static_cast<sf::Uint8>(word.alpha);
            word.text.setFillColor(c);
        }
    }

    textObjects.erase(
        std::remove_if(textObjects.begin(), textObjects.end(), [](const WordEntry& w) {
            return w.fading && w.alpha <= 0.f;
        }),
        textObjects.end()
    );

    bool allOffScreen = true;
    for (const auto& obj : textObjects) {
        if (obj.text.getPosition().x + obj.text.getLocalBounds().width > 0) {
            allOffScreen = false;
            break;
        }
    }

    if (allOffScreen) {
        currentInput.clear();
        generateWords();
    }
}

void Monkey::draw(sf::RenderWindow& window) const {
    for (size_t i = 0; i < textObjects.size(); ++i) {
        const auto& entry = textObjects[i];
        const sf::Text& original = entry.text;

        std::string word = original.getString();
        sf::Vector2f pos = original.getPosition();
        unsigned int size = original.getCharacterSize();
        const sf::Font* fnt = original.getFont();
        float x = pos.x;

        if (i == 0 && !entry.fading) {
            for (std::size_t j = 0; j < word.size(); ++j) {
                sf::Text letter(std::string(1, word[j]), *fnt, size);
                letter.setPosition(x, pos.y);

                if (j < currentInput.size()) {
                    if (currentInput[j] == word[j])
                        letter.setFillColor(sf::Color::Green);
                    else
                        letter.setFillColor(sf::Color::Red);
                } else {
                    letter.setFillColor(sf::Color::White);
                }

                window.draw(letter);
                x += letter.getLocalBounds().width + 1.0f;
            }
        } else {
            window.draw(original);
        }
    }
}
