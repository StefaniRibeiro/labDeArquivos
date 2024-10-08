#include <stdio.h>
#include <stdlib.h>

#define MAX_NOME 100
#define MAX_DEPARTAMENTO 50
#define MAX_ALUNOS 100
#define MAX_PROFESSORES 50


typedef struct {
    char nome[MAX_NOME];
    char departamento[MAX_NOME];
} Professor;

Professor professores[MAX_PROFESSORES];
int contadorProfessores = 0;

typedef struct {
    char nome[MAX_NOME];
    char departamento[MAX_DEPARTAMENTO];
} Aluno;

Aluno alunos[MAX_ALUNOS];
int contadorAlunos = 0;