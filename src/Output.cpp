#include "Output.h"

Output::Output():Object(){
    mask=false;
    distanceFactor=1;
}


Output::Output(int size):Object(size){
    mask=false;
    distanceFactor=1;
}

Output::Output(int size, int* data):Object(size, data){
    mask=false;
    distanceFactor=1;
}

Output::~Output(){
}

void Output::addState(State* s){
    states.push_back(s);
}

int Output::getStateSize(){
    return (int)(states.size());
}

vector<State*> Output::getStates(){
    return states;
}

State* Output::getState(int i){
    return states[i];
}

bool Output::isSatisfiable(){
    bool answer=true;
    for(int i=0;i<size;i++){
        if(data[i]==0)
            answer=false;
    }
    return answer;
}

bool Output::getMask(){
    return mask;
}

void Output::setMask(bool value){
    mask=value;
}

double Output::getDistanceFactor(){
    return distanceFactor;
}

void Output::setDistanceFactor(double d){
    distanceFactor=d;
}

void Output::hit(){
    cout << "hit" << endl ;
    distanceFactor *= 0.9 ;
}

void Output::miss(){
    distanceFactor *= 1.3;
}