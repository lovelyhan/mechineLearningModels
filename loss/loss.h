#ifndef __LOSS_H__
#define __LOSS_H__

#include <stdio.h>
#include <math.h>

class lossBase{
public:
    lossBase(){};
    //methods
    double virtual calculateLoss(float predict,float label){double ans = 0.0;return ans;};
};

class crossEntropyLoss:public lossBase{
public:
    double calculateLoss(float predict,float label);
};

#endif