//
// Created by Felix Zhang on 2022-12-28.
//

#ifndef MNIST_CLASSIFIER_GLOBALS_H
#define MNIST_CLASSIFIER_GLOBALS_H

#include <Eigen/Dense>

static const int IMAGE_SIZE = 28 * 28;
static const int NUM_TRAIN = 60000;
static const int NUM_TEST = 10000;

typedef Eigen::Matrix<double, IMAGE_SIZE, 1> VecDom;
typedef Eigen::Matrix<double, IMAGE_SIZE * 10, 1> VecLab;

struct DataPoint {
    VecDom x;
    int y;
};

#endif //MINST_CLASSIFIER_GLOBALS_H
