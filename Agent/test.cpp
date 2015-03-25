// uniform_real_distribution example
#include <iostream>
#include <chrono>
#include <random>
#include <list>
#include <bitset>
#include "randomgenerator.h"
#include "agent.h"
#include "strategy.h"
using namespace std;

void main()
{
	//maybe can be moved to Agent class
	list<Strategy *> allStrat; //holds all the strategy
	initStrategy(&allStrat); //initialize the strategy

	list<Agent *> allAgent; //hold all the dummy agent
	int numofAgent = 200;
	initAgent(&allAgent, numofAgent, allStrat);

	//get a random value of factors.
	float temp = 62.5;
	vector<int> randSkill = generateRandomNumber(1, 5, numofAgent);
	vector<int> randDuration = generateRandomNumber(1, 24, numofAgent);
	vector<int> randCom = generateRandomNumber(0, numofAgent, numofAgent);

	//set the value of factors
	//start calculation of each agent
	int counter = 0;
	int winner = 0;
	for (list<Agent *>::iterator it = allAgent.begin(); it != allAgent.end(); it++)
	{
		Agent *curAgent = *it;
		curAgent->setTemp(temp);
		curAgent->setCommunication(randCom.at(counter));
		curAgent->setFishduration(randDuration.at(counter));
		curAgent->setSkill(randSkill.at(counter));

		curAgent->makeEarlyDecision();
		curAgent->calcThreshold();
		curAgent->makeDecision();
		curAgent->updateHistory();

		//keep track of decision to get the winner side
		winner = winner + curAgent->getDecision();
		//cout << curAgent->getDecision() << endl;
	}

	//updating the strategy score
	for (list<Agent *>::iterator it = allAgent.begin(); it != allAgent.end(); it++)
	{
		Agent *curAgent = *it;
		curAgent->updateStrategyScore(winner);
	}

	//display strategy score
	cout << "Strategy Score" << endl;
	for (list<Strategy *>::iterator it = allStrat.begin(); it != allStrat.end(); it++)
	{
		Strategy *curStrat = *it;
		cout << curStrat->getScore() << endl;
	}




	//display the strategy pattern (20 Strategies)
	/*list<Strategy *>::iterator it = allStrat.begin();
	int i = 0;
	while (i < allStrat.size()){
		Strategy *strat = *it;
		vector<int> decision = strat->getDecisionPattern();
		cout << "Strategy " << i << endl;
		for (int j = 0; j < decision.size(); j++)
		{
			cout << decision.at(j) << endl;
		}
		it++; i++;
	}
	cout << "Length: " << allStrat.size() << endl;*/

	//Listing all the agents' strategies. 
	/*for (list<Agent *>::iterator it = allAgent.begin(); it != allAgent.end(); it++)
	{
		Agent *curAgent = *it;
		vector<Strategy *> curStart = curAgent->getStrat();
		for (int i = 0; i < curStart.size(); i++){
			cout << "Strategy " << i << endl;
			vector<int> stratpattern = curStart.at(i)->getDecisionPattern();
			for (int j = 0; j < stratpattern.size(); j++){
				cout << stratpattern.at(j) << endl;
			}
		}
	}*/

	//display the history
	/*int count = 1;
	for (list<Agent *>::iterator it = allAgent.begin(); it != allAgent.end(); it++)
	{
		cout << "Agent " << count << endl;
		Agent *curAgent = *it;
		vector<int> curHis = curAgent->getHistory();
		for (int i = 0; i < curHis.size(); i++){
			//cout << "History " << i << endl;
			cout << curHis.at(i) << endl;
		}
	}*/
}