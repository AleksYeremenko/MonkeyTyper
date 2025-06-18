
#pragma once
#include <vector>
#include <string>

class WordGenerator {
public:
    WordGenerator();
    std::vector<std::string> getWords(int count) const;

private:
    std::vector<std::string> wordPool;
    void loadWordsFromFile(const std::string& filename);
};
