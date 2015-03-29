//Testing that fucntions in spot works
//Note that some are dependent to another
#include <stdio.h>
#include <iostream>
#include "spot.h"
using namespace std;

int main(){
    Spot a; //Initialize
    
    int cap = 100;//Pick a value,like 100
    a.setCap(cap);//Set cap to integer 100
    cout<<"maxcapacity: "<<a.getSpotCapacity()<<'\n';//Check if this is also 100
    
    int agents = 50;//Pick a value,like 50
    a.setAgentNum(agents);//Set number of agents to integer 50
    cout<<"numAgents: "<<a.getAgentNum()<<'\n';//Check if this is equal to 50
    
    //Test crowd percentage (50/100)*100 = 50%
    cout<<"Spot: "<<a.crowdness(agents)<<"%"<<'\n';//Check if this is 50%
    
    return 0;
}
