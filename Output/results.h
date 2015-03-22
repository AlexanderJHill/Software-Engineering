#ifndef ____results__
#define ____results__

#include <stdio.h>
#include "strategy.h"
class Results{
private:
    int success;
    int decision;
public:
    Results();
    void computeAgentsSuccess(int majority,int decided);
    int getAgentsSuccess();
    float computeCrowdness(float goFish);
};
#endif /* defined(____results__) */
