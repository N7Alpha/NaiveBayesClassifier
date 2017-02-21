//
//  Document.cpp
//  NaiveBayesClassifier
//
//  Created by John Rehbein on 2/11/17.
//  Copyright © 2017 John Rehbein. All rights reserved.
//

#include "Document.hpp"
#include <string>
#include <sstream>

Category Document::getCategory() {
    return category;
}

Document::Document(std::string line) {
    text = line.substr(0, line.length() - 1);
    std::transform(text.begin(), text.end(), text.begin(), ::tolower);
    category = (Category)std::stoi(line.substr(line.length() - 1, line.length()));
    magicalFunctionFromTheInternet(text);
    //createSentences(text);
}

void Document::createSentences(std::string input) {
    using namespace std;
    bool nchr=false;
    char temp;
    int lenght,i=0,j=0,k;
    lenght = input.length();
    k=lenght;
    
    while(i<k){
        nchr=false;
        
        if ( (input[i]<'A' || input[i]>'Z') && (input[i]<'a' || input[i]>'z') && (input[i]<'0' || input[i]>'9') && input[i] != '.' && input[i]!=' ' ){
            nchr=true;
            
            for (j=i;j<k-1;j++){
                temp=input[j];
                input[j]=input[j+1];
                input[j+1]=temp;
            }
        }
        
        if (nchr==true){
            k--;
            lenght--;
        }
        else
            i++;
    }
    istringstream iss(input);
    string sentence;
    
    while (getline(iss, sentence, '.')) {
        std::istringstream iss2(sentence);
        vector<string> words;
        copy(std::istream_iterator<std::string>(iss2),
             std::istream_iterator<std::string>(),
             back_inserter(words));
        sentences.push_back(words);
    }
    
}

void Document::magicalFunctionFromTheInternet(std::string input) {
    bool nchr=false;
    char temp;
    int lenght,i=0,j=0,k;
    lenght = input.length();
    k=lenght;
    
    while(i<k){
        nchr=false;
        
        if ( (input[i]<'A' || input[i]>'Z') && (input[i]<'a' || input[i]>'z') && (input[i]<'0' || input[i]>'9') && input[i]!=' ' ){
            nchr=true;
            
            for (j=i;j<k-1;j++){
                temp=input[j];
                input[j]=input[j+1];
                input[j+1]=temp;
            }
        }
        
        if (nchr==true){
            k--;
            lenght--;
        }
        else
            i++;
    }
    
    // I think input contains the text of the review with all punctuation removed
    //This is kind of a mess
    std::istringstream iss(input);
    copy(std::istream_iterator<std::string>(iss),
         std::istream_iterator<std::string>(),
         back_inserter(words));
}
