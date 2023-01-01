//
// Created by Felix Zhang on 2022-12-28.
//

#ifndef MNIST_CLASSIFIER_GLOBALS_H
#define MNIST_CLASSIFIER_GLOBALS_H

#include <Eigen/Dense>

static const int IMAGE_SIZE = 784;
static const int NUM_TRAIN = 1000;
static const int NUM_TEST = 100;

static std::string TRAIN_IMAGES = "./../mnist/train-images.idx3-ubyte";
static std::string TRAIN_LABELS = "./../mnist/train-labels.idx1-ubyte";
static std::string TEST_IMAGES = "./../mnist/t10k-images.idx3-ubyte";
static std::string TEST_LABELS = "./../mnist/t10k-labels.idx1-ubyte";

typedef Eigen::Matrix<double, IMAGE_SIZE, 1> VecDom;
typedef Eigen::Matrix<double, IMAGE_SIZE * 10, 1> VecLab;

struct DataPoint {
    VecDom x;
    int y;
};

#endif //MNIST_CLASSIFIER_GLOBALS_H
