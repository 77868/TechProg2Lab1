#pragma once
#include "orchestra.h"
#include "limits"
#include "fstream"
#include "iostream"
class drums : public orchestra
{
private:
    char type[64] = "\0";
    char ownerName[64] = "\0";
    char name[64] = "\0";
    double price;
    static unsigned int cnt;

public:
    drums();
    drums(std::ifstream &inputFile);
    ~drums();
    void save(std::ofstream &outputFile);
    char *getName();
    void edit();
    void getInfo();
    void print(std::ostream& output);
};
