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
    win = 0;
    lose = 0;
	decisionPattern = randDecision;
}

//! Returns the decision pattern used by this strategy
//!
//! return a vector containing the decision pattern used. 0 represents staying home and 1 going fishing.
vector<int> Strategy::getDecisionPattern()
{
	return decisionPattern;
}

//! \brief returns the score
//! This value represents the number of wins that an agent has made using this strategy
//! \return the strategy score
int Strategy::getScore()
{
    return score;
}

//! \brief records the secess of this strategy
void Strategy::updateScore(int point)
{
	score = score + point;
    if(point == 1)
        win = win + 1;
    else
        lose = lose + 1;
}

//! \brief initializes all of the strategies
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

int Strategy::getWin()
{
    return win;
}

int Strategy::getLose()
{
    return lose;
}

void Strategy::clearWin()
{
    win = 0;
}

void Strategy::clearLose()
{
    lose = 0;
}
