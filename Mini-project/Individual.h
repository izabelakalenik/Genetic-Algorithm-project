#pragma once
#include <vector>
#include "KnapsackProblem.h"


using namespace std;

class Individual
{
private:
	vector<int> genotype;
	double fitness;

public:
	Individual();
	Individual(KnapsackProblem& knapsackProblem);
	~Individual();

	vector<int>& getGenotype();
	double getFitness();
	void showGenotype();

	void generateGenotype(KnapsackProblem& knapsackProblem);
	double calculateFitness(KnapsackProblem& knapsackProblem);
	void mutate(double mutProb);

	vector <Individual> cross(double crossProb, KnapsackProblem& knapsackProblem, Individual& individual);

};
