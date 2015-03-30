#include <iostream>
#include <string>
#include <stdio.h>
#include "agent.h"

using namespace std;

void main()
{
	list<Strategy *> allStrat; // holds all the strategies
	initStrategy(&allStrat); // initialize strategies

	list<Agent *> allAgent; // holds all the dummy agent
	int numofAgent = 1;
	initAgent(&allAgent, numofAgent, allStrat); // initialize agents

	// retrieve agents from list
	list<Agent *>::iterator it = allAgent.begin();
	Agent *agent1 = *it;

	// set factors value for Agent 1
	float temp1 = 67.5;
	int skill1 = 5;
	int duration1 = 24;
	int com1 = 1;

	// setting up initial value
	agent1->setTemp(temp1);
	agent1->setSkill(skill1);
	agent1->setFishduration(duration1);
	agent1->setCommunication(com1);

	// calculate threshold
	agent1->calcThreshold();

	// make decision
	agent1->makeEarlyDecision();
	agent1->makeDecision();
	cout << "Agent's Decision: " << agent1->getDecision() << endl;

	// setting up the agent's decision is always a minority choice
	// strategy score will go up by one point
	cout << "\nStrategy original score: " << agent1->getStrat().at(0)->getScore() << endl;
	
	if (agent1->getDecision() == -1) // agent choose to stay home
		agent1->updateStrategyScore(1); // majority go fishing
	else // agent choose to go fishing
		agent1->updateStrategyScore(-1); //majority stay home

	cout << "Strategy new score: " << agent1->getStrat().at(0)->getScore() << endl;

	// setting up the agent's decision is always a majority choice
	// strategy score will go down by one point
	cout << "\nStrategy old score: " << agent1->getStrat().at(0)->getScore() << endl;

	if (agent1->getDecision() == -1) // agent choose to stay home
		agent1->updateStrategyScore(-1); // majority stay at home
	else // agent choose to go fishing
		agent1->updateStrategyScore(1); //majority go fishing

	cout << "Strategy new score: " << agent1->getStrat().at(0)->getScore() << "\n\n";
}