#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(int argc, string argv[])
{
    // Checando pelo argumento de exatamente um comando-linha
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Checando se o argumento pe composto totalmente por números
    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    // Convertendo o argumento para integer
    int key = atoi(argv[1]);

    // Prompt para plaintext
    string plaintext = get_string("plaintext: ");

    printf("ciphertext: ");

    // Repetir sobre cada caractere
    for (int i = 0; i < strlen(plaintext); i++)
    {
        char c = plaintext[i];

        // Letras Maiúsculas
        if (isupper(c))
        {
            printf("%c", (c - 'A' + key) % 26 + 'A');
        }
        // Letras Minúsculas
        else if (islower(c))
        {
            printf("%c", (c - 'a' + key) % 26 + 'a');
        }
        // Caracteres não alfabéticos continuam os mesmos
        else
        {
            printf("%c", c);
        }
    }

    printf("\n");
    return 0;
}
