#pragma once
#include <string>
#include <vector>
#include "Item.h"

using namespace std;

class KnapsackProblem
{
private:
	double knapsackCapacity;
	int numberOfItems;
	vector<Item> listOfItems;


public:
	KnapsackProblem(const string& path);
	~KnapsackProblem();

	int getNumberOfItems();
	double getKnapsackCapacity();

	void showListOfItems();
	void showListOfFinalItems(vector<int>& genotype);

	bool fromFile(const string& path);
	void addItem(Item& item);

	vector<double> evaluateSolution(vector<int>& genotype);
};
