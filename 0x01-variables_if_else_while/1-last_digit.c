#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * main - Entry point of the program
 *
 * Return: 0 on success
 */
int main(void)
{
    int n;

    srand(time(0));
    n = rand();

    printf("Last digit of %d is ", n);

    n %= 10;

    printf("%d and is ", n);

    if (n > 5)
    {
        printf("greater than 5\n");
    }
    else if (n == 0)
    {
        printf("0\n");
    }
    else
    {
        printf("less than 6 and not 0\n");
    }

    return 0;
}
