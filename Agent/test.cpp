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
	int numofAgent = 10;
	initAgent(&allAgent, numofAgent, allStrat);

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
}