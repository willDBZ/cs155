#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void hidden()
{
    // Just prints a string on the standard output
    fprintf(stdout, "Hijacked! Hidden functionality!\n");
}

int bar(char *arg, char *out)
{
    strcpy(out, arg); // Copies from arg memory to out memory until arg is 0x00
    return 0;
}

int foo(char *argv[])
{
    char buf[128];     // Allocate buffer in memory that can hold 128 bytes
    bar(argv[1], buf); // Call bar function, where first command line argument is source & memory for copying and buf is target memory for copying
}

int main(int argc, char *argv[])
{
    // Check if we have exactly one command line argument,
    // otherwise print error message and exit program
    if (argc != 2) // Integer argc is number command line parameters, 0 is always reserved for & the name of the executable
    {
        fprintf(stderr, "target0: argc != 2\n");
        exit(EXIT_FAILURE);
    }
    // Call foo function with array of command line parameters as argument
    foo(argv);
    return 0;
}