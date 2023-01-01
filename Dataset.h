//
// Created by Felix Zhang on 2022-12-28.
//

#ifndef MNIST_CLASSIFIER_DATASET_H
#define MNIST_CLASSIFIER_DATASET_H

#include "globals.h"

#include <iostream>
#include <fstream>

template<int NUM_TRAIN, int NUM_TEST>
class Dataset {

private:
    // only call on initialization
    template<int K>
    std::array<DataPoint, K> readSet(const std::string& xFile, const std::string& yFile);

public:
    std::array<DataPoint, NUM_TRAIN> trainSet;
    std::array<DataPoint, NUM_TEST> testSet;

    Dataset(const std::string& trainImages, const std::string& trainLabels, const std::string& testImages,
            const std::string& testLabels) {
        trainSet = readSet<NUM_TRAIN>(trainImages, trainLabels);
        testSet = readSet<NUM_TEST>(testImages, testLabels);
    }
};

// template functions MUST be defined in the header file
template<int NUM_TRAIN, int NUM_TEST>
template<int K>
std::array<DataPoint, K> Dataset<NUM_TRAIN, NUM_TEST>::readSet(const std::string& xFile, const std::string& yFile) {
    std::ifstream fDom, fLab;

    fDom.open(xFile, std::ios::binary | std::ios::in);
    fLab.open(yFile, std::ios::binary | std::ios::in);

    if (!fDom.is_open()) {
        std::cout << "Error opening \"" << xFile << "\" !" << std::endl;
    };
    if (!fLab.is_open()) {
        std::cout << "Error opening \"" << yFile << "\" !" << std::endl;
    };

    // skip the header
    char* bufferHeader = new char[16];
    fDom.read(bufferHeader, 16);
    fLab.read(bufferHeader, 8);

    char* bufferX = new char[IMAGE_SIZE];
    char* bufferLab = new char[1];

    std::array<DataPoint, K> points;

    int i = 0;
    while (!fDom.eof() && i < K) {
        fDom.read(bufferX, IMAGE_SIZE);
        fLab.read(bufferLab, 1);

        auto bufferIm = reinterpret_cast<unsigned char*>(bufferX);
        auto* bufferDom = new double[784];
        std::transform(bufferIm, bufferIm + IMAGE_SIZE, bufferDom,
                       [](const unsigned char c) -> double { return (double) c; });
        Eigen::Map<VecDom> point(bufferDom);

        points[i] = DataPoint{point, reinterpret_cast<unsigned char*>(bufferLab)[0]};
        i++;
    }

    fDom.close();
    fLab.close();

    return points;
}

#endif //MNIST_CLASSIFIER_DATASET_H
