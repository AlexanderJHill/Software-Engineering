//contains trategy algorithm
#include "strategy.h"
#include<iostream>
#include <ctime>
#include <cstdlib>

//Strategy constructor
Strategy::Strategy(){
    score = 0;//Initial
}

//Used in strategies
float Strategy::getThreshold(){
    //Test inputs for checking purposes
    float num = 100;//fisherNum();
    float pop = 3100;//fishPop();
    float loc = 10;//fishLoc();
    float exp = 5;//fisherExp();
    float strat = 2;//fisherStrat();
    float type = 5;//fishType();
    float temp = 50;//temperature();
    float time = 12;//runtime();
    
    float E = (exp/5)*20;
    float F = ((num/pop)*20) - 20;
    float T = (time/24)*20;
    float W = (-abs((67.5 - temp)/67.5)*20)+20;
    float p = E+F+T+W;
    
    return p;
}


//This is the decision for every agent, random at first
//go fishing = 1
//stay at home = -1
int Strategy::earlyDecision(float early){
    return early;
}

int Strategy::getDecision(){
    float p = getThreshold();
    
    //Test values
    //int earlyd = earlyDecision(-1);
    
    if (p < 70){
        decision = early;//early decsion
    }
    else if (p>70){
        decision = 1;//go fishing
    }
    std::cout<<decision<<'\n';
    return decision;
}


//return strategy score
int Strategy::stratScore(int majority){
    
    //Get majority decision from agents
    int decision = getDecision();
    float p = getThreshold();
    
    if(p> 70){
        score+=0;//DOnt know what happens here.Assume nothing happens
    }
    
    if (p < 70){
        //Majority goes fishing and decision to stay home
        if (majority == 1 && decision == -1){
            score++;//Increase points
        }
        //Majority goes fishing but decision is go fishing
        else if(majority == 1 && decision == 1) {
            score--;//Decrease points
        }
        //Majority stays home and decides to go fishing
        else if (majority == -1 && decision == 1){
            score++;//Increase points
        }
        //Majority stays at home and decides to stay at home
        else if (majority == -1 && decision == -1){
            score--;//Decrease points
        }
    }
    std::cout<<score<<'\n';
    return score;
}


/*
int main (int argc, char** argv){
    Strategy a;

    a.earlyDecision(1);
    a.stratScore(-1);

    
    
    return 0;
}
*/

