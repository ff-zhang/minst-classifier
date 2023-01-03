//
// Created by Felix Zhang on 2022-12-28.
//

#include "SGDLearner.h"
#include "fmt/core.h"
#include <filesystem>
#include <fstream>
#include <iostream>

SGDLearner::SGDLearner(float rate) : LEARNING_RATE(rate) {
    weights = VecLab::Zero();
}

void SGDLearner::saveWeigths(std::filesystem::path relFilepath)
{
    // Save trained weights to a file so that the model doesn't need to be
    // re-trained when testing. Input is a filepath relative to the source dir.
    auto srcDir = getSrcDir(std::filesystem::current_path());
    auto path = (srcDir / relFilepath).make_preferred();

    std::ofstream ostream(path, std::ios::binary);
    if (ostream.is_open()) {
        for (auto it = weights.begin(); it != weights.end(); it++) {
            double currentValue = *it;
            ostream.write(reinterpret_cast<char*>(&currentValue), sizeof(currentValue));
        }
    }
    else {
        std::cout << fmt::format("Error writing to \"{}\".\n", path.string());
    }
    ostream.close();
}

void SGDLearner::loadWeigths(std::filesystem::path relFilepath)
{
    auto srcDir = getSrcDir(std::filesystem::current_path());
    auto path = (srcDir / relFilepath).make_preferred();

    std::ifstream istream(path, std::ios::binary);
    if (istream.is_open()) {
        int i = 0;
        double* inputBuffer = new double[IMAGE_SIZE * 10];
        while (!istream.eof() && i < IMAGE_SIZE * 10) {
            istream.read(reinterpret_cast<char*>(&(inputBuffer[i])), sizeof(double));
            i++;
        }
        Eigen::Map<VecLab> readWeights(inputBuffer);
        weights = readWeights;

        delete[] inputBuffer;
    }
    else {
        std::cout << fmt::format("Error opening \"{}\".\n", path.string());
    }
    istream.close();
}
