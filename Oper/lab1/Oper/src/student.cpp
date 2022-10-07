#include "student.h"
#include <stdio.h>

ostream& operator<<(ostream& out2, student stud)
{
    out2 << "age="<< stud.age << ";name=" << stud.name << ";iq=" << stud.iq << ";\n";
    return out2;
}
