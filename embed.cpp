//
// Created by Felix Zhang on 2022-12-28.


#include <Eigen/Dense>

#include "embed.h"

VecLab embed(VecDom v, int y) {
    VecLab psi = VecLab::Zero();
    psi.segment<784>(784*y) = v;
}