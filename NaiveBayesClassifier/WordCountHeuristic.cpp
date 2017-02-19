//
//  WordCountHeuristic.cpp
//  NaiveBayesClassifier
//
//  Created by John Rehbein on 2/11/17.
//  Copyright © 2017 John Rehbein. All rights reserved.
//

#include "WordCountHeuristic.hpp"

void WordCountHeuristic::trainForCategory(Document doc, Category c) {
    if (doc.getWordCount() < 200) {
        count[c][FEW]++;
    } else if (doc.getWordCount() < 400) {
        count[c][MODERATE]++;
    } else {
        count[c][MANY]++;
    }
}

uint alpha = 10;

probability_t WordCountHeuristic::logProbability(Document doc, Category c) {
    return count[c][rangeForDocument(doc)] + alpha / (count[c][FEW] + count[c][MODERATE] + count[c][MANY]);
}

Range WordCountHeuristic::rangeForDocument(Document d) {
    if (d.getWordCount() < 200) {
        return FEW;
    } else if (d.getWordCount() < 400) {
        return MODERATE;
    } else {
        return MANY;
    }
}
