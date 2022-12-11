#include "keeper.h"
#include "orchestra.h"
#include "drums.h"
#include "stringed.h"
#include "wind.h"
#include "string.h"

void keeper::resize()
{
	capacity = 2 * capacity;
	orchestra **tmp = new orchestra *[capacity];
	for (size_t i = 0; i < listLenght; i++)
	{
		tmp[i] = list[i];
	}
	delete[] list;
	list = tmp;
}

void keeper::show()
{
	for (size_t i = 0; i < listLenght; i++)
	{
		std::cout <<i<<") "<< *list[i]<<std::endl;
	}
}

void keeper::tryEditItem()
{
	try
	{
		list[choiseItem()]->edit();
	}
	catch (const char *msg)
	{
		std::cerr << msg << std::endl;
	}
}

void keeper::tryGetItemInfo()
{
		try
	{
		list[choiseItem()]->getInfo();
	}
	catch (const char *msg)
	{
		std::cerr << msg << std::endl;
	}

}

void keeper::sort()
{
	for (size_t i = 0; i < listLenght-1; i++)
	{
		for (size_t j = i + 1; j < listLenght; j++)
		{
			if (strcmp(list[i]->getName(),list[j]->getName())>0)
			{
				auto tmp =list[i];
				list[i]=list[j];
				list[j]=tmp;
			}
		}
	}
	
}

int keeper::choiseItem()
{
	if (listLenght == 0)
		throw "Список пуст";
	show();
	int choice = -1;
	std::cout <<std::endl<< "Введите индекс выбранного объекта: ";
	std::cin >> choice;
	if(!std::cin.good()){
	std::cin.clear();
	}
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	if (choice < 0 || choice >= listLenght)
		throw("Введенно некоректное значение");
	return choice;
}
int keeper::choiseType()
{
	int choice = -1;
	std::cout << "Выберите тип объекта: " << std::endl
			  << "0 - ударные" << std::endl
			  << "1 - струнные" << std::endl
			  << "2 - духовые" << std::endl;
	std::cin >> choice;
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	if (choice < 0 || choice > 2)
		throw("Введенно некоректное значение");
	return choice;
}
void keeper::tryAddItem()
{
	try
	{
		orchestra *item = nullptr;
		switch (choiseType())
		{
		case DRUMS:
			item = new drums;
			break;
		case STRINGED:
			item = new stringed;
			break;
		case WIND:
			item = new wind;
			break;
		}
		addItem(item);
	}
	catch (const char *msg)
	{
		std::cerr << msg << std::endl;
	}
}
void keeper::addItem(orchestra *item)
{
	if (capacity == listLenght)
		resize();
	list[listLenght++] = item;
}

void keeper::tryRemoveItem()
{
	try
	{
		int itemId = choiseItem();
		removeItem(itemId);
	}
	catch (const char *msg)
	{
		std::cerr << msg << std::endl;
	}
}
void keeper::removeItem(int itemId)
{
	delete list[itemId];
	for (size_t i = itemId; i < listLenght - 1; i++)
	{
		list[i] = list[i + 1];
	}
	list[--listLenght] = nullptr;
}

void keeper::trySave()
{
	char outputFileName[100] = "";
	std::cout << "Введите имя файла в который нужно сохранить данные :";
	std::cin >> outputFileName;
	try
	{
		save(outputFileName);
	}
	catch (char const *msg)
	{
		std::cerr << msg << '\n';
	}
}
void keeper::save(char *outputFileName)
{
	std::ofstream outf(outputFileName);

	if (!outf.is_open())
		throw "Не удалось открыть файл";

	outf << listLenght << std::endl;

	for (size_t i = 0; i < listLenght; i++)
	{
		list[i]->save(outf);
	}
	outf.close();
}

void keeper::tryLoad()
{
	char inputFileName[100] = "";
	std::cout << "Введите имя файла из которого нужно загрузить данные :";
	std::cin >> inputFileName;
	try
	{
		load(inputFileName);
	}
	catch (char const *msg)
	{
		std::cerr << msg << '\n';
	}
}
void keeper::load(char *inputFileName)
{
	std::ifstream inputFile(inputFileName);

	if (!inputFile.is_open())
		throw "Не удалось открыть файл";
	clear();

	int objektCount = 0;
	inputFile >> objektCount;
	if (objektCount > capacity)
	{
		delete[] list;
		list = new orchestra *[objektCount];
		capacity=objektCount;
	}
	int typeOfObjekt = -1;
	for (size_t i = 0; i < objektCount; i++)
	{
		inputFile >> typeOfObjekt;
		inputFile.ignore(1);
		switch (typeOfObjekt)
		{
		case DRUMS:
			list[i] = new drums(inputFile);
			break;
		case STRINGED:
			list[i] = new stringed(inputFile);
			break;
		case WIND:
			list[i] = new wind(inputFile);
			break;
		default:
			break;
		}
	}
	listLenght=objektCount;
	inputFile.close();
}

void keeper::clear()
{
	for (size_t i = 0; i < listLenght; i++)
	{
		delete list[i];
		list[i] = nullptr;
	}
	listLenght = 0;
}

keeper::keeper() : capacity(1), listLenght(0)
{
	list = new orchestra *[1];
}
keeper::keeper(char *inputFileName)
{
	std::ifstream inputFile(inputFileName);
	if (!inputFile.is_open())
		throw "Не удалось открыть файл";
	inputFile >> listLenght;
	if(listLenght<1)
	{
		capacity = 1;
		listLenght=0;
		list = new orchestra *[capacity];
		return;
	}
	capacity = listLenght;
	list = new orchestra *[capacity];
	int typeOfObjekt = 0;
	for (size_t i = 0; i < listLenght; i++)
	{
		inputFile >> typeOfObjekt;
		inputFile.ignore(1);
		switch (typeOfObjekt)
		{
		case DRUMS:
			list[i] = new drums(inputFile);
			break;
		case STRINGED:
			list[i] = new stringed(inputFile);
			break;
		case WIND:
			list[i] = new wind(inputFile);
			break;
		default:
			break;
		}
	}
	inputFile.close();
}