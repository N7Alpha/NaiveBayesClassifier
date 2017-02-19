//
//  NBCModel.cpp
//  NaiveBayesClassifier
//
//  Created by John Rehbein on 2/11/17.
//  Copyright © 2017 John Rehbein. All rights reserved.
//

#include "NBCModel.hpp"
#include <numeric>
#include <math.h>
#include <limits>


#pragma mark interface methods

NBCModel::NBCModel() {
    heuristic = new WordHeuristic();
}

void NBCModel::trainWithDocument(Document &doc) {
    docCountForCategory[doc.getCategory()]++;
    heuristic->trainForCategory(doc, doc.getCategory());
}

Category NBCModel::classify(Document &doc) const {
    // calculate the probabilities for each category
    probability_t logP[CATEGORY_COUNT];
    for (int category = 0; category < CATEGORY_COUNT; category++) {
        logP[category] = log(probabilityOfCategory((Category)category)) + heuristic->logProbability(doc, doc.getCategory());
    }
    
    //find the maximum category
    probability_t argmax = std::numeric_limits<probability_t>::min();
    uint category = 0;
    for (int i = 0; i < CATEGORY_COUNT; i++) {
        if(logP[i] > argmax) {
            argmax = logP[i];
            category = (Category)i;
        }
    }
    
    return (Category)category;
}


#pragma mark helper functions

probability_t NBCModel::probabilityOfCategory(Category c) const {
    return docCountForCategory[c] / std::accumulate(std::begin(docCountForCategory), std::end(docCountForCategory), 0);
}
