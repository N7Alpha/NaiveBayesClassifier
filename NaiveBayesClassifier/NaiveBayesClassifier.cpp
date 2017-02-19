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
using namespace std;


string trainingFileName, testingFileName;
vector<Document*> *trainingDocs, *testingDocs;
//NBCModel movieNBC;


void loadFileIntoDocuments(ifstream &myfile, vector<Document*> *docs) {
    string line;
    if (myfile.is_open()) {
        while (getline(myfile,line)) {
            cout << line << '\n';
            Document doc(line);
            //movieNBC.trainWithDocument(doc);
        }
        myfile.close();
    }
}

void loadDocuments() {
    ifstream trainingStream, testingStream;
    trainingStream.open(trainingFileName);
    testingStream.open(testingFileName);
    loadFileIntoDocuments(trainingStream, trainingDocs);
    
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
    
    return 0;
}
