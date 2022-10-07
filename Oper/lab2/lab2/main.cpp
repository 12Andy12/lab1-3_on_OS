#include <iostream>
#include <sys/sysinfo.h>

using namespace std;

int main()
{
    struct sysinfo info;
    cout <<"\ntotalram: " << info.totalram
    << "\nfreeram: " << info.freeram
    << "\ntotalswap: "<< info.totalswap
    << "\nfreeswap: " << info.freeswap;
    //cout << "Hello world!" << endl;
    return 0;
}
