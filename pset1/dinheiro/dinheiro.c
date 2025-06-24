#include <cs50.h>
#include <math.h>
#include <stdio.h>


int main(void)
{
    float reais;

    // Solicitar ao usuário um valor positivo
    do
    {
        reais = get_float("Changed owed: ");
    }

    while (reais < 0);

    // Converter dólares para centavos, arredondando para evitar erros de floating
    int centavos = round(reais * 100);
    int coins = 0;

    // Calculando divisão por 25
    coins += centavos / 25;
    centavos = centavos % 25;

    // Calculando divisão por 10
    coins += centavos / 10;
    centavos = centavos % 10;

    // Calculando divisão por 5
    coins += centavos / 5;
    centavos = centavos % 5;

    // Sobra em centavos 0,01
    coins +=centavos;

    printf("%i\n", coins);
}
