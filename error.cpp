//
// Created by Felix Zhang on 2022-12-28.
//

#include "SGDLearner.h"
#include "Dataset.h"
#include "Timer.h"

double SGDLearner::TrainingError(Dataset<NUM_TRAIN, NUM_TEST> &data) {
    ScopedTimer myTimer = ScopedTimer("Training Error Function Timer");

    double accum = 0;
    for (int i = 0; i < NUM_TRAIN; i++) {
        auto point = data.trainSet[i];
        accum += loss01(predict(point.x), point.y);
    }
    return accum / NUM_TRAIN;
}

double SGDLearner::GeneralizationError(Dataset<NUM_TRAIN, NUM_TEST> &data) {
    double accum = 0;
    for (int i = 0; i < NUM_TEST; i++) {
        auto point = data.testSet[i];
        accum += loss01(predict(point.x), point.y);
    }
    return accum / NUM_TEST;
}
