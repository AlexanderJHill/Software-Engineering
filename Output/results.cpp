#include "results.h"
#include "strategy.h"
#include<iostream>

//Constructor
Results::Results(){
    capital = 0;
}

//capital == success points
 //result should be the minority choice
void Results::computeAgentResults(float result,float decision){
    //float rt;
   // float tmpSum = 0;
    //Strategy a;
    //float decision = a.getDecision();
   
    if(result == decision)	//win
    {
        capital++;
       // rt = 1;
    }
    else			//lose
    {
        capital--;
        //rt = 0;
    }
    
}
float Results::getAgentResults(){
    // std::cout<<capital<<'\n';
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
