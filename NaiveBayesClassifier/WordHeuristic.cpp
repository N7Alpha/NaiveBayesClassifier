//
//  WordHeuristic.cpp
//  NaiveBayesClassifier
//
//  Created by John Rehbein on 2/11/17.
//  Copyright © 2017 John Rehbein. All rights reserved.
//

#include "WordHeuristic.hpp"
#include <vector>

void WordHeuristic::trainForCategory(Document doc, Category c) {
    const std::vector<std::string> words = doc.getWords();
    for (int i = 0; i < words.size(); i++) {
        std::string word = words[i];
        wordFrequency[c][word]++;
        wordCount++;
    }
}

probability_t WordHeuristic::logProbability(Document doc, Category c) {
    const std::vector<std::string> words = doc.getWords();
    probability_t runningProbability = 0;
    for (int i = 0; i < words.size(); i++) {
        std::string word = words[i];
        runningProbability += log((wordFrequency[c][word] + alpha) / ( alpha * wordFrequency[c].size() + wordCount));
    }
    
    return runningProbability;
}
