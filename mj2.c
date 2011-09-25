#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct _List
{
    unsigned int * value;
    struct _List * next;
};

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
    List * table = (List *) malloc (5 * sizeof(List));
    
    int i = 0;
    for (; i < 35; ++i)
    {
	table[i].value = &base[i];
	table[i].next = &table[i - 1];
    }

    srand(time(NULL));

    int times = 0;
    i = 0;
    /*
     * Pick up one number and remove it, then
     * move the last one to the hole, and set
     * the new-last-one next pointer to NULL..
     */
    while (35 > i)
    {
	++times;
	unsigned int loc = rand() % 36 - i;
	printf("loc: %d, ", loc);
	printf("%d, ", *table[loc].value);
	printf("\n");
	table[i - 1].next = &table[i + 1];
	*table[i].value = 0;
	table[i].next = NULL;
	++i;
    }

    printf("times: %d\n", times);

    return EXIT_SUCCESS;
}

