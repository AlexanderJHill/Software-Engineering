#ifndef ____spot__
#define ____spot__

#include <stdio.h>
class Spot{
private:
    double maxcapacity;
    double goFish;
    int numAgent;

public:
    Spot();
    void setCap(double cap);
    int getSpotCapacity();
    void setAgentNum(int fisherNum);
    int getAgentNum();
    double crowdness();
    void decideToGoFish();
};

#endif /* defined(____spot__) */
