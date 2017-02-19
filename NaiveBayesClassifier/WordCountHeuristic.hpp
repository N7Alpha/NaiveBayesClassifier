//
//  WordCountHeuristic.hpp
//  NaiveBayesClassifier
//
//  Created by John Rehbein on 2/11/17.
//  Copyright © 2017 John Rehbein. All rights reserved.
//

#ifndef WordCountHeuristic_hpp
#define WordCountHeuristic_hpp

#include <stdio.h>
#include "Heuristic.hpp"
enum Range {
    FEW,
    MODERATE,
    MANY,
    RANGE_COUNT
};
class WordCountHeuristic : public Heuristic {
    virtual void trainForCategory(Document doc, Category c);
    virtual probability_t logProbability(Document doc, Category c);
private:
    
    Range rangeForDocument(Document d);
    probability_t count[CATEGORY_COUNT][RANGE_COUNT];
};

#endif /* WordCountHeuristic_hpp */
