//
// Created by Felix Zhang on 2022-12-28.
//

#include "loss.h"

#include "SGDLearner.h"

double SGDLearner::loss01(int y, int z) {
    return double(y == z);
}
