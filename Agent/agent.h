#ifndef _AGENT
#define _AGENT

//! \file agent.h 
//! \brief agent represents 1 agent's experience and decisions

#include "strategy.h"
#include <list>
#include <vector>

//!
//! \brief Simulates the actions of an individual Fisher  
//!  
//!


using namespace std;

<<<<<<< HEAD
=======
static int numOfAgent;  /*! records the total number of agents created. */

/*! 

influence threshold, 
	
	if based on report > 70 
		will make agent's decison change to 1
	if < 70 
		agent's decision remain the same
		
	new rule: p => 85 change decision to 1
		40 < p < 85 decision remain
		p <= 40 decision change to -1
*/

//! \brief agent represents 1 agent's experience and decisions
>>>>>>> origin/master
class Agent{
private:
	vector<Strategy *> strat; 	//!< holds the 3 unique strategies
	vector<int> history; 		//!< holds the last 3 outcomes
	int decision; 				//!< new decision *have to calculate, use makeDecision
	int earlydecison; 			//!< based on history sequence and strategy
	double skill; 				//!< will be 1-5 *from input
	float fishduration; 		//!< *from input
	float temp; 				//!< *from input
	//int typefish; //number of fish *from input
	int communication; 			//!< *from input
	
	//! influence threshold, if based on report > 70 will make agent's decison change to 1
	//! < 70 agent's decision remain the same
	//! new rule: p => 85 change decision to 1
	//!			 40 < p < 85 decision remain
	//!			 p <= 40 decision change to -1
	float threshold; //calculate using calcThreshold


public:
	Agent(vector<Strategy *> strat); 	//!< default constructor
	void updateStrategyScore(int winnigScore);
	void calcThreshold();
	void makeEarlyDecision();
	void makeDecision(); 				//!< will be based on earlydecision and threshold
	void updateHistory(); 				//!< push new decision on

	//! Sets the temperature of the water
	//!
	//! 
	//! \param newTemp the new temperature in degrees Celsius
	//! 
	void setTemp(float newTemp); 		
	void setSkill(int newskill); 		//!< can be randomize
	void setFishduration(float newFishDuration); //!< can be randomize
	void setCommunication(int newCommunication);

	vector<int> getHistory();
	
	//! Returns the Decision of the Agent
	//! \return the decision of the Agent
	int getDecision();
	
	//! Returns the amount the agent communicates with other agents. 
	int getCommunication();
	
	//! Returns the current skill of the agent 
	int getSkill();
	//int getTypeFish();
	
	float getTemp();
	
	//! Returns the decay of the fish population
	//!
	//! \return the decay value used
	float getFishDuration();
	
	
	int getEarlyDecision();
	float getThreshold();
	
	//! Returns the statagies used by this agent
	//! Agents can change stratagies as they learn
	//!
	//! \return a vector containing the stratagies. This will normally return 3 items. 
	vector<Strategy *> getStrat();
};

void initAgent(int numOfAgent);
list<Agent *> *getAllAgent();

//struct list *get_all_agent();
#endif

//for typefish, not sure how to implement it yet. maybe can use enum type. 
