//
// Created by Felix Zhang on 2022-12-28.
//

#include "SGDLearner.h"

int SGDLearner::predict(const VecDom& x) {
    std::tuple<int, double> max = std::make_tuple(0, double(weights.dot(embed(x,0))));
    double weight;
    for (int i = 1; i < 10; i++) {
        weight = double(weights.dot(embed(x,i)));
        if (weight > std::get<1>(max))
            max = std::make_tuple(0, weight);
    }
    return std::get<0>(max);
}

std::array<int,10> SGDLearner::predictRanking(VecDom x) {
    //TODO
    // Should be like predict method but stores all the rankings in order
    // maybe just put them all in an array and then sort it, idk
}
