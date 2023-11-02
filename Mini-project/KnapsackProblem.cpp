#include "KnapsackProblem.h"
#include <fstream>
#include <iostream>
#include <stdexcept>

using namespace std;

KnapsackProblem::KnapsackProblem(const string& path)
{
	fromFile(path);
}

KnapsackProblem::~KnapsackProblem()
= default;

int KnapsackProblem::getNumberOfItems()
{
	return numberOfItems;
}

double KnapsackProblem::getKnapsackCapacity()
{
	return knapsackCapacity;
}


void KnapsackProblem::showListOfItems()
{
	cout << "List of items: \n";

	for (int i = 0; i < numberOfItems; i++)
	{
		cout << "[" << i + 1 << "] size: " << listOfItems[i].getSize() << ", value: " << listOfItems[i].getValue() << endl;
	}
}

void KnapsackProblem::showListOfFinalItems(vector<int>& genotype)
{
	int counter = 1;

	for (int i = 0; i < genotype.size(); i++)
	{
		if (genotype[i] == 1)
		{
			cout << "[" << counter << "]" << " size: " << listOfItems[i].getSize() << ", value: " << listOfItems[i].getValue() << endl;
			counter++;
		}
	}
}


bool KnapsackProblem::fromFile(const string& path)
{
	ifstream file(path);

	if (!file.is_open())
	{
		cout << "File does not exist";
		return false;
	}


	double capacity;
	file >> capacity;

	if (capacity <= 0)
	{
		throw invalid_argument("Negative knapsack capacity\n");
	}

	knapsackCapacity = capacity;
	double value;
	double size;

	while (file >> value >> size)
	{
		try
		{
			Item item(value, size);
			addItem(item);

		}
		catch (invalid_argument& e)
		{
			cout << "Invalid argument: " << e.what();
		}

	}

	numberOfItems = listOfItems.size();

	return true;
}

void KnapsackProblem::addItem(Item& item)
{
	listOfItems.push_back(item);
}

vector<double> KnapsackProblem::evaluateSolution(vector<int>& genotype)
{
	double sizeAll = 0;
	double valueAll = 0;
	const int genotypeSize = genotype.size();
	vector<double> solution;

	for (int i = 0; i < genotypeSize; i++)
	{
		if (genotype[i] == 1)
		{
			sizeAll += listOfItems[i].getSize();
			valueAll += listOfItems[i].getValue();
		}
	}

	if (sizeAll <= knapsackCapacity)
	{
		solution.push_back(sizeAll);
		solution.push_back(valueAll);
	}

	return solution;
}

