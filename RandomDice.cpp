#include"RandomDice.h"
#include <random>

/**
 * Produces random integer values i, uniformly distributed on the closed interval.
 * This implementation is inspired by the implementation found at cppreference.com
 */
int RandomDice::getValue() {
	
	std::random_device rd;  // Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); // Standard mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> dice(1, 6);
 
 	return dice(gen);
 	
}
