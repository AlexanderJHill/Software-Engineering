#include "results.h"
#include "strategy.h"
#include<iostream>

//Constructor
Results::Results(){
    capital = 0;
}

//capital == success points
float Results::computeAgentResults(float result,float decision){
    float rt;
    float tmpSum = 0;
    //Strategy a;
    //float decision = a.getDecision();
    if(result == decision)	//win
    {
        capital++;
        rt = 1;
    }
    else			//lose
    {
        capital--;
        rt = 0;
    }
    /*
    //update strategy scores
    for(int i=0;i<10;i++)	//10 strategies
    {
        stratPter[i]->updateScore(result,STI);
        //remove low scored strat
        if(stratPter[i]->getScore() < 0)
        {
            stratPter[i] = new Strategy;
        }
        //update the new best strategy
        tmpSum += stratPter[i]->getScore();
        if(stratPter[i]->getScore() > bestStratScore)
        {
            bestStratIndex = i;
            bestStratScore = stratPter[i]->getScore();
        }
    }
    */
    
   
    avgStratScore = tmpSum/10;
    return rt;
    
    
}
float Results::getAgentResults(){
     std::cout<<capital<<'\n';
    return capital;
    
}

//Test 
int main (int argc, char** argv){
   
    Strategy a;
    float decision = a.getDecision();
    Results b;
    float w = 1;
    b.computeAgentResults(w,decision);
    
    
    
    
    return 0;
}
