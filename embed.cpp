//
// Created by Felix Zhang on 2022-12-28.


#include <Eigen/Dense>

#include "SGDLearner.h"

VecLab SGDLearner::embed(const VecDom& v, int y) {
    VecLab psi = VecLab::Zero();
    psi.segment<IMAGE_SIZE>(IMAGE_SIZE * y) = v;

    return psi;
}
