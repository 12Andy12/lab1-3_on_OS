#include <iostream>
#include "list.h"
#include "student.h"
#include <string>
#include <vector>

using namespace std;
vector<string> allNames = {"Ivan","Andy", "Alex"};

int main()
{
    srand(time(0));
    list<student> myClassmates;
    myClassmates.fileRead("itIsFile.txt");
    cout<<myClassmates;
    list<student> myNewClassmates;
    for(int i=0;i<10;++i)
        myNewClassmates.push_back(student(rand()%80+20, allNames[rand()%3], rand()%200));

    myNewClassmates.fileWrite("itIsFile.txt");
}
