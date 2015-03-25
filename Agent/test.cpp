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
	list<Strategy *> *allStrat = new list<Strategy *>();
	initStrategy(allStrat);
	list<Strategy *>::iterator it = allStrat->begin();

	int i = 0;
	while (i < allStrat->size()){
		Strategy *strat = *it;
		vector<int> decision = strat->getDecisionPattern();
		cout << "Strategy " << i << endl;
		for (int j = 0; j < decision.size(); j++)
		{
			cout << decision.at(j) << endl;
		}
		it++; i++;
	}
	cout << "Length: " << allStrat->size();



}