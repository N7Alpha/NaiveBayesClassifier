//
//  CombinedHeuristic.cpp
//  NaiveBayesClassifier
//
//  Created by John Rehbein on 2/11/17.
//  Copyright © 2017 John Rehbein. All rights reserved.
//

#include "CombinedHeuristic.hpp"

/*void CombinedHeuristic::trainForCategory(Document doc, Category c) {
    std::for_each(heuristics.begin(), heuristics.end(), [&doc, c](Heuristic &h){ h.trainForCategory(doc, c); });
}

probability_t CombinedHeuristic::logProbability(Document doc, Category c) {
    probability_t logP = 0;
    for(Heuristic &h : heuristics) {
        logP += h.logProbability(doc, c);
    }
    return logP;
}*/
