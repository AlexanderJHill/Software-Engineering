//Created and edited by Ameer Fiqri Barahim
#include "agent.h"
#include "randomgenerator.h"

static list<Agent *> allAgent;

Agent::Agent(vector<Strategy *> newStrat, int newSkill, int newCom){
	//generate random history
	vector<int> randDecision = generateRandomNumber(-1, 1, 3);
	for (int i = 0; i < 3; i++){
		if (randDecision.at(i) <= 0)
			history.push_back(-1);
		else
			history.push_back(1);
	}

    //initialize agent's record
    boostscore[0] = 0;
    boostscore[1] = 0;
    agentscore[0] = 0;
    agentscore[1] = 0;

	//maps the strategy
    strat = newStrat;

    //initialize factors
    skill = newSkill;
    communication = newCom;
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

int Agent::getFishingDuration()
{
    return fishingduration;
}

void Agent::setFishingduration(int newFishingDuration)
{
    fishingduration = newFishingDuration;
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
    float E = ((float)skill / 5) * 20;
	//float F = ((num / pop) * 20) - 20; //not sure how to represent fish yet
    float T = ((float)fishingduration / 24) * 20;
    float W = (-abs((67.5 - (float)temp) / 67.5) * 20) + 20;
    float C = ((float)communication / allAgent.size()) * 20;
	float p = E + T + W + C;

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
    //make the final decision
    //this decision making is based on early decision and threshold
    //if the threshold is >85, and the early decision is -1, stay home,
    //the agent should decide to go fishing since all the factors are good.
    //if the threshold is <40 and the early decision is 1, go fishing,
    //agent should stay home because he will not have a good experience
    //to fish with a bad factors
    if (threshold >= 65 && earlydecison == -1)
		decision = 1;
    else if (threshold <= 20 && earlydecison == 1)
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

void Agent::updateStrategyScore(int majorityScore)
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
        if (-(decision * majorityScore) > (0.1 * allAgent.size()))
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
    vector<int> randCom = generateRandomNumber(0, numOfAgent, numOfAgent);

	vector<Strategy *> strat;
	for (int i = 0; i < numOfAgent; i++)
	{
		for (int j = 0; j < 3; j++){
			list<Strategy *>::iterator it = stratlist->begin();
            advance(it, randStrat.at(2*i + j));
            strat.push_back(*it);
		}
        Agent *newAgent = new Agent(strat, randSkill.at(i), randCom.at(i));
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

void runAgentSimulation()
{
    int majScore = 0;
    int index = 0;
    vector<int> randDur = generateRandomNumber(1, 24, allAgent.size());

    //main calculation
    for(list<Agent *>::iterator it = allAgent.begin(); it != allAgent.end(); it++, index++)
    {
        Agent *curAgent = *it;
        curAgent->setFishingduration(randDur.at(index));
        curAgent->makeEarlyDecision();
        curAgent->calcThreshold();
        curAgent->makeDecision();
        curAgent->updateHistory();

        majScore = majScore + curAgent->getDecision();

        //update agent's boost score
        vector<int> his = curAgent->getHistory();
        if((his.at(1) + his.at(2)) == 2)
        {
            curAgent->updateBoostScore(0,1);
            curAgent->updateBoostScore(1,1);
        }
        if((his.at(0)+his.at(1)+his.at(2)) == -3)
        {
            curAgent->updateBoostScore(0,-1);
            curAgent->updateBoostScore(1,-1);
        }

        //check boostscore cummulative and update skill/commnication/strategy
        if(curAgent->getBoostScore(0) > 8)
        {
            if(curAgent->getSkill() < 5)
                curAgent->setSkill(curAgent->getSkill() + 1);
            curAgent->updateBoostScore(0,-9); //reset boost score
        }

        if(curAgent->getBoostScore(1) > 3)
        {
            if(curAgent->getCommunication() < allAgent.size())
                curAgent->setCommunication(curAgent->getCommunication()+ 1);
            curAgent->updateBoostScore(1,-4); //reset boost score
        }
    }

    //update agent score and strategy score and check if agent needs to adapt new strategy
    for(list<Agent *>::iterator it = allAgent.begin(); it != allAgent.end(); it++)
    {
        Agent *curAgent = *it;
        curAgent->updateStrategyScore(majScore);
        curAgent->updateAgentScore(majScore);
    }

    for(list<Agent *>::iterator it = allAgent.begin(); it != allAgent.end(); it++)
    {
        Agent *curAgent = *it;
        if(curAgent->getAgentScore(1) == 5) //check if agent lose 5 times
        {
            curAgent->adaptNewStrat();
            curAgent->resetAgentScore();
        }
    }

}

//boost score will be added by 1 if the most 2 recent history of the agent
//is 1, go fishing.
//boost score will be reduced by 1 if all three recent history is -1, stay home
void Agent::updateBoostScore(int index, int score)
{
    boostscore[index] = boostscore[index] + score;

    //boostscore should not go below zero
    if(boostscore[index] < 0)
        boostscore[index] = 0;
}

int Agent::getBoostScore(int index)
{
    return boostscore[index];
}

void Agent::adaptNewStrat()
{
    //get the highest score strategy
    list<Strategy *>::iterator it = getAllStrat()->begin();
    Strategy *bestStrat = *it;
    for(it++; it != getAllStrat()->end(); it++)
    {
        Strategy *curStrat = *it;
        if(curStrat->getScore() > bestStrat->getScore())
            bestStrat = curStrat;
    }

    //get the lowest score strategy of an agent
    for(list<Agent *>::iterator it = allAgent.begin(); it != allAgent.end(); it++)
    {
        Agent *curAgent = *it;
        vector<Strategy *> agentStrat = curAgent->getStrat();
        int lowScoreIndex = 0;
        for(int i = 1; i < 3; i++)
        {
            if(agentStrat.at(i)->getScore() < agentStrat.at(lowScoreIndex)->getScore())
                lowScoreIndex = i;
        }
        //save the new set of strategies
        agentStrat.at(lowScoreIndex) = bestStrat;
        curAgent->setStrategy(agentStrat);
    }
}

void Agent::setStrategy(vector<Strategy *> newStrat)
{
    strat = newStrat;
}

void Agent::updateAgentScore(int majorityScore)
{
    if (-(decision * majorityScore) > (0.1 * allAgent.size()))
    {
        agentscore[0] = agentscore[0] + 1; //add agent score by one if he made a minoity decision
    }

    else
    {
        agentscore[0] = 0;
        agentscore[1] = agentscore[1] + 1;
    }

    if(agentscore[0] == 3)
        agentscore[1] = 0; //reset the agent lose count if the agent wins 3 times in a row
}

int Agent::getAgentScore(int index)
{
    return agentscore[index];
}

void Agent::resetAgentScore()
{
    agentscore[0] = 0;
    agentscore[1] = 0;
}


