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

void lerProfessores(const char* filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo de professores.\n");
        return;
    }

    while (fscanf(file, "%s %s", professores[contadorProfessores].nome, professores[contadorProfessores].departamento) != EOF) {
        contadorProfessores++;
    }
    
    fclose(file);
}

void verificarAlunos() {
    for (int i = 0; i < contadorAlunos; i++) {
        int departamentoValido = 0;
        for (int j = 0; j < contadorProfessores; j++) {
            if (strcmp(alunos[i].departamento, professores[j].departamento) == 0) {
                departamentoValido = 1;
                break;
            }
        }
        if (!departamentoValido) {
            printf("Aluno %s está em um departamento inválido: %s\n", alunos[i].nome, alunos[i].departamento);
        }
    }
}

int main() {
    lerProfessores("professor.txt");
    lerAlunos("aluno.txt");
    verificarAlunos();
    
    return 0;
}