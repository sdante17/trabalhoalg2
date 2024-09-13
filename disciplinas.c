#include <stdio.h>

// Definição do enum para o tipo de disciplina
typedef enum {
    Obrigatoria,
    Optativa
} TipoDisciplina;

// Definição da struct para uma disciplina
typedef struct {
    char codigo[10];                 // Código alfanumérico da disciplina
    char titulo[100];                // Título da disciplina
    int cargaHoraria;                // Carga horária da disciplina
    int semestre;                    // Semestre em que a disciplina é oferecida
    char prerequisitos[MAX_PREREQUISITOS][10];  // Lista de códigos das disciplinas pré-requisito
    int numPrerequisitos;            // Quantidade de pré-requisitos
    TipoDisciplina tipo;             // Tipo da disciplina (Optativa ou Obrigatória)
} Disciplina;

// Definição da struct para a matriz curricular
typedef struct {
    Disciplina disciplinas[MAX_DISCIPLINAS];
    int numSemestres;                  // Número de semestres
} MatrizCurricular;

int main(){

    FILE *file;
    char l[256]; // Buffer para armazenar cada linha do arquivo

    // Abrindo o arquivo em modo leitura
    file = fopen("matriz_curricular.txt", "r");
    
    // Verifica se o arquivo foi aberto corretamente
    if (file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    return 0;
}
