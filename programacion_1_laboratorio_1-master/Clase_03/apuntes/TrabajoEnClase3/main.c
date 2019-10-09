#include <stdio.h>
#include <stdlib.h>

float calcularSupCirculo(float radio);

int main()
{
    float radio;
    float superficie;

    printf("Ingrese el valor del radio: ");
    scanf("%f", &radio);

    superficie = calcularSupCirculo(radio);

    printf("\nLa superficie del Circulo es: %.2f\n\n", superficie);

    return 0;
}

float calcularSupCirculo( float radio)
{
    float resultado;
    resultado = radio * radio * 3.14;

    return resultado;
}
