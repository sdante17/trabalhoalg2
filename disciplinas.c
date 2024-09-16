#include <stdio.h>
#include <string.h>

#define MAX_PREREQUISITOS 10
#define MAX_DISCIPLINAS 50
#define MAX_SEMESTRES 10

void escreveTopo(){
    printf("_____________________________________________________________________________________________________________________________________________\n                                                               Bem-vindo ao Vasco!\n_____________________________________________________________________________________________________________________________________________\n");
    
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

    FILE *file;

    file = fopen("disciplinas.bin", "rb");
    //contando a quantidade de registros no arquivo
    fseek(file, 0, SEEK_END); //mover o ponteiro para o final

    long tamanhoArquivo = ftell(file); //declara o tamanho total do arquivo em questão

    rewind(file); //rebobinar, mandar ponteiro para o ínicio novamente

    int quantidadeRegistros = tamanhoArquivo / sizeof(Disciplina); //calculando a quatidade de registros

    Disciplina disciplinas[quantidadeRegistros]; //array para armazenar os dados

    //fazendo a leitura dos dados
    fread(disciplinas, sizeof(Disciplina), quantidadeRegistros, file); //onde armazenar, tamanho da informação, tamanho da nossa leitura do arquivo, fonte

    fclose(file);

    //varrer o vetor
    for(int i = 0; i < quantidadeRegistros; i++){
        printf("", ); //printando os dados armazenados no array "disciplinas"
    }

    return 0;
}

void lmatriz(){
    FILE *file;

    file = fopen("disciplinas.bin", "r");

    Disciplina disciplinas[MAX_DISCIPLINAS];

    fread(disciplinas, sizeof(Disciplina), MAX_DISCIPLINAS, file);

    for(int i = 0; i < MAX_DISCIPLINAS; i++){
        printf(">>%d\n\n", disciplinas[i].numPrerequisitos);
        
    }

    fclose(file);

}
