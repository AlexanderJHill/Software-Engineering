#ifndef ____spot__
#define ____spot__

#include <stdio.h>
class Spot{
private:
    double maxcapacity;
    double goFish;
    
public:
    Spot();
    void setCap(double cap);
    int getSpotCapacity();
    double crowdness();
    void decideToGoFish();
};

#endif /* defined(____spot__) */
