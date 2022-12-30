cmake_minimum_required(VERSION 3.23)
project(minst_classifier)

set(CMAKE_CXX_STANDARD 14)

find_package(Eigen3 REQUIRED NO_MODULE)
include_directories(${Eigen_INCLUDE_DIR})

add_executable(minst_classifier
        main.cpp
        sgd.cpp
        loss.cpp
        embed.cpp
        error.cpp
        predict.cpp
        SGDLearner.cpp SGDLearner.h
        Dataset.cpp Dataset.h
        globals.h
    )

target_link_libraries(minst_classifier Eigen3::Eigen)
