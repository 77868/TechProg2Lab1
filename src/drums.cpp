#include "drums.h"
#include "input.h"
unsigned int drums::cnt=0;
drums::drums()
{
    getValue(type, 64, "Введите тип инструмента: ");
    getValue(name, 64, "Введите название инстурмента: ");
    getValue(ownerName, 64, "Введите имя владельца: ");
    getValue(price, "Введите цену инстремента: ");
    cnt++;
}
drums::drums(std::ifstream &inputFile)
{
    inputFile.getline(ownerName, 64, '\n');
    inputFile.getline(name, 64, '\n');
    inputFile >> price;
    inputFile.ignore(1);
    inputFile.getline(type, 128, '\n');
    cnt++;
}
drums::~drums()
{
    cnt--;
}
void drums::save(std::ofstream &outputFile)
{
    outputFile << DRUMS << std::endl
               << ownerName << std::endl
               << name << std::endl
               << price << std::endl
               << type << std::endl;
}
void drums::getInfo()
{
    std::cout << "Тип: Ударное" << std::endl
              << "Название: " << name << std::endl
              << "Тип: " << type << std::endl
              << "Владелец: " << ownerName << std::endl
              << "Цена: " << price << std::endl;
}
void drums::print(std::ostream &output)
{
    output << "Ударное: " << name;
}
char *drums::getName()
{
    return name;
}
void drums::edit()
{
    system("clear");
    char choice = '0';
    std::cout << "Выберите редактируемое поле:" << std::endl
              << "1 - название" << std::endl
              << "2 - имя владельца" << std::endl
              << "3 - тип" << std::endl
              << "4 - цена" << std::endl;
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
        getValue(type, 64, "Введите тип инструмента: ");
        break;
    case '4':
        getValue(price, "Введите новую цену инстремента: ");
        break;
    default:
        std::cout << "Введенно некоректное значение: " << std::endl;
    }
}