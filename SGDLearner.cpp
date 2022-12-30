//
// Created by Felix Zhang on 2022-12-28.
//

#include "SGDLearner.h"

SGDLearner::SGDLearner(float rate) : LEARNING_RATE(rate) {
    weights = VecLab::Zero();
}
