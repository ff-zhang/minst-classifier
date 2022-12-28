//
// Created by Felix Zhang on 2022-12-28.
//

#ifndef MNIST_CLASSIFIER_GLOBALS_H
#define MNIST_CLASSIFIER_GLOBALS_H

#include <Eigen/Dense>

static const int imagePixels = 28 * 28;

typedef Eigen::Matrix<float, imagePixels, 1> VecDom;
typedef Eigen::Matrix<float, imagePixels * 10, 1> VecLab;

#endif //MINST_CLASSIFIER_GLOBALS_H
