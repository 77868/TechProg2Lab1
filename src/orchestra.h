#pragma once
class orchestra
{
private:
	char ownnerName[64],name[64];
	double price;

public:
	void save(std::ofstream outf);
	void load(std::ifstream inf);
};
