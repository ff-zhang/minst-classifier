//
// Created by Felix Zhang on 2022-12-28.
//

#include "error.h"

#include "SGDLearner.h"
#include "Dataset.h"

double SGDLearner::TrainingError(Dataset &data) {
    double accum = 0;
    for (auto &point : data.trainSet) {
        accum += loss01(predict(point.x), point.y);
    }
    return accum / data.numTrain;
}

double SGDLearner::GeneralizationError(Dataset &data) {
    double accum = 0;
    for (auto &point : data.testSet) {
        accum += loss01(predict(point.x), point.y);
    }
    return accum / data.numTest;
}

