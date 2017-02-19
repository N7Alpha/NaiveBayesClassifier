//
//  WordHeuristic.hpp
//  NaiveBayesClassifier
//
//  Created by John Rehbein on 2/11/17.
//  Copyright © 2017 John Rehbein. All rights reserved.
//

#ifndef WordHeuristic_hpp
#define WordHeuristic_hpp

#include <stdio.h>
#include <unordered_map>
#include "Heuristic.hpp"

// This class is the conditional probabilities of words
class WordHeuristic : public Heuristic {
private:
    probability_t alpha = 1.0;
    probability_t wordCount = 0;
    std::unordered_map<std::string, int> wordFrequency[2];
    
public:
    probability_t logProbability(Document doc, Category c);
    void trainForCategory(Document doc, Category c);
    
};

#endif /* WordHeuristic_hpp */
