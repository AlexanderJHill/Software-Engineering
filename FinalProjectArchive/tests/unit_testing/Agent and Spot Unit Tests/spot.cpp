#include <iostream>
#include <list>
#include "agent.h"
#include "strategy.h"
#include "spot.h"
/*
 constructor
 */
Spot::Spot(){
    numAgent = 0;//Initial
    maxcapacity = 0;
}

/*
 maxcapacity of fisherman variable is initialized for a given spot
 */
void Spot::setCap(double cap) {
    maxcapacity = cap;
}

/* 
 Returns a spot's maxcapacity
 */
double Spot::getSpotCapacity() {
    return maxcapacity;
}

/*
 set the number of agents going, from input
 */
void Spot::setAgentNum(int fisherNum){
    numAgent = fisherNum;
}

/*
 Returns number of Agents on spot
 */
int Spot::getAgentNum() {
    return numAgent;
}

/* @pre: 
 Computes the crowdness, in percentage
 */
double Spot::crowdness(double goFish) {
    double crowdness =(goFish/maxcapacity)*100;
    //cout<<crowdness<<'\n';
    return crowdness;
}

