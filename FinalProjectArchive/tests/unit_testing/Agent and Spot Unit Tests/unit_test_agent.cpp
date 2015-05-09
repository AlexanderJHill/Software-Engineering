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
	int numofAgent = 2;
	initAgent(&allAgent, numofAgent, allStrat); // initialize agents

	// set factors value for Agent 1
	float temp1 = 67.5;
	int skill1 = 5;
	int duration1 = 24;
	int com1 = 2;

	// set factors value for Agent 2
	float temp2 = 55.5;
	int skill2 = 1;
	int duration2 = 8;
	int com2 = 0;

	// retrieve agents from list
	list<Agent *>::iterator it = allAgent.begin();
	Agent *agent1 = *it;
	it++;
	Agent *agent2 = *it;

	// setting up initial value
	agent1->setTemp(temp1);
	agent1->setSkill(skill1);
	agent1->setFishduration(duration1);
	agent1->setCommunication(com1);

	agent2->setTemp(temp2);
	agent2->setSkill(skill2);
	agent2->setFishduration(duration2);
	agent2->setCommunication(com2);

	// printing agents' history
	vector<int> his1 = agent1->getHistory();
	vector<int> his2 = agent2->getHistory();

	int index1 = 0; //hold the row number for a strategy
	if (his1.at(2) == 1) index1 = index1 + 1;
	if (his1.at(1) == 1) index1 = index1 + 2;
	if (his1.at(0) == 1) index1 = index1 + 4;

	int index2 = 0; //hold the row number for a strategy
	if (his2.at(2) == 1) index2 = index2 + 1;
	if (his2.at(1) == 1) index2 = index2 + 2;
	if (his2.at(0) == 1) index2 = index2 + 4;

	cout << "History" << endl;
	printf("Agent 1: %2d %2d %2d", his1.at(0), his1.at(1), his1.at(2));
	printf("\tIndex of strategy: %d\n", index1);
	printf("Agent 2: %2d %2d %2d", his2.at(0), his2.at(1), his2.at(2));
	printf("\tIndex of strategy: %d\n", index2);

	// make early decision
	agent1->makeEarlyDecision();
	agent2->makeEarlyDecision();

	// printing agents' strategy
	vector<int> strat1 = agent1->getStrat().at(0)->getDecisionPattern();
	vector<int> strat2 = agent2->getStrat().at(0)->getDecisionPattern();

	cout << "\n\nAgent 1 Strategy       Agent 2 Strategy" << endl;
	for (int i = 0; i < strat1.size(); i++)
	{
		printf(" %-2d                     %-2d\n", strat1.at(i), strat2.at(i));
	}

	// print early decision
	cout << "\n\nAgents' Early Decision" << endl;
	cout << "Agent 1: " << agent1->getEarlyDecision() << endl;
	cout << "Agent 2: " << agent2->getEarlyDecision() << endl;

	// printing agents' threshold
	agent1->calcThreshold();
	agent2->calcThreshold();

	cout << "\n\nAgents' Threshold" << endl;
	cout << "Agent 1: " << agent1->getThreshold() << endl;
	cout << "Agent 2: " << agent2->getThreshold() << endl;

	// printing final decision
	agent1->makeDecision();
	agent2->makeDecision();
	cout << "\n\nAgents' Final Decision" << endl;
	cout << "Agent 1: " << agent1->getDecision() << endl;
	cout << "Agent 2: " << agent2->getDecision() << endl;

	// printing updated history
	agent1->updateHistory();
	agent2->updateHistory();
	vector<int> updatehis1 = agent1->getHistory();
	vector<int> updatehis2 = agent2->getHistory();
	cout << "\n\nUpdated History" << endl;
	printf("Agent 1: %2d %2d %2d\n", updatehis1.at(0), updatehis1.at(1), updatehis1.at(2));
	printf("Agent 2: %2d %2d %2d\n\n", updatehis2.at(0), updatehis2.at(1), updatehis2.at(2));
}