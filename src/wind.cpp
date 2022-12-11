#include "wind.h"
#include "input.h"
unsigned int wind::cnt = 0;
wind::wind()
{
    getValue(name, 64, "Введите название инстурмента: ");
    getValue(ownerName, 64, "Введите имя владельца: ");
    getValue(manufacturer, 64, "Введите название фирмы призводителя: ");
    getValue(price, "Введите цену инстремента: ");
    getValue(defectInfo, 128, "Опишите присутствующие дефекты: ");
    cnt++;
}
wind::wind(std::ifstream &inputFile)
{
    inputFile.getline(ownerName, 64, '\n');
    inputFile.getline(name, 64, '\n');
    inputFile >> price;
    inputFile.ignore(1);
    inputFile.getline(defectInfo, 128, '\n');
    inputFile.getline(manufacturer, 64, '\n');
    cnt++;
}
wind::~wind()
{
    cnt--;
}
void wind::save(std::ofstream &outputFile)
{
    outputFile << WIND << std::endl
               << ownerName << std::endl
               << name << std::endl
               << price << std::endl
               << defectInfo << std::endl
               << manufacturer << std::endl;
}
void wind::getInfo()
{
    std::cout << "Тип: Духовое" << std::endl
              << "Название: " << name << std::endl
              << "Владелец: " << ownerName << std::endl
              << "Производитель: " << manufacturer << std::endl
              << "Цена: " << price << std::endl
              << "Сведения о дефектах: " << defectInfo << std::endl;
}
void wind::print(std::ostream &output)
{
    output << "Духовое: " << name;
}
char *wind::getName()
{
    return name;
}
void wind::edit()
{
    system("clear");
    char choice = '0';
    std::cout << "Выберите редактируемое поле:" << std::endl
              << "1 - название" << std::endl
              << "2 - имя владельца" << std::endl
              << "3 - название фирмы производителя" << std::endl
              << "4 - цена" << std::endl
              << "5 - дефекты" << std::endl;
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
        getValue(defectInfo, 128, "Введите новое описание дефектов: ");
        break;
    default:
        std::cout << "Введенно некоректное значение" << std::endl;
    }
}