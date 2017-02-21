//
//  NaiveBayesClassifier.cpp
//  NaiveBayesClassifier
//
//  Created by John Rehbein on 2/8/17.
//  Copyright © 2017 John Rehbein. All rights reserved.
//

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "Document.hpp"
#include "NBCModel.hpp"
#include <time.h>
using namespace std;


string trainingFileName, testingFileName;
probability_t correctPredictionsTest = 0, correctPredictionsTrain = 0;
vector<Document*> trainingDocs, testingDocs;
NBCModel movieNBC;
time_t timeBeforeTest, timeAfterTest, timeBeforeLabel, timeAfterLabel;



void loadFileIntoDocuments(ifstream &myfile, vector<Document*> &docs) {
    string line;
    if (myfile.is_open()) {
        while (getline(myfile,line)) {
            //cout << line << '\n';
            Document *doc = new Document(line); // Probably want to either pass docs by reference var or pointers cause I think they might be getting copied.
            docs.push_back(doc);
        }
        myfile.close();
    }
}

void loadDocuments() {
    ifstream trainingStream, testingStream;
    trainingStream.open(trainingFileName);
    testingStream.open(testingFileName);
    loadFileIntoDocuments(trainingStream, trainingDocs);
    loadFileIntoDocuments(testingStream, testingDocs);
}

int main(int argc, const char * argv[]) {

#ifdef __APPLE__
    trainingFileName = "training.txt";
    testingFileName = "testing.txt";
#elif
    trainingFileName = argv[1];
    testingFileName = argv[2];
#endif
    loadDocuments();
    time(&timeBeforeTest);
    movieNBC.trainWithDocuments(trainingDocs);
    time(&timeAfterTest);
    time(&timeBeforeLabel);
    
    for(Document *testingDoc : testingDocs) {
        Category predictedCategory = movieNBC.classify(*testingDoc);
        cout << predictedCategory << '\n';
        correctPredictionsTest += (predictedCategory == testingDoc->getCategory());
    }
    for(Document *trainingDoc : trainingDocs) {
        Category predictedCategory = movieNBC.classify(*trainingDoc);
        correctPredictionsTrain += (predictedCategory == trainingDoc->getCategory());
    }
    time(&timeAfterLabel);
    
    cout << difftime(timeAfterLabel, timeBeforeLabel) << " seconds (training)\n";
    cout << difftime(timeAfterTest, timeBeforeTest) << " seconds (labeling)\n";
    cout << correctPredictionsTrain/trainingDocs.size() << " (training)\n";
    cout << correctPredictionsTest/testingDocs.size() << " (testing)\n";
    return 0;
}
