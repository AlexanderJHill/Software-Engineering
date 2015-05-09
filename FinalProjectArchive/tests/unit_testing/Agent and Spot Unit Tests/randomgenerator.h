#ifndef _RANDOM_GENERATOR
#define _RANDOM_GENERATOR
/*! \file randomgenerator.h 
	\brief construct a trivial random generator engine from a time-based seed:

*/


#include <vector>
using namespace std;

//! \fn vector<int> generateRandomNumber(int lowerBound, int upperBound, int length)
//! \brief Generates a vector of random numbers from some minimum bound to an upper bound.
//!
//!	\param lowerBound the lower bound that the random numbers can have.
//!	\param upperBound the upper bound of the random numbers
//! \param length the number of random numbers to generate.
//!	\return a vector containing length number of elements from 0 - (length-1)
//!
vector<int> generateRandomNumber(int lowerBound, int upperBound, int length);

#endif