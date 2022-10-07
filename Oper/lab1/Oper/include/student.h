#pragma once
#include <iostream>

using namespace std;


class student
{
public:
    int age;
    string name;
    int iq;
    student(int a, string n, int i): age(a), name(n), iq(i){}


};
ostream& operator<<(ostream& out2, student stud);
