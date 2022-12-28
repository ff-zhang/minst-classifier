//
// Created by Felix Zhang on 2022-12-28.
//

#include "loss.h"

double loss01(int y, int z) {
    return !(y == z)?1.0:0.0;
}