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
#include <initializer_list>


#pragma mark interface methods

NBCModel::NBCModel() {
    std::forward_list<std::pair<Heuristic*, probability_t> > heuristics;
    std::pair<Heuristic*, probability_t> bagOfWords, modifiedBagOfWords;
    bagOfWords.first = new WordHeuristic();
    bagOfWords.second = 1.0;
    modifiedBagOfWords.first = new LocalWordHeuristic(1.0, 4);
    modifiedBagOfWords.second = 0.3;
    heuristics.push_front(bagOfWords);
    //heuristics.push_front(modifiedBagOfWords);
    heuristic = new CombinedHeuristic(heuristics);
}

void NBCModel::trainWithDocuments(std::vector<Document*> &docs) {
    for(Document* doc : docs) {
        trainWithDocument(*doc);
    }
}

void NBCModel::trainWithDocument(Document &doc) {
    docCountForCategory[doc.getCategory()]++;
    heuristic->trainForCategory(doc, doc.getCategory());
}

Category NBCModel::classify(Document &doc) const {
    // calculate the probabilities for each category
    probability_t logP[CATEGORY_COUNT];
    for (int category = 0; category < CATEGORY_COUNT; category++) {
        logP[category] = log(probabilityOfCategory((Category)category)) + heuristic->logProbability(doc, (Category)category);
    }
    
    //find the maximum category
    probability_t argmax = std::numeric_limits<probability_t>::lowest();
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
