//
//  LocalWordHeuristic.cpp
//  NaiveBayesClassifier
//
//  Created by John Rehbein on 2/11/17.
//  Copyright © 2017 John Rehbein. All rights reserved.
//

#include "LocalWordHeuristic.hpp"


void LocalWordHeuristic::trainForCategory(Document doc, Category c) {
    
    
    didComputeImportantFeatures = false;
}

probability_t LocalWordHeuristic::logProbability(Document doc, Category c) {
    
    
    didComputeImportantFeatures = true;
}
