#include "header.h"

void oldman()
{
    fprintf(stdout, "I'm a perent %i\n", (int) getpid());
}

void recreation()
{
    fprintf(stdout, "I'm a child %i\n", (int) getpid());
}
