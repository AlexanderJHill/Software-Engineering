#include "agent.h"
#include "randomgenerator.h"

static list<Agent> all_agent;

Agent::Agent(){
	vector<double> randDecision = generateRandomNumber(-1.0, 1.0, 3);
	for (int i = 0; i < 3; i++){
		//generate random history
		if (randDecision.at(i) <= 0)
			history.push_back(-1);
		else
			history.push_back(1);

		//generate random strategy
		//Strategy *randStrat = new Strategy();
		//strat.push_back(randStrat);
	}
}

vector<Strategy *> Agent::getStrat()
{
	return strat;
}

vector<int> Agent::getHistory()
{
	return history;
}

int Agent::getDecision()
{
	return decision;
}

int Agent::getSkill()
{
	return skill;
}

void Agent::setSkill(int newSkill)
{
	skill = newSkill;
}

float Agent::getFishDuration()
{
	return fishduration;
}

void Agent::setFishduration(float newFishDuration)
{
	fishduration = newFishDuration;
}

float Agent::getTemp()
{
	return temp;
}

void Agent::setTemp(float newTemp)
{
	temp = newTemp;
}

int Agent::getCommunication()
{
	return communication;
}

void Agent::setCommunication(int newCommunication)
{
	communication = newCommunication;
}

void Agent::calcThreshold()
{
	float E = (skill / 5) * 20;
	//float F = ((num / pop) * 20) - 20; //not sure how to represent fish yet
	float T = (fishduration / 24) * 20;
	float W = (-abs((67.5 - temp) / 67.5) * 20) + 20;
	float p = E + T + W;
	//haven't include frequency of communication is threshold
	threshold = p;
}

void Agent::updateHistory()
{
	for (int i = 0; i < 2; i++)
	{
		history.at(i) = history.at(i + 1);
	}
	history.at(2) = decision;
}

void Agent::makeDecision()
{
	//isDecisionChange is to determine if we need to reward score to a strategy
	//strategy score need to be updated if the threshold didn't
	//change the earlydecision
	if (threshold >= 85 && earlydecison == -1)
		decision = 1;
	if (threshold <= 40 && earlydecison == 1)
		decision = -1;
}

void Agent::makeEarlyDecision()
{
	int index = 0; //hold the row number for a strategy

	if (history.at(2) == 1)
		index = index + 4;
	if (history.at(1) == 1)
		index = index + 2;
	if (history.at(0) == 1)
		index = index + 1;

	//get the highest score of strategy
	Strategy *bestStrategy = strat.at(0);
	int highest = bestStrategy->getScore();
	for (int i = 1; i < 3; i++)
	{
		Strategy *tempStrat = strat.at(i);
		if (tempStrat->getScore() > highest)
		{
			bestStrategy = tempStrat;
			highest = bestStrategy->getScore();
		}

	}

	//set the early decision
	vector<int> decisionPattern = bestStrategy->getDecisionPattern();
	earlydecison = decisionPattern.at(index);
}

void Agent::updateStrategyScore(int minoritydecision)
{
	//strategy score will not be update if earlydecision is changed
	//by the threshold
	if (earlydecison == decision)
	{
		//get the recently used strategy: determine by the highest score.
		Strategy *bestStrategy = strat.at(0);
		int highest = bestStrategy->getScore();
		for (int i = 1; i < 3; i++)
		{
			Strategy *tempStrat = strat.at(i);
			if (tempStrat->getScore() > highest)
			{
				bestStrategy = tempStrat;
				highest = bestStrategy->getScore();
			}

		}

		//update the score. Strategy score added by 1 if the agent's decision is
		//equal to minoritydecision. Strategy score is minus by 1 if the agent's
		//decision is not equal to minoritydecision
		if (decision == minoritydecision)
			bestStrategy->updateScore(1);
		else
			bestStrategy->updateScore(-1);
	}

}
