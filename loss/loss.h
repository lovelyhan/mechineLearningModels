#ifndef __LOSS_H__
#define __LOSS_H__

#include <stdio.h>
#include <math.h>

class lossBase{
public:
    lossBase(){};
    //methods
    double virtual calculateLoss(float predict,float label){};
};

class crossEntropyLoss:public lossBase{
public:
    double calculateLoss(float predict,float label);
};

#endif