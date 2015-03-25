#include "strategy.h"
#include "randomgenerator.h"
#include<iostream>
#include <bitset>
#include <ctime>
#include <cstdlib>
using namespace std;

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

void initStrategy(list<Strategy *> *allStrategy)
{
	vector<int> temp;
	//int counter = 1;
	for (int i = 1; i < 21; i++){
		bitset<5> bin(i);
		for (int j = 0, counter = 1; j < bin.size(); j++, counter++){
			if (bin.at(j) == 0)
				temp.push_back(-1);
			else
				temp.push_back(1);
			if (j == 4) j = -1;
			if (counter == 8){
				Strategy *strat = new Strategy(temp);
				allStrategy->push_back(strat);
				temp.clear();
				break;
			}
		}
	}

}
