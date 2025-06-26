#include <cs50.h>
#include <stdio.h>

// Maximo eleitores e candidatos
#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

// Preferencias[i][j] is jth preference for voter i
int preferences[MAX_VOTERS][MAX_CANDIDATES];

// Candidatos possuem nome, voto conta, elimina status
typedef struct
{
    string name;
    int votes;
    bool eliminated;
} candidate;

// Grupo de candidatos
candidate candidates[MAX_CANDIDATES];

// Numeros de eleitores e candidatos
int voter_count;
int candidate_count;

// Function prototypes
bool vote(int voter, int rank, string name);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);

int main(int argc, string argv[])
{
    // Checar por uso invalido
    if (argc < 2)
    {
        printf("Usage: runoff [candidate ...]\n");
        return 1;
    }

    // Preencher matriz de candidatos
    candidate_count = argc - 1;
    if (candidate_count > MAX_CANDIDATES)
    {
        printf("Maximum number of candidates is %i\n", MAX_CANDIDATES);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }

    voter_count = get_int("Number of voters: ");
    if (voter_count > MAX_VOTERS)
    {
        printf("Maximum number of voters is %i\n", MAX_VOTERS);
        return 3;
    }

    // Continuar consultando por votos
    for (int i = 0; i < voter_count; i++)
    {

        // Consulta para cada classificação
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            // Registrar o voto, a menos que seja inválido
            if (!vote(i, j, name))
            {
                printf("Invalid vote.\n");
                return 4;
            }
        }

        printf("\n");
    }

    // Continue realizando o segundo turno até que haja um vencedor
    while (true)
    {
        // Calcular os votos dados aos candidatos restantes
        tabulate();

        // Verifique se a eleição foi ganha
        bool won = print_winner();
        if (won)
        {
            break;
        }

        // Elimine os candidatos em último lugar
        int min = find_min();
        bool tie = is_tie(min);

        // Se houver empate, todos ganham
        if (tie)
        {
            for (int i = 0; i < candidate_count; i++)
            {
                if (!candidates[i].eliminated)
                {
                    printf("%s\n", candidates[i].name);
                }
            }
            break;
        }

        // Elimine qualquer um com o número mínimo de votos
        eliminate(min);

        // Redefinir a contagem de votos para zero
        for (int i = 0; i < candidate_count; i++)
        {
            candidates[i].votes = 0;
        }
    }
    return 0;
}

// Registre a preferência se o voto for válido
bool vote(int voter, int rank, string name)
{
    // TODO
    return false;
}

// Tabular votos para candidatos não eliminados
void tabulate(void)
{
    // TODO
    return;
}

// Imprima o vencedor da eleição, se houver
bool print_winner(void)
{
    // TODO
    return false;
}

// Retornar o número mínimo de votos que qualquer candidato restante possui
int find_min(void)
{
    // TODO
    return 0;
}

// Retorna verdadeiro se a eleição estiver empatada entre todos os candidatos, falso caso contrário
bool is_tie(int min)
{
    // TODO
    return false;
}

// Eliminar o(s) candidato(s) em último lugar
void eliminate(int min)
{
    // TODO
    return;
}

