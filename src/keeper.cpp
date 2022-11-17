#include "keeper.h"

void keeper::resize()
{
	capacity = 2 * capacity;
	orchestra** tmp = new orchestra * [capacity];
	for (size_t i = 0; i < listLenght; i++)
	{
		tmp[i] = list[i];
	}
	delete[] list;
	list = tmp;
}

void keeper::removeItem(unsigned int index)
{

}

keeper::keeper():capacity(1),listLenght(0)
{
	list = new orchestra * [1];
}
