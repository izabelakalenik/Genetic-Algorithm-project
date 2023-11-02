#include "RandomGenerator.h"
#include <random>

using namespace std;

int RandomGenerator::generateInt(int min, int max)
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(min, max);

    return distrib(gen);
}

double RandomGenerator::generateDouble(double min, double max)
{
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> distrib(min, max);

    return distrib(gen);
}
