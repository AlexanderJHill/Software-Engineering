//Created and edited by Ameer Fiqri Barahim
#ifndef _AGENT
#define _AGENT

#include "strategy.h"
#include <list>
#include <vector>
using namespace std;

class Agent{
private:
	vector<Strategy *> strat; 	//holds the 3 unique strategies
	vector<int> history; 		//holds the last 3 outcomes
	int decision; 			//new decision *have to calculate, use makeDecision
	int earlydecison; 		//based on history sequence and strategy
    int skill; 			// will be 1-5 *from input
    int fishingduration; 		//*from input
	float temp; 			//*from input
	//int typefish; 		//number of fish *from input
	int communication; 		//*from input

	//influence threshold, if based on report > 70 will make agent's decison change to 1
	// < 70 agent's decision remain the same
	// new rule: p => 85 change decision to 1
	//			 40 < p < 85 decision remain
	//			 p <= 40 decision change to -1
	float threshold; 		//calculate using calcThreshold

    //score use to determine if the agent's skill and communication
    //need to be increase/decrease.
    //index 0 -> skill boost score will add skill by 1 if cumulative score > 8
    //index 1 -> communication boost score will add communication by 1 if score > 3
    int boostscore[2];

    //agentscore is to keep track the wins and loses of an agent,
    //index 0 -> wins
    //index 1 -> loses; if = 5, agent will adapt new strategy
    int agentscore[2]; //keep track of the consecutive wins/loses of an agent


public:
    Agent(vector<Strategy *> newStrat, int newSkill, int newCom); //default constructor
    void updateStrategyScore(int majorityScore);
    void calcThreshold();
    void makeEarlyDecision();
    void makeDecision(); 		//will be based on earlydecision and threshold
    void updateHistory(); 		//push new decision
    void updateBoostScore(int index, int score);
    void adaptNewStrat();
    void updateAgentScore(int majorityScore);
    void resetAgentScore();

	void setTemp(float newTemp); 
	void setSkill(int newskill); 
    void setFishingduration(int newFishingDuration);
	void setCommunication(int newCommunication);
    void setStrategy(vector<Strategy *> newStrat);

	vector<int> getHistory();
	int getDecision();
	int getCommunication();
	int getSkill();
	//int getTypeFish();
	float getTemp();
    int getFishingDuration();
	int getEarlyDecision();
	float getThreshold();
    int getBoostScore(int index);
    int getAgentScore(int index);
	vector<Strategy *> getStrat();
};

void initAgent(int numOfAgent);
list<Agent *> *getAllAgent();
void runAgentSimulation(); //run all the calculation in a proper order


#endif

//for typefish, not sure how to implement it yet. maybe can use enum type. 
