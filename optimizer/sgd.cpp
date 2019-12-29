#include "sgd.h"

sgdBasic::sgdBasic(int param_size,float learning_rate){
    sgdBasic::param_size = param_size;
    sgdBasic::learning_rate = learning_rate;
}

sgdBasic::~sgdBasic(){
}

void sgdBasic::updateParams(double learning_rate,map<int,double>&weights,map<int,double>&grads){
    for (auto it = grads.begin();it != grads.end();it++){
        if(it -> first != 0){
            weights[it -> first] += learning_rate * it->second;
        }
    }
}