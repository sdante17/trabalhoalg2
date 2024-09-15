#include <stdio.h>
#include <string.h>

#define MAX_PREREQUISITOS 16
#define MAX_DISCIPLINAS 32

void escreveTopo(){
    printf("_____________________________________________________________________________________________________________________________________________\n                                                               Bem-vindo ao Vasco!\n_____________________________________________________________________________________________________________________________________________");
    
}


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

void lmatriz();

int main(){

    escreveTopo();

    lmatriz();

    return 0;
}

void lmatriz(){
    FILE *file;

    file = fopen("disciplinas.zip", "r");

    Disciplina disciplinas[MAX_DISCIPLINAS];

    fread(disciplinas, sizeof(Disciplina), MAX_DISCIPLINAS, file);

    for(int i = 0; i < MAX_DISCIPLINAS; i++){
        printf(">>%d\n\n", disciplinas[i].numPrerequisitos);
        
    }

    fclose(file);

}
