//
// Created by Felix Zhang on 2022-12-28.
//

#ifndef MINST_CLASSIFIER_SGDLEARNER_H
#define MINST_CLASSIFIER_SGDLEARNER_H

#include <Eigen/Dense>

class SGDLearner {
    static const int imagePixels = 784;

    typedef Eigen::Matrix<float, imagePixels, 1> VecDom;
    typedef Eigen::Matrix<float, imagePixels * 10, 1> VecLab;

    static const float learningRate;
    static const float numSamples;
};


#endif //MINST_CLASSIFIER_SGDLEARNER_H
