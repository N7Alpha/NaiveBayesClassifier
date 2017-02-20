//
//  WordCountHeuristic.cpp
//  NaiveBayesClassifier
//
//  Created by John Rehbein on 2/11/17.
//  Copyright © 2017 John Rehbein. All rights reserved.
//

#include "WordCountHeuristic.hpp"

void WordCountHeuristic::trainForCategory(Document &doc, Category c) {
    count[c][rangeForDocument(doc)]++;
}

probability_t alpha = 100.0;

probability_t WordCountHeuristic::logProbability(Document &doc, Category c) {
    return count[c][rangeForDocument(doc)] + alpha / (count[c][FEW] + count[c][MODERATE] + count[c][MANY]);
}

Range WordCountHeuristic::rangeForDocument(Document &d) {
    if (d.getWordCount() < 200) {
        return FEW;
    } else if (d.getWordCount() < 300) {
        return FEW_MODERATE;
    } else if (d.getWordCount() < 400) {
        return MODERATE;
    } else if (d.getWordCount() < 500) {
        return MANY_MODERATE;
    } else {
        return MANY;
    }
}
