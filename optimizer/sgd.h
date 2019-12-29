#ifndef __SGD_H__
#define __SGD_H__

#include <stdio.h>
#include <map>
//#include <mpi.h>
#include <math.h>

using namespace std;

class sgdBase{
public:
    sgdBase(){};
    //methods
    void virtual updateParams(double learning_rate,map<int,double>&weights,map<int,double>&grads){};
    
protected:
    //data
    int param_size;
    double learning_rate;
};

//sgd basic
class sgdBasic:public sgdBase{
public:
    sgdBasic(int param_size,float learning_rate);
    ~sgdBasic();

    //methods
    void updateParams(double learning_rate,map<int,double>&weights,map<int,double>&grads);
};

#endif