//
// Created by Felix Zhang on 2022-12-28.
//

#include <random>

#include "SGDLearner.h"

template<int NUM_STEPS>
VecLab SGDLearner::sgd(Dataset<NUM_TRAIN, NUM_TEST> &data) {
    //TODO some testing

    // Generate random seed and rng
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(0, NUM_TRAIN);

    std::array<VecLab, NUM_STEPS + 1> w;
    w[0] = SGDLearner::weights;

    VecLab accum = w[0];
    for (int i = 0; i < NUM_STEPS; i++) {
        // Sample a data point randomly
        DataPoint p =  data.trainSet[distrib(gen)];

        // TODO: Change the hard-coded 0-1 loss to a loss function field

        // Find argmax
        std::tuple<double, int> candidate = std::make_tuple(loss01(p.y, 0) + w[i].dot(embed(p.x,0) -
                embed(p.x,p.y)), 0);
        for (int j = 1; j < 10; j++) {
            double score = loss01(p.y, j) + w[i].dot(embed(p.x,j) - embed(p.x,p.y));
            if (score > std::get<0>(candidate)) { candidate = std::make_tuple(score,j); }
        }
        // update weight
        w[i+1] = w[i] - LEARNING_RATE * (embed(p.x, std::get<1>(candidate)) - embed(p.x, p.y));
        accum += w[i];
    }

    return accum / NUM_STEPS;
}

