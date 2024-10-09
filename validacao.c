#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_ELEITORES 100
#define MAX_CPF 12
#define MAX_VOTO 20

typedef struct {
    char cpf[MAX_CPF];  // CPF no formato "XXXXXXXXXXX"
    bool jaVotou;
    char voto[MAX_VOTO]; // Armazenar o TC votado
} Eleitor;

Eleitor eleitores[MAX_ELEITORES];
int contadorEleitores = 0;

// Função para validar CPF
bool validarCPF(const char* cpf) {
    int soma = 0, digito1, digito2;

    // Validação simples: verificar se tem 11 caracteres (sem formatação)
    if (strlen(cpf) != 11) {
        return false;
    }

    // Cálculo do primeiro dígito verificador
    for (int i = 0; i < 9; i++) {
        soma += (cpf[i] - '0') * (10 - i);
    }
    digito1 = (soma * 10) % 11;
    if (digito1 == 10) digito1 = 0;

    // Cálculo do segundo dígito verificador
    soma = 0;
    for (int i = 0; i < 10; i++) {
        soma += (cpf[i] - '0') * (11 - i);
    }
    digito2 = (soma * 10) % 11;
    if (digito2 == 10) digito2 = 0;

    return (digito1 == (cpf[9] - '0')) && (digito2 == (cpf[10] - '0'));
}

// Função para registrar voto
bool registrarVoto(const char* cpf, const char* voto) {
    for (int i = 0; i < contadorEleitores; i++) {
        if (strcmp(eleitores[i].cpf, cpf) == 0) {
            if (eleitores[i].jaVotou) {
                printf("Eleitor com CPF %s já votou.\n", cpf);
                return false; // Eleitor já votou
            }
            // Registro do voto
            strncpy(eleitores[i].voto, voto, MAX_VOTO - 1);
            eleitores[i].voto[MAX_VOTO - 1] = '\0'; // Garantir null-termination
            eleitores[i].jaVotou = true;
            printf("Voto registrado para CPF %s: %s\n", cpf, voto);
            return true;
        }
    }
    printf("Eleitor com CPF %s não encontrado.\n", cpf);
    return false; // Eleitor não encontrado
}

// Função para adicionar eleitor
void adicionarEleitor(const char* cpf) {
    if (contadorEleitores < MAX_ELEITORES) {
        strncpy(eleitores[contadorEleitores].cpf, cpf, MAX_CPF - 1);
        eleitores[contadorEleitores].cpf[MAX_CPF - 1] = '\0'; // Garantir null-termination
        eleitores[contadorEleitores].jaVotou = false;
        contadorEleitores++;
    } else {
        printf("Limite de eleitores alcançado.\n");
    }
}

int main() {
    char cpf[MAX_CPF];
    char voto[MAX_VOTO];

    // Adicionando alguns eleitores
    adicionarEleitor("12345678909"); // CPF válido
    adicionarEleitor("98765432100"); // CPF válido

    // Validação e votação
    printf("Digite o CPF do eleitor: ");
    scanf("%11s", cpf); // Limitar a leitura a 11 caracteres

    if (validarCPF(cpf)) {
        printf("CPF válido.\n");
        printf("Digite o TC votado: ");
        scanf("%19s", voto); // Limitar a leitura a 19 caracteres
        
        registrarVoto(cpf, voto);
    } else {
        printf("CPF inválido.\n");
    }

    return 0;
}
