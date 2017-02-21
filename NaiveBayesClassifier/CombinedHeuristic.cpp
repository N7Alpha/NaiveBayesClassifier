//
//  CombinedHeuristic.cpp
//  NaiveBayesClassifier
//
//  Created by John Rehbein on 2/11/17.
//  Copyright © 2017 John Rehbein. All rights reserved.
//

#include "CombinedHeuristic.hpp"

void CombinedHeuristic::trainForCategory(Document &doc, Category c) {
    for (std::pair<Heuristic*, double> h : heuristics) {
        h.first->trainForCategory(doc, c);
    }
}

probability_t CombinedHeuristic::logProbability(Document &doc, Category c) {
    probability_t logP = 0;
    for(std::pair<Heuristic*, double> h : heuristics) {
        logP += h.first->logProbability(doc, c) * h.second;
    }
    return logP;
}
