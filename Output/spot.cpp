#include "spot.h"
Spot::Spot(){
}

/* Precondition: A "Spot" has been initialized
 Postcondition: maxcapacity of fisherman variable is initialized for a given spot
 */
Spot::Spot(int cap) {
    maxcapacity = cap;
}

/* Precondition: maxcapacity is initialized
 Postcondition: None
 Description: Returns a spot maxcapacity
 */
int Spot::getSpotCapacity() {
    return maxcapacity;
}

/* Precondition: The number of Agents going to this specific spot has been decided.
 Postcondition: The outcome of this spot has been decided
 */
double Spot::wonThisTurn(int fisher) {
    return (((double)fisher)/((double)maxcapacity));
}
