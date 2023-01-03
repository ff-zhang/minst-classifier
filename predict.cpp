//
// Created by Felix Zhang on 2022-12-28.
//

#include "SGDLearner.h"
#include <algorithm>

int SGDLearner::predict(const VecDom& x) {
    std::tuple<int, double> max = std::make_tuple(0, double(weights.dot(embed(x,0))));
    double weight = 0;
    for (int i = 1; i < 10; i++) {
        weight = double(weights.dot(embed(x,i)));
        if (weight > std::get<1>(max))
            max = std::make_tuple(i, weight);
    }
    return std::get<0>(max);
}

std::array<int,10> SGDLearner::predictRanking(VecDom x) {
    //TODO

    // Should be like predict method but stores all the rankings in order
    // maybe just put them all in an array and then sort it, idk
        // so like make an std::Array<std::tuple<double, int>,10> store loss(i) in the ith entry, then sort w.r.t. the double
        // then return the array of just the ints
    
    std::array<std::tuple<int, double>, 10> confidenceArr;
    for (int i = 0; i < 10; i++) { 
        confidenceArr[i] = std::make_tuple(i, double(weights.dot(embed(x, i))));
    }

    // Sorts based off of the value of "double(weights.dot(embed(x, i)))" from highest to lowest.
    std::sort(confidenceArr.begin(), confidenceArr.end(), 
        [](std::tuple<int, double> a, std::tuple<int, double> b) { 
            return std::get<1>(a) > std::get<1>(b); 
        });

    std::array<int, 10> output;
    for (int i = 0; i < 10; i++) {
        output[i] = std::get<0>(confidenceArr[i]);
    }

    return output;
}
