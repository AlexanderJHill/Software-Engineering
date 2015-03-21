#include "randomgenerator.h"
#include <chrono>
#include <random>

vector<double> generateRandomNumber(double lowerBound, double upperBound, int length)
{
	// construct a trivial random generator engine from a time-based seed:
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::default_random_engine generator(seed);

	std::uniform_real_distribution<double> distribution(lowerBound, upperBound);
	
	vector<double> randNumber;
	for (int i = 0; i < length; i++){
		randNumber.push_back(distribution(generator));
	}

	return randNumber;
}