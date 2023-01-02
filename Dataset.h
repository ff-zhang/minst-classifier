//
// Created by Felix Zhang on 2022-12-28.
//

#ifndef MNIST_CLASSIFIER_DATASET_H
#define MNIST_CLASSIFIER_DATASET_H

#include "globals.h"

#include <iostream>
#include <fstream>
#include <filesystem>

template<int NUM_TRAIN, int NUM_TEST>
class Dataset {

private:
    // only call on initialization
    template<int K>
    DataPoint* readSet(const std::filesystem::path& xFile, const std::filesystem::path& yFile);

public:
    DataPoint *trainSet, *testSet;

    Dataset(const std::filesystem::path& trainImages, const std::filesystem::path& trainLabels, const std::filesystem::path& testImages,
            const std::filesystem::path& testLabels) {
        trainSet = readSet<NUM_TRAIN>(TRAIN_IMAGES, TRAIN_LABELS);
        testSet = readSet<NUM_TEST>(TEST_IMAGES, TEST_LABELS);
    }
};

// template functions MUST be defined in the header file
template<int NUM_TRAIN, int NUM_TEST>
template<int K>
DataPoint* Dataset<NUM_TRAIN, NUM_TEST>::readSet(const std::filesystem::path& xFile, const std::filesystem::path& yFile) {
    std::ifstream fDom, fLab;

    // Retrieve training set directory
    std::filesystem::path currentDir = std::filesystem::current_path();

    // Iterate over the current path from the root to find the project name folder "mnist-classifier".
    std::filesystem::path srcDir;
    auto it = currentDir.begin();
    while(*it != "mnist-classifier" && it != currentDir.end())
    {
        srcDir /= *it;
        it++;
    }
    srcDir /= *it;

    std::filesystem::path xFileAbs = (srcDir / xFile).make_preferred();
    std::filesystem::path yFileAbs = (srcDir / yFile).make_preferred();

    fDom.open(xFileAbs, std::ios::binary | std::ios::in);
    fLab.open(yFileAbs, std::ios::binary | std::ios::in);

    if (!fDom.is_open()) {
        std::cout << "Error opening " << xFileAbs << "!" << std::endl;
    };
    if (!fLab.is_open()) {
        std::cout << "Error opening " << yFileAbs << "!" << std::endl;
    };

    // skip the header
    char bufferHeader[16];
    fDom.read(bufferHeader, 16);
    fLab.read(bufferHeader, 8);

    char* bufferX = new char[IMAGE_SIZE];;

    auto* points = new DataPoint[K];
    char bufferLab;

    int i = 0;
    while (!fDom.eof() && i < K) {
        fDom.read(bufferX, IMAGE_SIZE);
        fLab.get(bufferLab);

        auto bufferIm = reinterpret_cast<unsigned char*>(bufferX);
        auto* bufferDom = new double[784];
        std::transform(bufferIm, bufferIm + IMAGE_SIZE, bufferDom,
                       [](const unsigned char c) -> double { return (double) c; });
        Eigen::Map<VecDom> point(bufferDom);

        points[i] = *new DataPoint{point, *reinterpret_cast<unsigned char*>(&bufferLab)};
        i++;
    }

    fDom.close();
    fLab.close();

    return points;
}

#endif //MNIST_CLASSIFIER_DATASET_H
