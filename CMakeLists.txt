cmake_minimum_required(VERSION 3.23)
project(mnist_classifier)

set(CMAKE_CXX_STANDARD 20)

find_package(Eigen3 REQUIRED NO_MODULE)
include_directories(${Eigen_INCLUDE_DIR})

add_subdirectory(fmt-9.1.0 EXCLUDE_FROM_ALL)

add_executable(mnist_classifier
        main.cpp
        sgd.cpp
        loss.cpp
        embed.cpp
        error.cpp
        predict.cpp
        SGDLearner.cpp SGDLearner.h
        Dataset.cpp Dataset.h
        globals.h
        Timer.cpp Timer.h
        Logger.cpp Logger.h
        fileHelpers.cpp fileHelpers.h)

target_link_libraries(mnist_classifier Eigen3::Eigen)
target_link_libraries(mnist_classifier fmt::fmt)
