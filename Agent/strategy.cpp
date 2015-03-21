#include "strategy.h"
#include "randomgenerator.h"
#include<iostream>
#include <ctime>
#include <cstdlib>

//Strategy constructor
Strategy::Strategy(){
    score = 0; //Initial
	
	//generating decision pattern
	vector<double> randDecision = generateRandomNumber(-0.05, 0.05, 8);
	for (int i = 0; i < 8; i++)
	{
		if (randDecision.at(i) <= 0)
			decisionPattern.push_back(-1);
		else
			decisionPattern.push_back(1);
	}
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


/*Testing
int main (int argc, char** argv){
    Strategy a;
    a.stratScore(1);
    a.stratScore(-1);
    a.stratScore(1);
    
    
    return 0;
}
*/
