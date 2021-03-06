#include <stdio.h>
#include <iostream>
#include <list>
#include "randomgenerator.h"
#include "agent.h"
#include "strategy.h"
#include "spot.h"
using namespace std;

int main(){
    int winning = 0;//Keep tracks of winning decision
    double goFishing = 0;//Initialize agents deciding to go fishing
    int numAgent = 1000;// getfisherNum();
    int temperature = 50; //getfishTemp();
    int duration = 24;//getRunTime();
    int loc = 2;//getFishLoc();Only 1 or 2
    int skill = 3;//getFishSkill();
    int comm = 5; //getfisherComm();
    
    double max = (numAgent)/(loc);//maximum agent per spot, even division of input agents
    // when there are two locations initialize two spots
    if(loc == 2){
        //First spot
        Spot a;
        a.setCap(max);//should be according to AgentNum
        a.setAgentNum(max);
        //Get the Agents decision to know if they went fishing or not
        list<Strategy *> allStrat;
        initStrategy(&allStrat);
        list<Strategy *>::iterator it = allStrat.begin();
        
        list<Agent *> allAgent;
        initAgent(&allAgent, max, allStrat);
        
        for (list<Agent *>::iterator it = allAgent.begin(); it != allAgent.end(); it++)
        {
            Agent *curAgent = *it;
            //These should be from user input
            curAgent->setTemp(temperature);
            curAgent->setSkill(skill);
            curAgent->setFishduration(duration);
            curAgent->setCommunication(comm);
            
            //Make agent decisions
            curAgent->makeEarlyDecision();
            curAgent->calcThreshold();
            curAgent->makeDecision();
            curAgent->updateHistory();
            
            winning = winning + curAgent->getDecision();
            
            //If decides to go, then increase going fishing by 1
            if(curAgent->getDecision()==1){
                goFishing++;
                // cout<<goFishing<<'\n';
            }
            
        }
        double crowd = a.crowdness(goFishing);
        cout<<"Spot1: "<<crowd<<"% went fishing."<<'\n';
      
        //Second spot
        Spot b;
        b.setCap(max);//should be according to AgentNum
        b.setAgentNum(max);
        //Get the Agents decision to know if they went fishing or not
        
        list<Agent *> allAgent2;
        initAgent(&allAgent2, max, allStrat);
        
        for (list<Agent *>::iterator it = allAgent2.begin(); it != allAgent2.end(); it++)
        {
            Agent *curAgent = *it;
            //These should be from user input
            curAgent->setTemp(temperature);
            curAgent->setSkill(skill);
            curAgent->setFishduration(duration);
            curAgent->setCommunication(comm);
            
            //Make agent decisions
            curAgent->makeEarlyDecision();
            curAgent->calcThreshold();
            curAgent->makeDecision();
            curAgent->updateHistory();
            
            winning = winning + curAgent->getDecision();
            
            //If decides to go, then increase going fishing by 1
            if(curAgent->getDecision()==1){
                goFishing++;
                // cout<<goFishing<<'\n';
            }
            
        }
        cout<<"Spot2: "<<b.crowdness(goFishing)<<"% went fishing."<<'\n';
        
        
        for (list<Agent *>::iterator it = allAgent.begin(); it != allAgent.end(); it++)
        {
            Agent *curAgent = *it;
            curAgent->updateStrategyScore(winning);
        }
        
        
        cout << "Strategy Score: " << '\n';
        for (list<Strategy *>::iterator it = allStrat.begin(); it != allStrat.end(); it++)
        {
            Strategy *curStrat = *it;
            cout << curStrat->getScore() << '\n';
        }
    }
    //If there is only one location then only use one spot
    else{
        //First spot
        Spot a;
        a.setCap(max);//should be according to AgentNum
        a.setAgentNum(max);
        //Get the Agents decision to know if they went fishing or not
        list<Strategy *> allStrat;
        initStrategy(&allStrat);
        list<Strategy *>::iterator it = allStrat.begin();
        
        list<Agent *> allAgent;
        initAgent(&allAgent, max, allStrat);
        
        for (list<Agent *>::iterator it = allAgent.begin(); it != allAgent.end(); it++)
        {
            Agent *curAgent = *it;
            //These should be from user input
            curAgent->setTemp(temperature);
            curAgent->setSkill(skill);
            curAgent->setFishduration(duration);
            curAgent->setCommunication(comm);
            
            //Make agent decisions
            curAgent->makeEarlyDecision();
            curAgent->calcThreshold();
            curAgent->makeDecision();
            curAgent->updateHistory();
            
            winning = winning + curAgent->getDecision();
            
            //If decides to go, then increase going fishing by 1
            if(curAgent->getDecision()==1){
                goFishing++;
                // cout<<goFishing<<'\n';
            }
            
        }
        cout<<"Spot: "<<a.crowdness(goFishing)<<"% went fishing."<<'\n';
  
        for (list<Agent *>::iterator it = allAgent.begin(); it != allAgent.end(); it++)
        {
            Agent *curAgent = *it;
            curAgent->updateStrategyScore(winning);
        }
      
        cout << "Strategy Score: " << '\n';
        for (list<Strategy *>::iterator it = allStrat.begin(); it != allStrat.end(); it++)
        {
            Strategy *curStrat = *it;
            cout << curStrat->getScore() << '\n';
        }
    }
    return 0;
}

