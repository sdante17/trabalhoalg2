#include <stdio.h>
#include <string.h>
#include <locale.h>

#define MAX_PREREQUISITOS 10
#define MAX_DISCIPLINAS 50
#define MAX_SEMESTRES 10

void escreveTopo(){
    printf("_______________________________________________________________________________________________________________________________\n|                                                                                                                             |\n|                                            Matriz Curricular Engenharia de Software                                         |\n|_____________________________________________________________________________________________________________________________|\n");
    
}

void escreveMenu(){
    setlocale(LC_ALL, "Portuguese"); 
    printf("|                    |                    |                    |                    |                    |                    |\n|      Código        |       Curso        |         CH         |      Semestre      |      Pré-Req       |    Tipo de Disc    |\n|____________________|____________________|____________________|____________________|____________________|____________________|\n");

}

// Definição do enum para o tipo de disciplina
typedef enum {
    Obrigatoria,
    Optativa
} TipoDisciplina;

// Definição da struct para uma disciplina
typedef struct {
    char codigo[10];                 // Código alfanumérico da disciplina
    char titulo[20];                // Título da disciplina
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

void lerMatriz(FILE *file, Disciplina *disciplinas, int *quantidade);

void print(const Disciplina *d);

int main(){
    FILE *file;
    Disciplina disciplinas[MAX_DISCIPLINAS];
    int quantidadeRegistros;

    escreveTopo();

    escreveMenu();

    file = fopen("home//adolfo//Documentos//codigos//disciplinas.txt", "r");

    /*
    //contando a quantidade de registros no arquivo
    fseek(file, 0, SEEK_END); //mover o ponteiro para o final

    long tamanhoArquivo = ftell(file); //declara o tamanho total do arquivo em questão

    rewind(file); //rebobinar, mandar ponteiro para o ínicio novamente

    int quantidadeRegistros = tamanhoArquivo / sizeof(Disciplina); //calculando a quatidade de registros
    

    Disciplina disciplinas[quantidadeRegistros]; //array para armazenar os dados

    //fazendo a leitura dos dados
    fread(disciplinas, sizeof(Disciplina), quantidadeRegistros, file); //onde armazenar, tamanho da informação, tamanho da nossa leitura do arquivo, fonte
    */

    lerMatriz(file, disciplinas, &quantidadeRegistros);

    fclose(file);

    //varrer o vetor
    for (int i = 0; i < quantidadeRegistros; i++){
        print(&disciplinas[i]); //printando os dados armazenados no array "disciplinas"
    }

    return 0;
}

void lerMatriz(FILE *file, Disciplina *disciplinas, int *quantidade) {
    int i = 0;
    while (fscanf(file, "%s %s %d %d %d", 
                  disciplinas[i].codigo, 
                  disciplinas[i].titulo, 
                  &disciplinas[i].cargaHoraria, 
                  &disciplinas[i].semestre, 
                  &disciplinas[i].numPrerequisitos) != EOF) {
        for (int j = 0; j < disciplinas[i].numPrerequisitos; j++) {
            fscanf(file, "%s", disciplinas[i].prerequisitos[j]);
        }
        int tipo;
        fscanf(file, "%d", &tipo);
        disciplinas[i].tipo = (TipoDisciplina)tipo;
        i++;
    }
    *quantidade = i;
}

void print(const Disciplina *d) {
    const char *tipoD = (d->tipo == Obrigatoria) ? "Obrigatoria" : "Optativa"; //

    
    // Impressão dos dados da disciplina
    printf("|%-20s|%-20s|%-20d|%-20d|\n", d->codigo, d->titulo, d->cargaHoraria, d->semestre);

    // Impressão dos pré-requisitos
    for (int i = 0; i < d->numPrerequisitos; i++) {
        printf("%s ", d->prerequisitos[i]);
    }
    
    // Completa os espaços se houver menos pré-requisitos
    for (int i = d->numPrerequisitos; i < 2; i++) {
        printf("               ");
    }

    // Impressão do tipo da disciplina
    printf("|%-20s|\n", tipoD);
}

/*
void lmatriz(){
    FILE *file;

    file = fopen("disciplinas.bin", "r");

    Disciplina disciplinas[MAX_DISCIPLINAS];

    fread(disciplinas, sizeof(Disciplina), MAX_DISCIPLINAS, file);

    for(int i = 0; i < MAX_DISCIPLINAS; i++){
        printf(">>%d\n\n", disciplinas[i].numPrerequisitos);
        
    }

    fclose(file);

}*/
