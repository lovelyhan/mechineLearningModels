#include "model.h"
#include "../loss/loss.h"
#include <time.h>
#include <cfloat>
#include <random>
#include <iostream>
#include "../utils/utility.h"
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <numeric>
#include <algorithm>
#include <map>


linearReg::linearReg(double lr,int param,int minibatch){
    learning_rate = lr;
    paramSize = param;
    minibatchSize = minibatch;
}

linearReg::~linearReg(){}

//calculate gradient to update models
map<int,double> computeGrad(double learning_rate,int batchSize,int paramSize,map<int,double>&weights,vector<map<int,double> >data){
    // linearReg lr(learning_rate,batchSize,paramSize);
    // crossEntropyLoss cross;
    // double overflow = 20.0;
    // float total_cost = 0.0;
    // float diff,predict;

    // //random device returns a figure between the min and the max
    // random_device rd;
    // //mt19937 is used to produce a random num
    // mt19937 g(rd());

    // vector<int> index(data.size());
    // iota(index.begin(),index.end(),0);
     map<int,double> gradients;
    // double total_loss = 0.0;
    // int total_right = 0;
    // int total = data.size();
    // shuffle(index.begin(),index.end(),g);
    // for (unsigned int i = 0;i < batchSize;i++){
    //     double loss = 0.0;
    //     double label = data[index[i]][0];
    //     double logit = 0.0;
    //     for (auto it = data[index[i]].begin();it != data[index[i]].end();it++){
    //         if (it -> first != 0){
    //             //calculate the dot
    //             logit += it->second * weights[it->first];
    //         }
    //     }
    //     if (logit > overflow){
    //         logit = overflow;
    //     }
    //     if (logit < -overflow){
    //         logit = -overflow;
    //     }
    //     for (auto it = data[index[i]].begin();it != data[index[i]].end();it++){
    //         if (it -> first != 0){
    //             //calculate the dot
    //             gradients[it -> first] +=(label - logit) * it->second;
    //         }
    //     }
    //     logit =  1.0/(1.0 + exp(-logit));
    //     loss = cross.calculateLoss(logit,label);
    //     total_loss += loss;
    // }
    // total_loss /= batchSize;
    // printf("Linear Regression loss:%f\n",total_loss);
    return gradients;
}

void linearReg::initParams(map<int,double>&weights){
    srand(time(NULL));
    for (int i = 0;i < paramSize;i++){
        weights[i] = 0;
    }
}

// map<int,double> linearReg::getLabels(string addr){
//     map<int,double> labels;
//     ifstream fin;
//     fin.open(addr);
//     string line;
//     int i = 0;
//     while (getline(fin,line)){
//         if(line[0] != '#' && line[0] != ' '){
//             vector<string> tokens = split(line,' ');
//             if (atoi(tokens[0].c_str()) == 1){
//                 labels[i] = 1.0;
//             }else{
//                 labels[i] = 0;
//                 }
//             }
//         i++;
//     }
//     fin.close();
//     return labels;
// }

vector<map<int,double> >linearReg::getData(string addr){
    ifstream fin;
    fin.open(addr);
    string line;
    vector<map<int,double> > data;
    while (getline(fin,line)){
        if(line[0] != '#' && line[0] != ' '){
            vector<string> tokens = split(line,' ');
            map<int,double> example;
            if (atoi(tokens[0].c_str()) == 1){
                example[0] = 1.0;
            }else{
                example[0] = 0.;
                }
            for(unsigned int i = 1;i < tokens.size();i++){
                vector<string> feat_val = split(tokens[i],':');
                if(feat_val.size() == 2){
                    example[atoi(feat_val[0].c_str())] = atof(feat_val[1].c_str());
                    }
                }
                data.push_back(example);
            }
    }
    fin.close();
    return data;
}

