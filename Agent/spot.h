//! \file spot.h 
//! \brief Used to create a spot and calculate how crowded a spot is.

#ifndef ____spot__
#define ____spot__

#include <stdio.h>
#include <vector>
//! \brief Spot is used to create a location and calculate how crowded it is.
class Spot{
private:
    double maxcapacity; 	//!< max agents per spot
    int numAgent;			//!< number of agents possibly going fishing per spot
    vector<int> locations;
public:
    
	/*! Constructor for a spot
    @pre none
    @post numAgent and maxcapacity is initialized to zero
    @return none
    */
    Spot();
    
	/*Set the maxcapcity of agents for a given spot
    @pre A spot is initialized and the number for capacity(cap) is given.
    @post The maxcapacity is set equal to the given cap
    @return none
    */
    void setCap(double cap);
    
	/*! Get the maxcapacity 
    @pre A capacity is already set
    @post none
    @return The number of maxcapacity 
    */
    double getSpotCapacity();
    
	/*! Set the number of agents possibly going to spot
    @pre Give the number of agents called fisherNum
    @post The numAgent is equal to given fisherNum
    @return none
    */
    void setAgentNum(int fisherNum);//
    
	/*! Get back total number agents
    @pre Number of agents is already set
    @post none
    @return Integer number of total agents (numAgent)
    */
    int getAgentNum();
    
	/*! Calculate how crowded a spot is
    @pre Give number of agents that decided to go fishing
    @post Percentage of crowd is calculated
    @return Percentage of fisherman going fishing
    */
    double crowdness(double goFish);
};

#endif /* defined(____spot__) */
