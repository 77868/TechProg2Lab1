#include "orchestra.h"
std::ostream &operator<<(std::ostream &output,orchestra& object)
{
    object.print(output);
    return output;
}