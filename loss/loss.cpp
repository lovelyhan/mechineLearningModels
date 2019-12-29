#include "loss.h"

double crossEntropyLoss::calculateLoss(float predict,float label){
    double loss = 0.0;
    if (label > 0){
        loss = (-1.0)*log(predict);
    }
    else{
        loss = (-1.0) * log(1 - predict);
    }
    return loss;
}