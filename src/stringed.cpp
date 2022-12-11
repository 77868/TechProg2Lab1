#include "stringed.h"
#include "stringed.h"
#include "input.h"
unsigned int stringed::cnt=0;
stringed::stringed()
{
    getValue(name, 64, "Введите название инстурмента: ");
    getValue(ownerName, 64, "Введите имя владельца: ");
    getValue(manufacturer, 64, "Введите название фирмы призводителя: ");
    getValue(price, "Введите цену инстремента: ");
    getValue(info, 128, "Опишите инструмент: ");
    cnt++;
}
stringed::stringed(std::ifstream &inputFile)
{
    inputFile.getline(ownerName, 64, '\n');
    inputFile.getline(name, 64, '\n');
    inputFile >> price;
    inputFile.ignore(1);
    inputFile.getline(info, 128, '\n');
    inputFile.getline(manufacturer, 64, '\n');
    cnt++;
}
stringed::~stringed()
{
    cnt--;
}
void stringed::save(std::ofstream &outputFile)
{
    outputFile << STRINGED << std::endl
               << ownerName << std::endl
               << name << std::endl
               << price << std::endl
               << info << std::endl
               << manufacturer << std::endl;
}
void stringed::getInfo()
{
    std::cout << "Тип: Струнное" << std::endl
              << "Название: " << name << std::endl
              << "Владелец: " << ownerName << std::endl
              << "Производитель: " << manufacturer << std::endl
              << "Цена: " << price << std::endl
              << "Сведения об инструменте: " << info << std::endl;
}
void stringed::print(std::ostream &output)
{
    output << "Струнное: " << name;
}
char *stringed::getName()
{
    return name;
}
void stringed::edit()
{
    system("clear");
    char choice = '0';
    std::cout << "Выберите редактируемое поле:" << std::endl
              << "1 - название" << std::endl
              << "2 - имя владельца" << std::endl
              << "3 - название фирмы производителя" << std::endl
              << "4 - цена" << std::endl
              << "5 - информация об инструменте" << std::endl;
    std::cin >> choice;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    switch (choice)
    {
    case '1':
        getValue(name, 64, "Введите новое название инстурмента: ");
        break;
    case '2':
        getValue(ownerName, 64, "Введите новое имя владельца: ");
        break;
    case '3':
        getValue(manufacturer, 64, "Введите новое название фирмы призводителя: ");
        break;
    case '4':
        getValue(price, "Введите новую цену инстремента: ");
        break;
    case '5':
        getValue(info, 128, "Введите новое описание инструмента: ");
        break;
    default:
        std::cout << "Введенно некоректное значение: " << std::endl;
    }
}