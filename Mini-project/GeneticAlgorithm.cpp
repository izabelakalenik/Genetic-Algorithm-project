#include "GeneticAlgorithm.h"
#include "RandomGenerator.h"
#include <vector>
#include <stdexcept>


using namespace std;

GeneticAlgorithm::GeneticAlgorithm(int popSizee, double mutProbb, double crossProbb, KnapsackProblem& knapsackProblem, int counter)
{
	if (popSizee < 0)
	{
		throw invalid_argument("Negative size of the population\n");
	}
	if (mutProbb < 0 || mutProbb > 1)
	{
		throw invalid_argument("Wrong mutation probability\n");
	}
	if (crossProbb < 0 || crossProbb > 1)
	{
		throw invalid_argument("Wrong cross probability\n");
	}

	popSize = popSizee;
	mutProb = mutProbb;
	crossProb = crossProbb;

	run(counter, knapsackProblem);
}

GeneticAlgorithm::~GeneticAlgorithm()
= default;

void GeneticAlgorithm::generatePopulation(KnapsackProblem& knapsackProblem)
{
	for (int i = 0; i < popSize; i++)
	{
		population.push_back(Individual(knapsackProblem));
	}

}

vector<double> GeneticAlgorithm::rateSolutions(KnapsackProblem& knapsackProblem)
{
	vector<double> solutionsValues;
	double best = 0;

	for (int i = 0; i < popSize; i++)
	{
		best = population[i].calculateFitness(knapsackProblem);
		solutionsValues.push_back(best);

		if (best > bestSol.getFitness())
		{
			bestSol = population[i];
		}
	}

	return solutionsValues;

}


void GeneticAlgorithm::makeCross(KnapsackProblem& knapsackProblem)
{
	vector<Individual> newPopulation;

	for (int i = 0; i < popSize; i++) {

		Individual parent1 = doCross();
		Individual parent2 = doCross();

		vector<Individual> kids = parent1.cross(crossProb, knapsackProblem, parent2);

		newPopulation.push_back(kids[0]);
		newPopulation.push_back(kids[1]);

	}

	for (int i = 0; i < popSize; i++)
	{
		population[i] = newPopulation[i];
	}
}

Individual GeneticAlgorithm::doCross()
{

	Individual ind1 = population[RandomGenerator::generateInt(0, popSize - 1)];
	Individual ind2 = population[RandomGenerator::generateInt(0, popSize - 1)];

	if (ind1.getFitness() > ind2.getFitness())
	{
		return ind1;
	}
	return ind2;
}



void GeneticAlgorithm::makeMutation()
{
	for (int i = 0; i < popSize; i++)
	{
		population[i].mutate(mutProb);
	}
}


void GeneticAlgorithm::bestSolution()
{

	for (int i = 0; i < popSize; i++)
	{
		if (population[i].getFitness() > bestSol.getFitness())
		{
			bestSol = population[i];
		}
	}

}

Individual& GeneticAlgorithm::getBestSolution()
{
	return bestSol;
}

void GeneticAlgorithm::run(int counter, KnapsackProblem& knapsackProblem)
{
	if (counter < 0)
	{
		throw invalid_argument("Negative counter\n");
	}

	generatePopulation(knapsackProblem);

	while (counter > 0)
	{
		rateSolutions(knapsackProblem);
		makeCross(knapsackProblem);
		makeMutation();
		bestSolution();
		counter--;
	}
}

