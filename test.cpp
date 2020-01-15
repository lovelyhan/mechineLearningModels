#include <iostream>
#include <fstream>
#include <iomanip>
#include <random>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <sstream>
#include <numeric>
#include <algorithm>
#include <map>

#include "./model/model.h"
#include "./optimizer/sgd.h"

using namespace std;

int main(int argc,const char* argv[]){
    //model
    linearReg lr = linearReg(0.02,10000,500);
    //optimizer
    sgdBasic sgd = sgdBasic(10000,0.02);
    string dataAddr = "/Users/apple/Desktop/lr_optimize/data/train.dat";
    //dataset
    vector<map<int,double> > data = lr.getData(dataAddr);
    map<int,double>weights;
    lr.initParams(weights);
    for(int i = 0;i < 500;i++){
        map<int,double> gradients = lr.computeGrad(lr.learning_rate,lr.minibatchSize,lr.paramSize,weights,data);
        sgd.updateParams(lr.learning_rate,weights,gradients);
    }

    

}