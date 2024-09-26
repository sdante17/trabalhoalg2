#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_PREREQUISITOS 10
#define MAX_DISCIPLINAS 50
#define MAX_SEMESTRES 10

void escreveTopo(){
    printf("\u2554");  // ╔

    for (int i = 0; i < 125; i++){
        printf("\u2550");  // ═
    }

    printf("\u2557\n");  // ╗
    
    printf("\u2551");  // ║
    printf("                                           Matriz Curricular Engenharia de Software                                          ");
    printf("\u2551\n");  // ║
    
    printf("\u255A");  // ╚

    for (int i = 0; i < 125; i++){
        printf("\u2550");  // ═
    }

    printf("\u255D\n");  // ╝
}


void escreveCabecalho() {

    printf("\u2551      Codigo        \u2551      Curso         \u2551         CH         \u2551      Semestre      \u2551      Pre-Req       \u2551    Tipo de Disc    \u2551\n");
    
    printf("\u255F");  // ╟

    for (int i = 0; i < 20; i++){
        printf("\u2550");  // ═
    }

    printf("\u256B");  // ╫
    for (int i = 0; i < 20; i++){
        printf("\u2550");
    }

    printf("\u256B");

    for (int i = 0; i < 20; i++){
        printf("\u2550");
    }

    printf("\u256B");

    for (int i = 0; i < 20; i++){
        printf("\u2550");
    }

    printf("\u256B");

    for (int i = 0; i < 20; i++){
        printf("\u2550");
    }

    printf("\u256B");

    for (int i = 0; i < 20; i++){
        printf("\u2550");
    }

    printf("\u255F\n");  // ╟
}

void escreveFuncoes(){
    printf("Digite a opção desejada: ");
    printf("1 - Listar matriz curricular\n");
    printf("2 - Cadastrar disciplinas atuais\n");
    printf("3 - Apresentar histórico escolar\n");
    printf("4 - Gerenciar agenda (atividades e compromissos)\n");
    printf("5 - Apresentar tarefas pendentes\n");
    printf("x - Sair\n");

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

void scan(FILE *file, Disciplina *disciplinas, int *quantidadeRegistros);
void print(const Disciplina *d);

/*void list(){
    escreveCabecalho();
    for(int i=0; i < quantidadeRegistros; i++){
        printf("Codigo: %s\n", disciplinas[i].codigo);
    }
}*/

void regist();

int main() {
    FILE *file;  
    char op = ' ';  

    //file = fopen("C:\\Users\\Aluno\\Documents\\ATP\\disciplinas.bin", "rb"); // Abrir arquivo no windows
    file = fopen("home//adolfo//Downloads//arqs_projeto_final//disciplinas.bin","rb"); //Abrir arquivo no linux
    if (file == NULL){
        return 0;
    }
    fread(&quantidadeRegistros, sizeof(int), 1, file);
    fread(disciplinas, sizeof(Disciplina), quantidadeRegistros, file);
    scan(file, disciplinas, &quantidadeRegistros);
    fclose(file);

    do{
        system("cls");//limpar a tela
        escreveTopo();        
        escreveFuncoes();
        scanf("%c", &op);
        switch (op){
            case '1':
                for (int i = 0; i < quantidadeRegistros; i++) {
                    print(&disciplinas[i]);
                }
                break;
            case '2':
                regist();
                break;
            /*case '3';
                record();
                break;
            case '4';
                agenda();
                break;
            case '5';
                pendAct();
                break;*/
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

void scan(FILE *file, Disciplina *disciplinas, int *quantidadeRegistros) {
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
    *quantidadeRegistros = i;  // Total de disciplinas lidas
}

void print(const Disciplina *d) {
    const char *tipoD = (d->tipo == Obrigatoria) ? "Obrigatoria" : "Optativa";
    escreveCabecalho();

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

void regist(){
    Disciplina cadastro; //variavel para guardar as materias que o aluno pretende cadastrar
    int N;

    printf("Quantas materias o aluno pretende cadastrar: ");
    scanf("%d", &N);
    getchar();  // Consome o caractere de nova linha (\n) deixado pelo scanf
    printf("\n");

    for(int i = 0; i < N; i++){
        printf("Disciplina %d: ", i + 1);
        fgets(cadastro.titulo, sizeof(cadastro.titulo), stdin);  // Lê a linha completa
        printf("\n");
    }
}
