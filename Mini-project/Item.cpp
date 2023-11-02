#include "Item.h"
#include <iostream>

using namespace std;

Item::Item()
= default;

Item::Item(double valuee, double sizee)
{
	if (valuee < 0)
	{
		throw invalid_argument("Negative item value\n");
	}
	if (sizee <= 0)
	{
		throw invalid_argument("Negative item size\n");
	}

	value = valuee;
	size = sizee;
}

Item::~Item()
= default;

double Item::getValue()
{
	return value;
}

double Item::getSize()
{
	return size;
}

