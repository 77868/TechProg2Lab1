#pragma once
#include "orchestra.h"
#include "fstream"
class keeper
{
private:
	orchestra** list;
	unsigned int capacity, listLenght;
	void resize();
	void addItem();
	void removeItem(unsigned int index);
public:
	keeper();
};
