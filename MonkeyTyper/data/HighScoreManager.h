#pragma once
#include <vector>
#include <string>

struct HighScoreEntry {
    std::string name;
    int wordsTyped;
    int timeLimit;
};

class HighScoreManager {
public:
    void addScore(const HighScoreEntry& entry);
    const std::vector<HighScoreEntry>& getScores() const;

private:
    std::vector<HighScoreEntry> scores;
};
