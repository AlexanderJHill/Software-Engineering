#include <iostream>
#include <list>
#include "agent.h"
#include "strategy.h"
#include "spot.h"
Spot::Spot(){
    goFish = 0;//Initial
}

/*
maxcapacity of fisherman variable is initialized for a given spot
 */
void Spot::setCap(double cap) {
    maxcapacity = cap;
}

/* @pre: maxcapacity is initialized
@post: None
@return: Returns a spot maxcapacity
 */
int Spot::getSpotCapacity() {
    return maxcapacity;
}

/* @pre: The number of Agents going to this specific spot has been decided.
 @post: The crowdness, in percentage
*/
double Spot::crowdness() {
    double crowdness =( goFish/maxcapacity)*100;
   // cout<<crowdness<<'\n';
    return crowdness;
}
/*
 Majority decides to fish or not according to decision
 */
void Spot::decideToGoFish(){
        //Get the Agents decision to know if they went fishing or not
    list<Strategy *> allStrat;
    initStrategy(&allStrat);
    list<Strategy *>::iterator it = allStrat.begin();
    
    
    list<Agent *> allAgent;
    int numAgent = 100;//Get from user input
    initAgent(&allAgent, numAgent, allStrat);
    
    
    for (list<Agent *>::iterator it = allAgent.begin(); it != allAgent.end(); it++)
    {
        Agent *curAgent = *it;
        //These should be from user input
        curAgent->setTemp(50);
        curAgent->setSkill(3);
        curAgent->setFishduration(24);
        curAgent->setCommunication(4);

        //Make agent decisions
        curAgent->makeEarlyDecision();
        curAgent->calcThreshold();
        curAgent->makeDecision();
        curAgent->updateHistory();
        
        //If decides to go, then increase going fishing by 1
        if(curAgent->getDecision()==1){
            goFish++;
        }
        
    }
   //cout<<"fisherman: "<<goFish<<'\n';
}

/*Testing
int main(){
    Spot a;
    a.setCap(100);//should be =<100 because of numAgents above
    a.decideToGoFish();
    cout<<a.crowdness()<<'\n';
    return 0;
}
*/
 
