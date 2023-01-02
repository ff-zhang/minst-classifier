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
    template<std::size_t N>
    void readSet(std::array<DataPoint, N>& set, const std::string& xFile, const std::string& yFile);

public:
    std::array<DataPoint, NUM_TRAIN> trainSet;
    std::array<DataPoint, NUM_TEST> testSet;


    Dataset(const std::string& trainImages, const std::string& trainLabels, const std::string& testImages,
            const std::string& testLabels) {
        readSet<NUM_TRAIN>(trainSet,TRAIN_IMAGES, TRAIN_LABELS);
        readSet<NUM_TEST>(testSet,TEST_IMAGES, TEST_LABELS);
    }
};

// template functions MUST be defined in the header file
template<int NUM_TRAIN, int NUM_TEST>
template<std::size_t N>
void Dataset<NUM_TRAIN, NUM_TEST>::readSet(std::array<DataPoint, N>& set, const std::string& xFile,
                                           const std::string& yFile) {
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
    char bufferHeader[16];
    fDom.read(bufferHeader, 16);
    fLab.read(bufferHeader, 8);

    char* bufferX = new char[IMAGE_SIZE];
    char bufferLab;

    int i = 0;
    while (!fDom.eof() && i < N) {
        fDom.read(bufferX, IMAGE_SIZE);
        fLab.get(bufferLab);

        auto bufferIm = reinterpret_cast<unsigned char*>(bufferX);
        auto* bufferDom = new double[784];
        std::transform(bufferIm, bufferIm + IMAGE_SIZE, bufferDom,
                       [](const unsigned char c) -> double { return (double) c; });
        Eigen::Map<VecDom> point(bufferDom);

        set[i] = *new DataPoint{point, *reinterpret_cast<unsigned char*>(&bufferLab)};
        i++;
    }

    fDom.close();
    fLab.close();
}

#endif //MNIST_CLASSIFIER_DATASET_H
