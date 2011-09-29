#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct _List List;

unsigned int base[] = 
{
    1, 2, 3, 4, 5, 6,
    7, 8, 9, 10, 11, 12,
    13, 14, 15, 16, 17, 18,
    19, 20, 21, 22, 23, 24,
    25, 26, 27, 28, 29, 30,
    31, 32, 33, 34, 35, 36
};

int main (int argc, char* argv[])
{
    unsigned int ** table = (unsigned int**) malloc(sizeof(unsigned int*) * 36);
    int i = 0;
    for (; i < 36; ++i)
    {
	table[i] = &base[i];
    }

    srand(time(NULL));

    i = 0;
    while (35 > i)
    {
	++i;
	unsigned int loc = rand() % (36 - i);
	printf("%d\t(%p)\n", *table[loc], table[loc]);
	table[loc] = table[36 - i];
    }

    return EXIT_SUCCESS;
}

