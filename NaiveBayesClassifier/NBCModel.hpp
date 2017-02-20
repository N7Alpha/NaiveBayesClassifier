//
//  NBCModel.hpp
//  NaiveBayesClassifier
//
//  Created by John Rehbein on 2/11/17.
//  Copyright © 2017 John Rehbein. All rights reserved.
//

#ifndef NBCModel_hpp
#define NBCModel_hpp

#include <stdio.h>
#include <vector>
#include "Document.hpp"
#include "Heuristic.hpp"
#include "CombinedHeuristic.hpp"
#include "WordHeuristic.hpp"
#include "WordCountHeuristic.hpp"

class NBCModel {
private:
    probability_t docCountForCategory[2];
    // Heursitics are the dependent variables so they compute conditional probabilities
    Heuristic *heuristic;
    probability_t probabilityOfCategory(Category c) const;
public:
    NBCModel();
    void trainWithDocument(Document &doc);
    Category classify(Document &doc) const;
    void trainWithDocuments(std::vector<Document*> &docs);
};

#endif /* NBCModel_hpp */
