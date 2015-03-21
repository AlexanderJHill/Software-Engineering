// uniform_real_distribution example
#include <iostream>
#include <chrono>
#include <random>
#include "randomgenerator.h"
#include "agent.h"
using namespace std;

void main()
{
	Agent agent[10];
	vector<Strategy *> strat = agent[0].getStrat();

	//print out strategy pattern
	for (int i = 0; i < strat.size(); i++)
	{
		Strategy *s = strat.at(i);
		cout << "Strategy " << i + 1 << endl;
		vector<int> decision = s->getDecisionPattern();
		for (int j = 0; j < decision.size(); j++)
		{
			cout << decision.at(j) << endl;
		}
	}
}