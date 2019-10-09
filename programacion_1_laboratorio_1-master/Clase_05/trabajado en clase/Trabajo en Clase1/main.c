#include <stdio.h>
#include <stdlib.h>

int factorial( int x );

int main()
{
    // long long f;

    // f = factorial(10);

    printf("%lli", factorial(20));
    return 0;
}

int factorial( int x )
{
    int fact = 1;

   /* while (x > 1)
    {
        fact = fact * x;    Funcion NO recursiva
        x--;
    }
    */
    while (x > 1)
    {
        fact = fact * factorial( x - 1); // Funcion Recursiva (STACK)
    }

    return fact;
}
