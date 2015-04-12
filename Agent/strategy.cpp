#include "strategy.h"
#include "randomgenerator.h"
#include<string>
#include <bitset>
#include <ctime>
#include <cstdlib>
using namespace std;

static list<Strategy *> allStrategy;

//Strategy constructor
Strategy::Strategy(vector<int> randDecision){
    score = 0; //Initial
	decisionPattern = randDecision;
}

vector<int> Strategy::getDecisionPattern()
{
	return decisionPattern;
}

int Strategy::getScore()
{
	return score;
}

void Strategy::updateScore(int point)
{
	score = score + point;
}

void initStrategy()
{
	vector<int> temp;
	for (int i = 1; i < 21; i++){
		bitset<5> bin(i); 
		for (int j = 0, counter = 1; j < bin.size(); j++, counter++){
			if (bin.to_string().at(j) == '0')
				temp.push_back(-1);
			else
				temp.push_back(1);
			if (j == 4) j = -1;
			if (counter == 8){
				Strategy *strat = new Strategy(temp);
				allStrategy.push_back(strat);
				temp.clear();
				break;
			}
		}
	}

}

list<Strategy *> *getAllStrat()
{
	return &allStrategy;
}
