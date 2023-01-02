//
// Created by Felix Zhang on 2022-12-28.
//

#include <random>

#include "SGDLearner.h"

// TODO: test

void SGDLearner::train(Dataset<NUM_TRAIN, NUM_TEST> &data, int numSteps) {
    // Generate random seed and rng
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(0, data.trainSet.size());

    VecLab w;
    VecLab accum;

    DataPoint* in;
    for (int i = 0; i < numSteps; i++) {
        std::advance(in = data.trainSet.begin(), distrib(gen));
        w = SGDLearner::sgd(w, *in);
        accum += w;
    }
    weights = accum / (numSteps + 1);
};

VecLab SGDLearner::sgd(VecLab& w_t, DataPoint& p) {
    // Find argmax
    std::tuple<double, VecLab> candidate = std::make_tuple(-1, VecLab::Zero());
    for (int j = 0; j < 10; j++) {
        VecLab diff = embed(p.x, j) - embed(p.x, p.y);
        double score = loss01(p.y, j) + w_t.dot(diff);
        if (score > std::get<0>(candidate)) { candidate = std::make_tuple(score, diff); }
    }
    // return updated weight
    return w_t - LEARNING_RATE * std::get<1>(candidate);
};
