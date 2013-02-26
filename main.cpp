#include <iostream>
#include <time.h>
#include "WithProbability.h"

using namespace std;

/* todo: add argument support? */
int main()
{
	srand((unsigned int) time(NULL));	

	double p = 0.33333;
	const int NUM_SIMULATIONS = 100000;
	int results_true = 0;
	int results_false = 0;

	int i;
	for (i = 0; i < NUM_SIMULATIONS; i++)
	{
		if (WithProbability(p))
			results_true++;
		else
			results_false++;
	}

	double simulated_p = ((double)results_true / (double)NUM_SIMULATIONS);

	cout << "Simulations: \t\t\t" << NUM_SIMULATIONS << endl;
	cout << "True: \t\t\t\t" << results_true << endl;
	cout << "False: \t\t\t\t" << results_false << endl;
	cout << "Desired Probability: \t\t" << p << endl;
	cout << "Simulated Probability: \t\t" << simulated_p << endl;
	cout << "Difference: \t\t\t";
	if (simulated_p > p) /* todo: compare floats properly */
		cout << "+";
	else if (simulated_p < p)
		cout << "-";
	cout << fabs((p - simulated_p)) << endl;

	return 0;
}