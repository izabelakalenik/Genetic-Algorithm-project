#pragma once
#include <vector>
#include "Individual.h"

using namespace std;

class GeneticAlgorithm
{
private:
	vector<Individual> population;
	Individual bestSol;

	int popSize;
	double mutProb;
	double crossProb;

public:

	GeneticAlgorithm(int popSize, double mutProb, double crossProb, KnapsackProblem& knapsackProblem, int counter);
	~GeneticAlgorithm();

	void generatePopulation(KnapsackProblem& knapsackProblem);

	vector<double> rateSolutions(KnapsackProblem& knapsackProblem);

	void makeCross(KnapsackProblem& knapsackProblem);
	Individual doCross();
	void makeMutation();

	void bestSolution();
	Individual& getBestSolution();

	void run(int counter, KnapsackProblem& knapsackProblem);
};

