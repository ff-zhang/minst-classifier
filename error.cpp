//
// Created by Felix Zhang on 2022-12-28.
//

/*

#include "SGDLearner.h"
#include "Dataset.h"

double SGDLearner::TrainingError(Dataset<NUM_TRAIN, NUM_TEST> &data) {
    double accum = 0;
    for (auto &point : data.trainSet) {
        accum += loss01(predict(point.x), point.y);
    }
    return accum / NUM_TRAIN;
}

double SGDLearner::GeneralizationError(Dataset<NUM_TRAIN, NUM_TEST> &data) {
    double accum = 0;
    for (auto &point : data.testSet) {
        accum += loss01(predict(point.x), point.y);
    }
    return accum / NUM_TEST;
}

*/