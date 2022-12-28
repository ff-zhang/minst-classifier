//
// Created by Felix Zhang on 2022-12-28.
//

#ifndef MNIST_CLASSIFIER_SGDLEARNER_H
#define MNIST_CLASSIFIER_SGDLEARNER_H

#include "globals.h"

class SGDLearner {
    const float learningRate;

    VecLab weights;

private:
    VecLab embed(VecDom v, int y);

    VecLab sgd(int numSamples);
    double loss01(int y, int z);

    double TrainingError(Dataset &data);
    double GeneralizationError(Dataset &data);

public:
    int predict(VecDom x);
    SGDLearner(float rate);
};


#endif //MNIST_CLASSIFIER_SGDLEARNER_H
