#include <iostream>
#include "keeper.h"
#include "orchestra.h"
#include "drums.h"
#include "stringed.h"
#include "wind.h"
#include <limits>
#include <locale>

int main()
{
  setlocale(LC_ALL, "Ru");
  std::cout << "Загузить данные из файла? Y/N:";
  char choice = 0;
  std::cin >> choice;
  keeper *mainKeeper;
  while (true)
  {
    if (choice == 'Y' || choice == 'y')
    {
      char fileName[100];
      std::cout << "Введите полное имя файла:";
      std::cin >> fileName;
      try
      {
        mainKeeper = new keeper(fileName);
      }
      catch (const char *msg)
      {
        std::cerr << msg << std::endl;
        return -1;
      }
      break;
    }
    else if (choice == 'N' || choice == 'n')
    {
      mainKeeper = new keeper;
      break;
    }
    else
    {
      if (!std::cin.good())
      {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      }
      std::cout << "Введены некоректные данные, попрообуйте ещё раз :";
      std::cin >> choice;
    }
  }

  while (true)
  {
    mainKeeper->show();
    std::cout << std::endl
              << "выберите действие:" << std::endl
              << "1 - добавить объект" << std::endl
              << "2 - удалить объект" << std::endl
              << "3 - вывести подробную информацию" << std::endl
              << "4 - отсортировать объекты по названию" << std::endl
              << "5 - отредактировать информацию об объекте" << std::endl
              << "6 - сохранить список" << std::endl
              << "7 - загрузить список" << std::endl
              << "8 - выйти" << std::endl;
    choice = 0;
    std::cin >> choice;
    if (!std::cin.good())
    {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    switch (choice)
    {
    case '1':
      mainKeeper->tryAddItem();
      break;
    case '2':
      mainKeeper->tryRemoveItem();
      break;
    case '3':
      mainKeeper->tryGetItemInfo();
      break;
    case '4':
      mainKeeper->sort();
      break;
    case '5':
      mainKeeper->tryEditItem();
      break;
    case '6':
      mainKeeper->trySave();
      break;
    case '7':
      mainKeeper->tryLoad();
      break;
    case '8':
      delete mainKeeper;
      return 0;
    }
  }
}
