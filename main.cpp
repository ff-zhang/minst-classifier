#include <iostream>

#include "Dataset.h"

int main()
{
    Dataset<100, 5> mnist = Dataset<100, 5>("./../mnist/train-images.idx3-ubyte",
                                            "./../mnist/train-labels.idx1-ubyte",
                                            "./../mnist/t10k-images.idx3-ubyte",
                                            "./../mnist/t10k-labels.idx1-ubyte");
}
