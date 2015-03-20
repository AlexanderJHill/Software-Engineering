#ifndef ____strategy__
#define ____strategy__

#include <stdio.h>

class Strategy{
private:
    float score;
    float decision;
public:
    Strategy();
    float getThreshold();
    float earlyDecision(float early);
    float getDecision();
    float stratDecide();
    float stratScore(float majority);
};

#endif /* defined(____strategy__) */
