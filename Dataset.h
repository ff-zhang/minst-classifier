//
// Created by Felix Zhang on 2022-12-28.
//

#ifndef MINST_CLASSIFIER_DATASET_H
#define MINST_CLASSIFIER_DATASET_H

#include "globals.h"

class Dataset {
private:
    DataPoint readImage(std::array<int, imagePixels> im, int y);

public:
    static const int numTrain = 10000;
    static const int numTest = 10000;

    std::array<DataPoint, numTest> trainSet;
    std::array<DataPoint, numTest> testSet;
};


#endif //MINST_CLASSIFIER_DATASET_H
