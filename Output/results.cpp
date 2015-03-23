
#include <stdio.h>
#include "results.h"
#include "strategy.h"
#include<iostream>

//Constructor
Results::Results(){
    success = 0;//Initial
}

//result should be the minority choice, oppposite of majority decision
void Results::computeAgentsSuccess(int majority,int decided){

    if(majority == decided)	//lose
    {
        success--;
    }
    else			//win
    {
        success++;
    }
}
int Results::getAgentsSuccess(){
    
    return success;
    
}

//How crowded a single spot would be, in percentages
//Number of locations should be also counted in(not implemented below)
//goFish shouldt exceed the limit of fisherman allowed
float Results::computeCrowdness(float goFish){
    //Test values
    float fisherMax = 50;//Maximum fisherman allowed
    //For one location only
    float crowd = (goFish/fisherMax)*100;//percentage
    return crowd;
}



//Test
/*
int main (int argc, char** argv){
    Results a;
    a.computeAgentsSuccess(1,-1);
    int b =  a.getAgentsSuccess();
    std::cout<<b<<'\n';
    float gofish = 25;
    float c = a.computeCrowdness(gofish);
    std::cout<<c<<'\n';
    return 0;
}
*/
