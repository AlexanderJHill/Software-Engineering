#ifndef ____compute__
#define ____compute__

#include "agent.h"
#include <vector>
#include <stdio.h>

class Compute{
    private:
    int round;
    
    public:
    Compute();
    void calcOutput();
    void resultGen();
    void dataUpdate();
    int stratGuide();
    ~Compute();
    
};

int getMinorityDecision(vector<Agent> allAgent[]);


#endif /* defined(____compute__) */
