#pragma once

class Item
{
private:
	double size;
	double value;

public:
	Item();
	Item(double value, double size);
	~Item();

	double getValue();
	double getSize();


};
