#ifndef ____results__
#define ____results__

#include <stdio.h>

class Results{
private:
    float capital;
    float bestStratIndex;
    float bestStratScore;
    float avgStratScore;
public:
    Results();
    void computeAgentResults(float results,float decision);
    float getAgentResults();
    
    
};


#endif /* defined(____results__) */
