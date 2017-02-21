//
//  LocalWordHeuristic.cpp
//  NaiveBayesClassifier
//
//  Created by John Rehbein on 2/11/17.
//  Copyright © 2017 John Rehbein. All rights reserved.
//

#include "LocalWordHeuristic.hpp"
#include "util.hpp"


void LocalWordHeuristic::trainForCategory(Document &doc, Category c) {
    for(std::string word : doc.getWords()) {
        wordFrequency[word]++;
    }
    trainingDocs[c].push_back(&doc); //save the doc for later cause the training model is contigent on having all the training data
    didComputeImportantFeatures = false;
}

probability_t LocalWordHeuristic::logProbability(Document &doc, Category c) {
    if (!didComputeImportantFeatures) {
        computeImportantFeatures();
        trainForPastDocs();
        didComputeImportantFeatures = true;
    }
    
    std::vector<std::string> validWords;
    validWordsForDoc(&doc, &validWords);
    
    probability_t runningProbability = 0;
    for (uint i = adjacencyCutoff; i < validWords.size(); i++) {
        for (uint j = i - adjacencyCutoff; j < i; j++) {
            runningProbability += log((localWordFrequency[c][keyForWords(validWords[i], validWords[j])] + alpha) / (probability_t)(alpha * localWordFrequency[c].size() + pairsCount[c]));
            //log((wordFrequency[c][word] + alpha) / ( alpha * wordFrequency[c].size() + wordCount[c]))
        }
    }
    return runningProbability;
}

void LocalWordHeuristic::validWordsForDoc(Document *doc, std::vector<std::string> *validWords) {
    for(std::string word : doc->getWords()) {
        if (importantFeatures.find(word) != importantFeatures.end()) { // checks for set membership
            validWords->push_back(word);
        }
    }
}

void LocalWordHeuristic::computeImportantFeatures() {
    //finds the nth largest term in wordFrequency
    int *frequecies = new int[wordFrequency.size()];
    uint counter = 0;
    for (std::pair<std::string, uint> frequencyElement : wordFrequency) {
        frequecies[counter] = frequencyElement.second;
        counter++;
    }
    int hundrethLargest = kthSmallest(frequecies, 0, wordFrequency.size() - 1, wordFrequency.size() - importantFeaturesCount); // assumes > importantFeaturesCount elements in wordFrequencies
    delete [] frequecies;
    
    // add the top ranking terms to importantFeatures
    for (std::pair<std::string, uint> frequencyElement : wordFrequency) {
        if(frequencyElement.second >= hundrethLargest) {
            importantFeatures.insert(frequencyElement.first);
        }
    }
}

std::string LocalWordHeuristic::keyForWords(std::string s1, std::string s2) {
    std::stringstream ss;
    if(s1.compare(s2) < 0) {
        ss << s1 << " " << s2;
    } else {
        ss << s2 << " " << s1;
    }
    return ss.str();
}

void LocalWordHeuristic::trainForPastDocs() {
    for (uint c = NEGATIVE; c < CATEGORY_COUNT; c++) {
        for(Document *doc : trainingDocs[c]) {
        std::vector<std::string> validWords;
        validWordsForDoc(doc, &validWords);
        for (uint i = adjacencyCutoff; i < validWords.size(); i++) {
            for (uint j = i - adjacencyCutoff; j < i; j++) {
                localWordFrequency[c][keyForWords(validWords[i], validWords[j])]++;
                pairsCount[c]++;
            }
        }
        
        }
    }
    
}
