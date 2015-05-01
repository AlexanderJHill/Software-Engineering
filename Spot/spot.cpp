#include <iostream>
#include <list>
#include "../Agent/agent.h"
#include "../Agent/strategy.h"
#include "spot.h"
/*
 constructor
 */
Spot::Spot(list<Agent *> newAgents){
    agents = newAgents;
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


list<Agent *> Spot::getAgents(){
    return agents;
}

/* @pre:
 Computes the crowdness, in percentage
 */
double crowdness(double goFish, double maxCap) {
    double crowdness =(goFish/maxCap)*100;
    //cout<<crowdness<<'\n';
    return crowdness;
}
