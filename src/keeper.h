#pragma once
#include "orchestra.h"
#include <fstream>
#include <iostream>
#include <limits>

class keeper
{
private:
	orchestra **list;
	unsigned int capacity, listLenght;
	void resize();
	int choiseItem();
	int choiseType();
	void getItemInfo();
	void editItem();
	void addItem(orchestra *item);
	void removeItem(int itenId);
	void load(char *inputFileName);
	void save(char *outputFileName);
	void clear();

public:
	void show();
	void tryRemoveItem();
	void tryAddItem();
	void tryGetItemInfo();
	void tryEditItem();
	void trySave();
	void tryLoad();
	void sort();

	keeper();
	keeper(char *inputFileName);

	~keeper();
};
