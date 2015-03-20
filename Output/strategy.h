#ifndef ____strategy__
#define ____strategy__

#include <stdio.h>
//strategy class
class Strategy{
private:
    int score;
    int decision;
public:
    Strategy();
    float getThreshold();
    int earlyDecision(int early);
    int getDecision();
    int stratScore(int majority);
};

#endif /* defined(____strategy__) */
