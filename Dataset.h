//
// Created by Felix Zhang on 2022-12-28.
//

#ifndef MINST_CLASSIFIER_DATASET_H
#define MINST_CLASSIFIER_DATASET_H

#include "globals.h"

class Dataset {
private:
    std::tuple<VecDom, int> readImage(std::array<int, imagePixels> im, int y);
    
public:
    static const int numTrain = 10000;
    static const int numTest = 10000;
    
    std::array<std::tuple<VecDom, int>, numTrain> trainSet;
    std::array<std::tuple<VecDom, int>, numTest> testSet;
};


#endif //MINST_CLASSIFIER_DATASET_H
