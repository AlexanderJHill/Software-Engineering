#ifndef ____strategy__
#define ____strategy__

#include <stdio.h>
#include <vector>
#include <list>
using namespace std;

class Strategy{
private:
    int score; //hold score for strategy

	//!brief represents a strategy for determining the conditions of going fishing.
	//since each startegy depends on 3 previous outcomes, so posiible output
	//for one strategy is 8.
	//the sequence for the 3 previous outcomes would be:
	//000,001,010,...,111
	//special case for starategy: 0->stay at home, 1->go fishing
	vector<int> decisionPattern;
public:
    Strategy(vector<int> randDecision);
	vector<int> getDecisionPattern();
	int getScore();
	void updateScore(int point);
};

void initStrategy();
list<Strategy *> *getAllStrat();
#endif /* defined(____strategy__) */
