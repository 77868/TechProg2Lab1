#pragma once
#include "orchestra.h"
#include "limits"
#include "fstream"
#include "iostream"
class wind : public orchestra
{
private:
    char ownerName[64]="\0";
    char name[64]="\0";
    double price;
    static unsigned int cnt;
    char defectInfo[128]="\0";
    char manufacturer[64]="\0";

public:
    wind();
    wind(std::ifstream &inputFile);
    ~wind();
    void save(std::ofstream &outputFile);
    char* getName();
    void edit();
	void getInfo();
	void print(std::ostream& output);
};
