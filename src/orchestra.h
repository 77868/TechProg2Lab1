#pragma once
#include <fstream>
enum
{
	DRUMS,
	STRINGED,
	WIND
};
class orchestra
{
private:
public:
	virtual void print(std::ostream &out)=0;
	virtual char *getName() = 0;
	virtual void save(std::ofstream &outf) = 0;
	virtual void edit() = 0;
	virtual void getInfo() = 0;
	friend std::ostream &operator<<(std::ostream &output, orchestra &object);
	orchestra(){};
	~orchestra(){};
};
