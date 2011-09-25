#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main (int argc, char* argv[])
{
    unsigned int orig[] = 
	{1, 2, 3, 4, 5, 6,
	 7, 8, 9, 10, 11, 12,
	 13, 14, 15, 16, 17, 18,
	 19, 20, 21, 22, 23, 24,
	 25, 26, 27, 28, 29, 30,
	 31, 32, 33, 34, 35, 36};

    srand(time(NULL));

    int j = 0;
    int i = 0;
    while (35 != i)
    {
	++j;
	unsigned int loc = rand() % 35 + 1;
	if (orig[loc])
	{
	    // rand number found.
	    printf("%d, ", orig[loc]);
	    orig[loc] = 0;
	    ++i;
	}
    }
    printf("j: %d\n", j);

    return EXIT_SUCCESS;
}

