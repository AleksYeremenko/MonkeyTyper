#include "HighScoreManager.h"

void HighScoreManager::addScore(const HighScoreEntry& entry) {
    scores.push_back(entry);

}

const std::vector<HighScoreEntry>& HighScoreManager::getScores() const {
    return scores;
}
