#include "agent.h"
#include "randomgenerator.h"

static list<Agent *> allAgent;

Agent::Agent(vector<Strategy *> newStrat, int newSkill, int newCom, int newDur){
	//generate random history
	vector<int> randDecision = generateRandomNumber(-1, 1, 3);
	for (int i = 0; i < 3; i++){
		if (randDecision.at(i) <= 0)
			history.push_back(-1);
		else
			history.push_back(1);
	}

	//maps the strategy
    strat = newStrat;

    //initialize factors
    skill = newSkill;
    communication = newCom;
    fishduration = newDur;
    temp = 67.5;
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

int Agent::getFishDuration()
{
	return fishduration;
}

void Agent::setFishduration(int newFishDuration)
{
	fishduration = newFishDuration;
}

float Agent::getTemp()
{
	return temp;
}

//! Sets the temperature of the water
//!
//! 
//! \param newTemp the new temperature in degrees celsius
//!
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
	float C = (communication / allAgent.size()) * 20;
	float p = E + T + W + C;
	//haven't include frequency of communication in threshold
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
	else if (threshold <= 40 && earlydecison == 1)
		decision = -1;
	else
		decision = earlydecison;
}

void Agent::makeEarlyDecision()
{
	int index = 0; //hold the row number for a strategy

	if (history.at(2) == 1)
		index = index + 1;
	if (history.at(1) == 1)
		index = index + 2;
	if (history.at(0) == 1)
		index = index + 4;

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

void Agent::updateStrategyScore(int winnigScore)
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
		if (-(decision * winnigScore) > 0)
			bestStrategy->updateScore(1);
		else
			bestStrategy->updateScore(-1);
	}

}

void initAgent(int numOfAgent)
{
	list<Strategy *> *stratlist = getAllStrat();
	vector<int> randStrat = generateRandomNumber(0, 19, numOfAgent * 3);
    vector<int> randSkill = generateRandomNumber(1, 5, numOfAgent);
    vector<int> randDur = generateRandomNumber(1, 24, numOfAgent);
    vector<int> randCom = generateRandomNumber(0, numOfAgent, numOfAgent);

	vector<Strategy *> strat;
	for (int i = 0; i < numOfAgent; i++)
	{
		for (int j = 0; j < 3; j++){
			list<Strategy *>::iterator it = stratlist->begin();
            advance(it, randStrat.at(2*i + j));
			strat.push_back(*it);
		}
        Agent *newAgent = new Agent(strat, randSkill.at(i), randCom.at(i), randDur.at(i));
		allAgent.push_back(newAgent);
		strat.clear();
	}
}

int Agent::getEarlyDecision()
{
	return earlydecison;
}

float Agent::getThreshold()
{
	return threshold;
}

list<Agent *> *getAllAgent()
{
	return &allAgent;
}

