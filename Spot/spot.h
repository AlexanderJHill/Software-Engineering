#ifndef ____spot__
#define ____spot__

#include <stdio.h>
class Spot{
private:
    double maxcapacity;//max agents per spot
    int numAgent;//number of agents possibly going fishing per spot


public:
    Spot();//initialize
    void setCap(double cap);//set the maxcapacity per spot
    int getSpotCapacity();//get back maxcapacity
    void setAgentNum(int fisherNum);//total number of agents possibly going to spot
    int getAgentNum();//get back total deciding agents
    double crowdness(double goFish);//calculate the crowdness
};

#endif /* defined(____spot__) */
