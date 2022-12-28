//
// Created by Felix Zhang on 2022-12-28.
//

#include "error.h"

#include "SGDLearner.h"

double SGDLearner::TrainingError(Dataset &data) {
    double accum = 0;
    for (auto iter = data.trainSet.begin(); iter != data.trainSet.end(); iter++) {
        accum += loss01(predict(std::get<0>(iter)), std::get<1>(iter));
    }
    return accum / data.numTrain;
}

double SGDLearner::GeneralizationError(Dataset &data) {
    double accum = 0;
    for (auto iter = data.testSet.begin(); iter != data.testSet.end(); iter++) {
        accum += loss01(predict(std::get<0>(iter)), std::get<1>(iter));
    }
    return accum / data.numTest;
}