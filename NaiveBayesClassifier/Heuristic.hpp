//
//  Heuristic.hpp
//  NaiveBayesClassifier
//
//  Created by John Rehbein on 2/11/17.
//  Copyright © 2017 John Rehbein. All rights reserved.
//

#ifndef Heuristic_hpp
#define Heuristic_hpp

#include <stdio.h>
#include "Document.hpp"
#include <math.h>

typedef double probability_t;

class Heuristic {
public:
    virtual void trainForCategory(Document &doc, Category c) = 0;
    virtual probability_t logProbability(Document &doc, Category c) = 0;
    // it'd be nice if I could somehow delegate taking the log of probabilities to this class it would make things nicer but I couldn't figure out a clean way to do it. I probably should have made each word have it's own class then I could've done that
    
};

#endif /* Heuristic_hpp */
