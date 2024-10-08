#include <stdio.h>
#include <stdlib.h>

#define MAX_PROFESSORES 100
#define MAX_NOME 100


typedef struct {
    char nome[MAX_NOME];
    char departamento[MAX_NOME];
} Professor;

Professor professores[MAX_PROFESSORES];
int contadorProfessores = 0;
