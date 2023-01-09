# include "globals.h"

#include "Dataset.h"
#include "SGDLearner.h"
#include "Logger.h"

int main()
{
    auto* mnist = new Dataset<NUM_TRAIN, NUM_TEST>(TRAIN_IMAGES, TRAIN_LABELS,TEST_IMAGES,
                                                   TEST_LABELS);

    auto* model = new SGDLearner(0.01);
    //model->train(*mnist, 10000);
    //model->saveWeigths("weights/model_weights.b");

    model->loadWeigths("weights/model_weights.b");

    Log appLog = Log();

    //appLog.logVecLab(model->getWeights());
    //appLog.logVecLabSegment(model->getWeights(), 59, 86);

    double trainingError = model->TrainingError(*mnist);
    appLog.logMessage("The training error is: " + std::to_string(trainingError));

    double testingError = model->GeneralizationError(*mnist);
    appLog.logMessage("The testing error is: " + std::to_string(testingError));

    delete model;
    delete mnist;
}
