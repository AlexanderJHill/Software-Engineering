#ifndef _AGENT
#define _AGENT

#include "strategy.h"
#include <list>
#include <vector>
using namespace std;

class Agent{
private:
	vector<Strategy *> strat; //holds the 3 unique strategies
	vector<int> history; //holds the last 3 outcomes
	int decision; //new decision *have to calculate, use makeDecision
	int earlydecison; //based on history sequence and strategy
	double skill; // will be 1-5 *from input
	float fishduration; //*from input
	float temp; //*from input
	//int typefish; //number of fish *from input
	int communication; //*from input
	//influence threshold, if based on report > 70 will make agent's decison change to 1
	// < 70 agent's decision remain the same
	// new rule: p => 85 change decision to 1
	//			 40 < p < 85 decision remain
	//			 p <= 40 decision change to -1
	float threshold;


public:
	Agent(vector<Strategy *> strat); //constructor
	vector<Strategy *> getStrat();
	void calcThreshold();
	int getDecision();
	void makeEarlyDecision();
	void makeDecision(); //will be based on earlydecision and threshold
	vector<int> getHistory();
	void updateHistory(); //push new decision
	int getSkill();
	void setSkill(int newskill);
	float getFishDuration();
	void setFishduration(float newFishDuration);
	float getTemp();
	void setTemp(float newTemp);
	//int getTypeFish();
	int getCommunication();
	void setCommunication(int newCommunication);
	void updateStrategyScore(int minoritydecision);
};

void initAgent(list<Agent *> *allAgent, int numAgent, list<Strategy *> stratlist);

//struct list *get_all_agent();
#endif

//for typefish, not sure yet how to implement it yet. maybe can use enum type. 
