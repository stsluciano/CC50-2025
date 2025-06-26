#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Maximo número de candidatos
#define MAX 9

// Candidatos possuem nome e os votos contam
typedef struct
{
    string name;
    int votes;
} candidate;

// Variedade de candidatos
candidate candidates[MAX];

// Numero de candidatos
int candidate_count;

// Prototipo da função
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Checar por usos inválidos
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    //Preencher matriz de candidatos
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop sobre todos os eleitores
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Checando por votos inválidos
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Mostrar o vencedor da eleição
    print_winner();
}

// Update total de votos quando novo voto é dado
bool vote(string name)
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(candidates[i].name, name) == 0)
        {
            candidates[i].votes++;
            return true;
        }
    }
    return false;
}
{
    // TODO
    return false;
}

// Imprimir vencedor(es) da eleição
void print_winner(void)
{
    int max_votes = 0;

    // Ache o máximo número de votos
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes > max_votes)
        {
            max_votes = candidates[i].votes;
        }
    }

    // Imprima todos os candidatos com o máximo de votos
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == max_votes)
        {
            printf("%s\n", candidates[i].name);
        }
    }
}
{
    // TODO
    return;
}

