# include "globals.h"

#include "Dataset.h"
#include "SGDLearner.h"
#include "Logger.h"

int main()
{
    auto* mnist = new Dataset<NUM_TRAIN, NUM_TEST>(TRAIN_IMAGES, TRAIN_LABELS,TEST_IMAGES,
                                                   TEST_LABELS);

    auto* model = new SGDLearner(0.1);
    model->train(*mnist, 20);

    Log appLog = Log();

    appLog.logVecLab(model->getWeights());

    double traningError = model->TrainingError(*mnist);
    appLog.logMessage("The training error is: " + std::to_string(traningError));

    delete model;
    delete mnist;
}
