#ifndef ____spot__
#define ____spot__

#include <stdio.h>
class Spot{
private:
    int maxcapacity;
    int goFish;
    
public:
    Spot();
    Spot(int cap);
    int getSpotCapacity();
    double crowdness(int fisher);
    int decideToGoFish()
};

#endif /* defined(____spot__) */
