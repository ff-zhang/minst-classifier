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
    std::array<DataPoint, K> readSet(char* xFile, char* yFile);

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
std::array<DataPoint, K> Dataset<NUM_TRAIN, NUM_TEST>::readSet(char* xFile, char* yFile) {
    std::ifstream fDom, fLab;

    fDom.open(xFile, std::ios::binary | std::ios::in);
    fLab.open(yFile, std::ios::binary | std::ios::in);

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

    char* bufferX = new char[imagePixels];
    char* bufferLab = new char[1];

    std::array<DataPoint, K> points;

    int i = 0;
    while (!fDom.eof() && i < K) {
        fDom.read(bufferX, imagePixels);
        fLab.read(bufferLab, 1);

        auto bufferIm = reinterpret_cast<unsigned char*>(bufferX);
        auto* bufferDom = new double[784];
        std::transform(bufferIm, bufferIm + imagePixels, bufferDom,
                       [](const unsigned char c) -> double { return (double) c; });
        Eigen::Map<VecDom> point(bufferDom);

        points[i] = DataPoint{point, reinterpret_cast<unsigned char*>(bufferLab)[0]};
        i++;
    }

    fDom.close();
    fLab.close();

    return points;
}

#endif //MINST_CLASSIFIER_DATASET_H
