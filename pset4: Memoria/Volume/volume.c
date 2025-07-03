#include <stdint.h>
#include <stdio.h>
#include <cs50.h>

// Número de bytes em .wav
const int HEADER_SIZE = 44;

int main(int argc, char *argv[])
{
    // Checar argumentos da linha-comando
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // Abrir arquivo entrada
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    // Abrir arquivo saída
    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        fclose(input);
        printf("Could not open file.\n");
        return 1;
    }

    // Get fator
    float factor = atof(argv[3]);

    // Copiar header da entrada para saída
    uint8_t header[HEADER_SIZE];
    fread(header, sizeof(uint8_t), HEADER_SIZE, input);
    fwrite(header, sizeof(uint8_t), HEADER_SIZE, output);

    // Ler um sample por vez, escala e escrever na saída
    int16_t buffer;
    while (fread(&buffer, sizeof(int16_t), 1, input))
    {
        buffer *= factor;
        fwrite(&buffer, sizeof(int16_t), 1, output);
    }

    // Fechar arquivos
    fclose(input);
    fclose(output);
}
