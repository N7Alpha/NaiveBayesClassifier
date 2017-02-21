//
//  CombinedHeuristic.hpp
//  NaiveBayesClassifier
//
//  Created by John Rehbein on 2/11/17.
//  Copyright © 2017 John Rehbein. All rights reserved.
//

#ifndef CombinedHeuristic_hpp
#define CombinedHeuristic_hpp

#include <iostream>
#include "Heuristic.hpp"
#include <forward_list>
#include <initializer_list>

class CombinedHeuristic : public Heuristic {
private:
    std::forward_list<std::pair<Heuristic*, double>> heuristics;
public:
    CombinedHeuristic(std::initializer_list<std::pair<Heuristic*, probability_t>> heuristics) { this->heuristics = heuristics; };
    virtual void trainForCategory(Document &doc, Category c);
    virtual probability_t logProbability(Document &doc, Category c);
};

#endif /* CombinedHeuristic_hpp */
