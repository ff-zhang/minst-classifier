//
// Created by Felix Zhang on 2022-12-28.
//

#include "predict.h"

#include "SGDLearner.h"

int SGDLearner::predict(VecDom x) {
    std::tuple<int,double> max = std::make_tuple(0, double(weights.dot(embed(x,0))));
    double weight;
    for (int i = 1; i < 10; i++) {
        weight = double(weights.dot(embed(x,i)));
        if (weight > std::get<1>(max))
            max = std::make_tuple(0, weight);
    }
    return std::get<0>(max);
}
