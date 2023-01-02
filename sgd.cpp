//
// Created by Felix Zhang on 2022-12-28.
//

#include "SGDLearner.h"

#include <memory>
#include <random>
#include <fmt/core.h>

void SGDLearner::train(Dataset<NUM_TRAIN, NUM_TEST> &data, int numSteps) {
    // Generate random seed and rng
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(0, NUM_TRAIN);

    // Initialize weight vectors
    auto *w = new VecLab, *accum = new VecLab ;
    *w = VecLab::Zero();
    *accum = VecLab::Zero();

    const int NUM_CHECKPTS = 3;
    const float checkpoints[NUM_CHECKPTS] = { 25, 50, 75 };
    int currentCheckpoint = 0;

    for (int i = 0; i < numSteps; i++) {
        DataPoint p =  data.trainSet[distrib(gen)];

        std::unique_ptr<VecLab> newWeight = SGDLearner::sgd(*w, p);
        *w = *newWeight;
        *accum += *w;

        // Document training progress to console.
        float progress = (float) 100 * (i + 1) / numSteps;
        if (progress > checkpoints[currentCheckpoint] && currentCheckpoint < NUM_CHECKPTS) {
            std::cout << fmt::format("Training is {:.1f}% complete.\n", progress);
            currentCheckpoint++;
        }
    }
    weights = *accum / (numSteps + 1);
    std::cout << "Training is complete.\n";

    delete w;
    delete accum;
};

std::unique_ptr<VecLab> SGDLearner::sgd(VecLab& w_t, DataPoint& p) {
    // Find argmax
    auto* candidate = new VecLab;
    *candidate = VecLab::Zero();

    double best = 0;
    auto* diff = new VecLab;
    for (int j = 0; j < 10; j++) {
        *diff = embed(p.x, j) - embed(p.x, p.y);
        double score = loss01(p.y, j) + w_t.dot(*diff);
        if (score > best) {
            best = score;
            *candidate = *diff;
        }
    }
    delete diff;

    // Return a pointer to a VecLab containing the updated weights
    std::unique_ptr<VecLab> output = std::make_unique<VecLab>();
    *output = w_t - LEARNING_RATE * (*candidate);

    return output;
};
