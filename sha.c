#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

int main (int argc, char* argv[])
{
    printf("%s\n", SHA1(argv[1], strlen(argv[1]), NULL));

    return EXIT_SUCCESS;
}

