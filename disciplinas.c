#include <stdio.h>
#include <string.h>
#include <locale.h>

#define MAX_PREREQUISITOS 10
#define MAX_DISCIPLINAS 50
#define MAX_SEMESTRES 10

void escreveTopo() {
    printf("_______________________________________________________________________________________________________________________________\n");
    printf("|                                                                                                                             |\n");
    printf("|                                            Matriz Curricular Engenharia de Software                                         |\n");
    printf("|_____________________________________________________________________________________________________________________________|\n");
}

void escreveCabecalho() {
    setlocale(LC_ALL, "Portuguese");
    printf("|                    |                    |                    |                    |                    |                    |\n");
    printf("|      Codigo        |       Curso        |         CH         |      Semestre      |      Pre-Req       |    Tipo de Disc    |\n");
    printf("|____________________|____________________|____________________|____________________|____________________|____________________|\n");
}

void escreveFuncoes(){
    printf("Digite 1 para listar matriz - 2 para ... - x para sair\n");
}

// Definição do enum para o tipo de disciplina
typedef enum {
    Obrigatoria,
    Optativa
} TipoDisciplina;

// Definição da struct para uma disciplina
typedef struct {
    char codigo[10];                  // Código alfanumérico da disciplina
    char titulo[100];                  // Título da disciplina
    int cargaHoraria;                 // Carga horária da disciplina
    int semestre;                     // Semestre em que a disciplina é oferecida
    char prerequisitos[MAX_PREREQUISITOS][10];  // Lista de códigos das disciplinas pré-requisito
    int numPrerequisitos;             // Quantidade de pré-requisitos
    TipoDisciplina tipo;              // Tipo da disciplina (Optativa ou Obrigatória)
} Disciplina;

//variáveis globais
Disciplina disciplinas[MAX_DISCIPLINAS];
int quantidadeRegistros;

void lerMatriz(FILE *file, Disciplina *disciplinas, int *quantidade);
void print(const Disciplina *d);

void listarMatriz(){
    escreveCabecalho();
    for(int i=0; i < quantidadeRegistros; i++){
        printf("Codigo: %s\n", disciplinas[i].codigo);
    }
}

int main() {
    //FILE *file;  
    char op = ' ';  

    FILE *arq = fopen("C:/Users/Aluno/Documents/ATP/disciplinas.bin", "rb");
    if (arq == NULL){
        return 0;
    }
    fread(&quantidadeRegistros, sizeof(int), 1, arq);
    fread(disciplinas, sizeof(Disciplina), quantidadeRegistros, arq);    

    do{
        system("cls");//limpar a tela
        escreveTopo();        
        escreveFuncoes();
        scanf("%c", &op);
        switch (op){
            case '1':
                listarMatriz();
                break;
            case ' ':
                break;
            default:
                printf("Opcao invalida!\n");
                break;
        }
    }while(op != 'x');
    


    /*file = fopen("C:\\Users\\Aluno\\Documents\\ATP\\disciplinas.txt", "r"); // Abrir arquivo de texto

    if (file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    lerMatriz(file, disciplinas, &quantidadeRegistros);
    fclose(file);

    // Varrer o vetor e imprimir os dados
    for (int i = 0; i < quantidadeRegistros; i++) {
        print(&disciplinas[i]);
    }*/

    return 0;
}

void lerMatriz(FILE *file, Disciplina *disciplinas, int *quantidade) {
    int i = 0;
    while (fscanf(file, "%s %s %d %d %d", 
                  disciplinas[i].codigo, 
                  disciplinas[i].titulo, 
                  &disciplinas[i].cargaHoraria, 
                  &disciplinas[i].semestre, 
                  &disciplinas[i].numPrerequisitos) == 5) {
        for (int j = 0; j < disciplinas[i].numPrerequisitos; j++) {
            fscanf(file, "%s", disciplinas[i].prerequisitos[j]);
        }
        int tipo;
        fscanf(file, "%d", &tipo);
        disciplinas[i].tipo = (TipoDisciplina)tipo;
        i++;
        if (i >= MAX_DISCIPLINAS) {
            break;
        }
    }
    *quantidade = i;  // Total de disciplinas lidas
}

void print(const Disciplina *d) {
    const char *tipoD = (d->tipo == Obrigatoria) ? "Obrigatoria" : "Optativa";

    // Impressão dos dados da disciplina
    printf("|%-20s|%-20s|%-20d|%-20d|", d->codigo, d->titulo, d->cargaHoraria, d->semestre);

    // Impressão dos pré-requisitos
    for (int i = 0; i < d->numPrerequisitos; i++) {
        printf("%s ", d->prerequisitos[i]);
    }

    // Completa os espaços se houver menos pré-requisitos
    for (int i = d->numPrerequisitos; i < MAX_PREREQUISITOS; i++) {
        printf("               ");
    }

    // Impressão do tipo da disciplina
    printf("|%-20s|\n", tipoD);
}
