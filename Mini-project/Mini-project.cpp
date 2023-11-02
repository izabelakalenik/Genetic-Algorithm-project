#include <iostream>
#include "KnapsackProblem.h"
#include "GeneticAlgorithm.h"

using namespace std;


int main()
{

	try
	{
		KnapsackProblem problem("Instance.txt");

		cout << "Knapsack capacity: " << problem.getKnapsackCapacity() << endl;
		problem.showListOfItems();
		cout << "----------------------------------------------\n";

		GeneticAlgorithm algorithm(10, 0.8, 0.6, problem, 20);
		Individual finalSolution = algorithm.getBestSolution();

		cout << "Final solution fitness: " << finalSolution.getFitness() << endl;
		cout << "Final solution genotype: ";
		finalSolution.showGenotype();
		cout << endl;
		cout << "Final solution list of items: \n";
		problem.showListOfFinalItems(finalSolution.getGenotype());


	}
	catch (invalid_argument& e)
	{
		cout << "Invalid argument: " << e.what();
	}



}
