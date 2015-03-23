#ifndef ____spot__
#define ____spot__

#include <stdio.h>
class Spot{
private:
    int maxcapacity;
    
public:
    Spot();
    Spot(int cap);
    int getSpotCapacity();
    double wonThisTurn(int fisher);
};

#endif /* defined(____spot__) */
