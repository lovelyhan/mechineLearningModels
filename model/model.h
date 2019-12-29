#ifndef __MODEL_H__
#define __MODEL_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

class modelBase{
public:
    modelBase(){};
    virtual ~modelBase(){};
    //data
    int paramSize;
    int minibatchSize;
    //method
    virtual map<int,double> computeGrad(map<int,double>&weights,vector<map<int,double> >data){
        map<int,double> gradients;
        return gradients;
    }
    void virtual initParams(map<int,double>&weights){};
};

class linearReg: public modelBase{
public:
    linearReg(double learning_rate,int paramSize,int minibatchSize);
    ~linearReg();

    //data
    //int inputSize;
    double learning_rate;
    //methods
    map<int,double> computeGrad(double learning_rate,int batchSize,int paramSize,map<int,double>weights,vector<map<int,double> >data);
    void initParams(map<int,double>&weights);
    map<int,double> getLabels(string addr);
    vector<map<int,double> > getData(string addr);
};

#endif
