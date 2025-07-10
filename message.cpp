#include "message.h"


std::ostream &operator<<(std::ostream &out, const Message &obj)
{
    out << obj.makeString();
    return out;
}
