//
// Created by Felix Zhang on 2022-12-28.


#include <Eigen/Dense>

#include "embed.h"

#include "SGDLearner.h"

SGDLearner::VecLab SGDLearner::embed(VecDom v, int y) {
    VecLab psi = VecLab::Zero();
    psi.segment<imagePixels>(imagePixels*y) = v;
}
