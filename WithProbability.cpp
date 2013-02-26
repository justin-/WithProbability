#include <stdlib.h>

/*
* WithProbability(double p) - Returns boolean true with an approximate frequency of "p"
* NOTE: The PRNG must be seeded with srand() before calling this function for the first time
*/
bool WithProbability (double p)
{
	double p_adj = p * 100;
	double rng = (double)(rand() % 101); /* [0, 100) */

	if (rng <= p_adj)
		return true;
	else
		return false;
}