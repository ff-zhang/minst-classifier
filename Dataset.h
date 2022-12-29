//
// Created by Felix Zhang on 2022-12-28.
//

#ifndef MINST_CLASSIFIER_DATASET_H
#define MINST_CLASSIFIER_DATASET_H

#include "globals.h"

#include <iostream>
#include <fstream>

template<int NUM_TRAIN, int NUM_TEST>
class Dataset {

private:
    // only call on initialization
    template<int K>
    std::array<DataPoint, K> readSet(char* x, char* y);

public:
    std::array<DataPoint, NUM_TRAIN> trainSet;
    std::array<DataPoint, NUM_TEST> testSet;

    Dataset(char* trainImages, char* trainLabels, char* testImages, char* testLabels) {
        trainSet = readSet<NUM_TRAIN>(trainImages, trainLabels);
        testSet = readSet<NUM_TEST>(testImages, testLabels);
    };
};

// template functions MUST be defined in the header file
template<int NUM_TRAIN, int NUM_TEST>
template<int K>
std::array<DataPoint, K> Dataset<NUM_TRAIN, NUM_TEST>::readSet(char* x, char* y) {
    std::ifstream fDom, fLab;

    fDom.open(x, std::ios::binary | std::ios::in);
    fLab.open(y, std::ios::binary | std::ios::in);

    if (!fDom.is_open()) {
        std::cout << "Error with domain file!" << std::endl;
    };
    if (!fLab.is_open()) {
        std::cout << "Error with test file!" << std::endl;
    };

    // skip the header
    char* bufferHeader = new char[16];
    fDom.read(bufferHeader, 16);
    fLab.read(bufferHeader, 8);

    char* bufferDom = new char[imagePixels];
    char* bufferLab = new char[1];

    while (!fDom.eof()) {
        fDom.read(bufferDom, imagePixels);
        fLab.read(bufferLab, 1);

        auto bufferIm = reinterpret_cast<unsigned char*>(bufferDom);
        auto bufferY = reinterpret_cast<unsigned char*>(bufferLab);

//        TODO: implement creation of point
    }

    // TODO: remove once implemented
    std::array<DataPoint, K> l;
    for (int i = 0; i < K; i++) {
        l[i] = DataPoint{VecDom::Zero(), -1};
    };

    return l;
}

#endif //MINST_CLASSIFIER_DATASET_H
