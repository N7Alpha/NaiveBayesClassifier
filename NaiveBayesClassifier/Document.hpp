//
//  Document.hpp
//  NaiveBayesClassifier
//
//  Created by John Rehbein on 2/11/17.
//  Copyright © 2017 John Rehbein. All rights reserved.
//

#ifndef Document_hpp
#define Document_hpp

#include <iostream>
#include <assert.h>
#include <vector>

enum Category {
    NEGATIVE,
    POSITIVE,
    CATEGORY_COUNT
};
typedef unsigned int uint;
class Document {
private:
    Category category;
    std::string text;
    std::vector<std::string> words;
    std::vector<std::vector<std::string> > sentences;
    void magicalFunctionFromTheInternet(std::string input);
    void createSentences(std::string input);
public:
    Document(std::string line);
    Category getCategory();
    uint getWordCount() { return words.size(); };
    const std::vector<std::string>& getWords() { return words; };
};

#endif /* Document_hpp */
