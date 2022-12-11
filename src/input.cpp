#include "input.h"
void getValue(double &value, const char *promt)
{
    std::cout << promt;
    std::cin >> value;
    while (!std::cin.good())
    {
        std::cout<< "Введены неверные данные. Попробуйте ещё раз: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin >> value;
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
void getValue(char value[], unsigned int maxLength, const char *promt)
{
    std::cout << promt;
    std::cin.getline(value, maxLength, '\n');
}