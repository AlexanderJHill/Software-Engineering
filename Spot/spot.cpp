#include "spot.h"
#include "agent.h"

Spot::Spot(){
}

/*
maxcapacity of fisherman variable is initialized for a given spot
 */
Spot::Spot(int cap) {
    maxcapacity = cap;
}

/* @pre: maxcapacity is initialized
@post: None
@return: Returns a spot maxcapacity
 */
int Spot::getSpotCapacity() {
    return maxcapacity;
}

/* @pre: The number of Agents going to this specific spot has been decided.
 @post: The outcome of this spot has been decided
*/
double Spot::crowdness() {
    return (((double)goFish)/((double)maxcapacity));
}
/*
 Majority decides to fish or not according to decision
 */
int Spot::decideToGoFish(){
    //Get the Agents decision
    
    if (decision == 1){
        goFish++;
    }
    else if(decision == -1){
        goFish--;
    }
    
}
