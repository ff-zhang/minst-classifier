# include "globals.h"

#include "Dataset.h"
#include "SGDLearner.h"

int main()
{
    auto* mnist = new Dataset<NUM_TRAIN, NUM_TEST>(TRAIN_IMAGES, TRAIN_LABELS,TEST_IMAGES,
                                                   TEST_LABELS);

    SGDLearner* model = new SGDLearner(0.1);
    model->train(*mnist, 20);

    std::cout << model->getWeights() << ",\n\n";
    std::cout << "Training Error: " << model->TrainingError(*mnist) << std::endl;

    delete model;
    delete mnist;
}
