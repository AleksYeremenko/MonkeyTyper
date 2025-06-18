
#include "WordGenerator.h"
#include <fstream>
#include <random>
#include <algorithm>
#include <iostream>

WordGenerator::WordGenerator() {
    loadWordsFromFile("assets/wordlist.txt");
}

void WordGenerator::loadWordsFromFile(const std::string& filename) {
    std::ifstream file(filename);
    std::string word;

    if (!file.is_open()) {
        std::cerr << "Could not open word list file: " << filename << std::endl;
        return;
    }

    while (file >> word) {
        wordPool.push_back(word);
    }

    std::cout << "Loaded " << wordPool.size() << " words from file.\n";
}

std::vector<std::string> WordGenerator::getWords(int count) const {
    std::vector<std::string> shuffled = wordPool;
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(shuffled.begin(), shuffled.end(), g);

    std::vector<std::string> result;
    for (int i = 0; i < count && i < static_cast<int>(shuffled.size()); ++i) {
        result.push_back(shuffled[i]);
    }
    return result;
}
