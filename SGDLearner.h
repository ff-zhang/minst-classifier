//
// Created by Felix Zhang on 2022-12-28.
//

#ifndef MNIST_CLASSIFIER_SGDLEARNER_H
#define MNIST_CLASSIFIER_SGDLEARNER_H

#include "globals.h"
#include "Dataset.h"

class SGDLearner {
    const float learningRate;

    VecLab weights;

private:
    VecLab embed(VecDom v, int y);

    VecLab sgd(int numSamples, Dataset<NUM_TRAIN, NUM_TEST> &data);
    double loss01(int y, int z);
    double lossKT(std::array<int,10> y, std::array<int,10> z);

    double TrainingError(Dataset<NUM_TRAIN, NUM_TEST>  &data);
    double GeneralizationError(Dataset<NUM_TRAIN, NUM_TEST>  &data);

public:
    int predict(VecDom x);
    std::array<int,10> predictRanking(VecDom x);
    SGDLearner(float rate);
};


#endif //MNIST_CLASSIFIER_SGDLEARNER_H
