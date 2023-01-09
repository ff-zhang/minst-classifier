//
// Created by Felix Zhang on 2022-12-28.
//

#include "SGDLearner.h"

double SGDLearner::loss01(int y, int z) {
    return double(y != z);
}

double SGDLearner::lossKT(std::array<int,10> y, std::array<int,10> z) {
    const float NUM_PAIRS = 45.;

    //2./90. * sum_{i=0}^8 sum_{j=i+1}^9 I(sign(y'_i-y'_j)=/=sign(y_i-y_j)
    double accum = 0;
    for (int i = 0; i <= 8; i++) {
        for (int j = i + 1; j <= 9; j++) {
            // (0 < x) - (x < 0) represents the sign of a number
            accum += ((0 < z[i] - z[j]) - (z[i] - z[j] < 0) != (0 < y[i] - y[j]) - (y[i] - y[j] < 0));
        }
    }
    return accum / NUM_PAIRS;
}
