#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

vector<string>split(const string &s,char delim,vector<string> &elems){
    stringstream ss(s);
    string item;
    while(getline(ss,item,delim)){
        elems.push_back(item);
    }
    return elems;
};

vector<string>split(const string &s,char delim){
    vector<string> elems;
    split(s,delim,elems);
    return elems;
};

