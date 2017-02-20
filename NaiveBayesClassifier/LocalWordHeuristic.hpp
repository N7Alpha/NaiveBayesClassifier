//
//  LocalWordHeuristic.hpp
//  NaiveBayesClassifier
//
//  Created by John Rehbein on 2/11/17.
//  Copyright © 2017 John Rehbein. All rights reserved.
//

#ifndef LocalWordHeuristic_hpp
#define LocalWordHeuristic_hpp

#include <stdio.h>
#include "Heuristic.hpp"
#include <vector>
#include <unordered_map>
#include <unordered_set>


class LocalWordHeuristic : public Heuristic {
private:
    uint importantFeaturesCount = 100;
    uint adjacencyCutoff = 3;
    std::unordered_set<std::string> importantFeatures;
    bool didComputeImportantFeatures = false;
    
public:
    //Heuristic interface functions
    virtual void trainForCategory(Document doc, Category c);
    virtual probability_t logProbability(Document doc, Category c);
};

#endif /* LocalWordHeuristic_hpp */
