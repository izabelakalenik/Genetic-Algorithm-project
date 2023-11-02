#include "Individual.h"
#include <iostream>
#include "RandomGenerator.h"

using namespace std;


Individual::Individual()
= default;

Individual::Individual(KnapsackProblem& knapsackProblem)
{
	generateGenotype(knapsackProblem);
}

Individual::~Individual()
= default;

vector<int>& Individual::getGenotype()
{
	return genotype;
}

double Individual::getFitness()
{
	return fitness;
}

void Individual::showGenotype()
{
	for (int i = 0; i < genotype.size(); i++)
	{
		cout << genotype[i];
	}
}

void Individual::generateGenotype(KnapsackProblem& knapsackProblem)
{
	const int numberOfItems = knapsackProblem.getNumberOfItems();

	for (int i = 0; i < numberOfItems; i++)
	{
		genotype.push_back(RandomGenerator::generateInt(0, 1));
	}

}

double Individual::calculateFitness(KnapsackProblem& knapsackProblem)
{
	if (knapsackProblem.evaluateSolution(genotype).empty() == true)
	{
		fitness = 0;
	}
	else
	{
		fitness = knapsackProblem.evaluateSolution(genotype)[1];
	}

	return fitness;
}

void Individual::mutate(double mutProb)
{

	for (int i = 0; i < genotype.size(); i++)
	{
		if (RandomGenerator::generateDouble(0, 1) < mutProb)
		{
			if (genotype[i] == 0)
			{
				genotype[i] = 1;
			}
			else
			{
				genotype[i] = 0;
			}

		}
	}

}

vector <Individual> Individual::cross(double crossProb, KnapsackProblem& knapsackProblem, Individual& individual)
{

	vector<Individual> kids;


	if (RandomGenerator::generateDouble(0, 1) < crossProb)
	{

		int intersectionPoint = RandomGenerator::generateInt(1, knapsackProblem.getNumberOfItems() - 1);

		Individual kid1;
		Individual kid2;

		for (int i = 0; i < intersectionPoint; i++)
		{
			kid1.genotype.push_back(genotype[i]);
			kid2.genotype.push_back(individual.genotype[i]);
		}
		for (int i = intersectionPoint; i < individual.genotype.size(); i++)
		{
			kid1.genotype.push_back(individual.genotype[i]);
			kid2.genotype.push_back(genotype[i]);
		}

		kids.push_back(kid1);
		kids.push_back(kid2);

	}
	else
	{
		kids.push_back(*this);
		kids.push_back(individual);

	}

	return kids;

}
