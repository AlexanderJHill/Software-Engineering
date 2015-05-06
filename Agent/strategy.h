//Created and edited by Ameer Fiqri Barahim
#ifndef ____strategy__
#define ____strategy__

#include <stdio.h>
#include <vector>
#include <list>
using namespace std;

class Strategy{
private:
    int score; //hold score for strategy
    int win;
    int lose;

	//!brief represents a strategy for determining the conditions of going fishing.
	//since each startegy depends on 3 previous outcomes, so posiible output
	//for one strategy is 8.
	//the sequence for the 3 previous outcomes would be:
	//000,001,010,...,111
	//special case for starategy: 0->stay at home, 1->go fishing
	vector<int> decisionPattern;
public:
    Strategy(vector<int> randDecision);
    void updateScore(int point);

	vector<int> getDecisionPattern();
	int getScore();
    int getWin();
    int getLose();

    void clearWin();
    void clearLose();


};

void initStrategy();
list<Strategy *> *getAllStrat();
#endif /* defined(____strategy__) */
