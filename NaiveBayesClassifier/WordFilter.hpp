//
//  WordFilter.hpp
//  NaiveBayesClassifier
//
//  Created by John Rehbein on 2/11/17.
//  Copyright © 2017 John Rehbein. All rights reserved.
//

#ifndef WordFilter_hpp
#define WordFilter_hpp

#include <iostream>

class WordFilter {
public:
    virtual bool shouldUseWord(std::string w) { return true; }
};

#endif /* WordFilter_hpp */
