//
//  LocalWordHeuristic.hpp
//  NaiveBayesClassifier
//
//  Created by John Rehbein on 2/11/17.
//  Copyright © 2017 John Rehbein. All rights reserved.
//

/*
    This class is a somewhat context sensitive version of the bag of words model.
 
 */

#ifndef LocalWordHeuristic_hpp
#define LocalWordHeuristic_hpp

#include <stdio.h>
#include <sstream>
#include <string>
#include "Heuristic.hpp"
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <utility>

template <typename T>
struct shortTermMemorySet {
public:
    bool contains(T elem);
    void add(T elem);
    
private:
    std::unordered_set<T> set;
};

class LocalWordHeuristic : public Heuristic {
private:
    //Tweakable Parameters
    probability_t alpha = 1.0;
    uint importantFeaturesCount = 1200;
    uint adjacencyCutoff = 3;
    
    //Helper Data structures and vars
    std::unordered_set<std::string> importantFeatures;
    std::unordered_map<std::string, uint> wordFrequency;
    std::unordered_map<std::string, uint> localWordFrequency[CATEGORY_COUNT];
    std::vector<Document*> trainingDocs[CATEGORY_COUNT];
    bool didComputeImportantFeatures = false;
    probability_t pairsCount[CATEGORY_COUNT] = {0, 0};
    
    //Private Helper Functions
    void computeImportantFeatures();
    void trainForPastDocs();
    void validWordsForDoc(Document *doc, std::vector<std::string> *validWords);
    std::string keyForWords(std::string s1, std::string s2);
    
public:
    //Constructors
    LocalWordHeuristic(probability_t alpha = 1.0, uint adjacencyCutoff = 3) : alpha(alpha), adjacencyCutoff(adjacencyCutoff) {};
    
    //Heuristic interface functions
    virtual void trainForCategory(Document &doc, Category c);
    virtual probability_t logProbability(Document &doc, Category c);
};

#endif /* LocalWordHeuristic_hpp */

