#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_PREREQUISITOS 10
#define MAX_DISCIPLINAS 50
#define MAX_SEMESTRES 10
#define MAX_ATIVIDADES 100

void escreveTopo(){
    int total = 120;
    // Título a ser centralizado
    char titulo[] = "Matriz Curricular Engenharia de Software";

    // Espaçamento antes e depois do título para centralizar
    int before = (total - strlen(titulo)) / 2;
    int after = total - strlen(titulo) - before;

    // Linha superior
    printf("\u2554");  // ╔
    for(int i = 0; i < total; i++){
        printf("\u2550");  // ═
    }
    printf("\u2557\n");  // ╗

    // Linha em branco abaixo da borda superior
    printf("\u2551%*s\u2551\n", total, "");

    // Linha com o título centralizado
    printf("\u2551%*s%s%*s\u2551\n", before, "", titulo, after, "");

    // Linha em branco acima da borda inferior
    printf("\u2551%*s\u2551\n", total, "");

    // Linha inferior
    printf("\u255A");  // ╚
    for(int i = 0; i < total; i++){
        printf("\u2550");  // ═
    }
    printf("\u255D\n");  // ╝
}

void escreveCabecalho(){
    printf("\u2551%-10s\u2551%-40s\u2551%-10s\u2551%-10s\u2551%-30s\u2551%-15s\u2551\n", "Codigo", "Curso", "CH", "Semestre", "Pre-Req", "Tipo");
    printf("\u255F");  // ╟

    for(int i = 0; i < 10; i++) printf("\u2550");  // Código
    printf("\u256B");  // ╫

    for(int i = 0; i < 40; i++) printf("\u2550");  // Curso
    printf("\u256B");

    for(int i = 0; i < 10; i++) printf("\u2550");  // Carga Horária
    printf("\u256B");

    for(int i = 0; i < 10; i++) printf("\u2550");  // Semestre
    printf("\u256B");

    for(int i = 0; i < 30; i++) printf("\u2550");  // Pré-requisitos
    printf("\u256B");

    for(int i = 0; i < 15; i++) printf("\u2550");  // Tipo de Disciplina
    printf("\u255F\n");  // Finaliza a linha separadora
}

void escreveFuncoes(){
    printf("Digite a opcao desejada: \n1 - Listar matriz curricular\n2 - Cadastrar disciplinas\n3 - Apresentar historico escolar\n4 - Gerenciar agenda\n5 - Apresentar tarefas pendentes\nx - Sair\n");
    //função de controle
}

void escreveFTopo(char titulo[100], int total){
    // Espaçamento antes e depois do título para centralizar
    int before = (total - strlen(titulo)) / 2;
    int after = total - strlen(titulo) - before;

    // Linha superior
    printf("\u2554");  // ╔
    for(int i = 0; i < total; i++){
        printf("\u2550");  // ═
    }
    printf("\u2557\n");  // ╗

    // Linha com o título centralizado
    printf("\u2551%*s%s%*s\u2551\n", before, "", titulo, after, "");

    // Linha inferior
    printf("\u255A");  // ╚
    for(int i = 0; i < total; i++){
        printf("\u2550");  // ═
    }
    printf("\u255D\n");  // ╝
}

// Definição do enum para o tipo de disciplina
typedef enum{
    Obrigatoria,
    Optativa
} TipoDisciplina;

// Definição da struct para uma disciplina
typedef struct{
    char codigo[10];                  // Código alfanumérico da disciplina
    char titulo[100];                  // Título da disciplina
    int cargaHoraria;                 // Carga horária da disciplina
    int semestre;                     // Semestre em que a disciplina é oferecida
    char prerequisitos[MAX_PREREQUISITOS][10];  // Lista de códigos das disciplinas pré-requisito
    int numPrerequisitos;             // Quantidade de pré-requisitos
    TipoDisciplina tipo;              // Tipo da disciplina (Optativa ou Obrigatória)
} Disciplina;

//Definição da struct para a matriz curricular
typedef struct{
    Disciplina disciplinas[MAX_DISCIPLINAS];
    int numSemestres;           //Número de semestres
} MatrizCurricular;

//Definição da struct para uma atividade
typedef struct {
    char titulo[100];      // Título da atividade
    char data[11];         // Data da atividade (DD/MM/AAAA)
    int status;            // Status da atividade (Pendente ou Concluída)
} Atividade;

//variáveis globais
Disciplina disciplinas[MAX_DISCIPLINAS];
int quantidadeRegistros;

//função para relacionar o codigo da disciplina com seus titulos
void frelate(char *codigo, char titulos[MAX_DISCIPLINAS][100], int *count){
    int aux = 0;

    for(int i = 0; i < quantidadeRegistros; i++){
        if(strcmp(disciplinas[i].codigo, codigo) == 0){
            strcpy(titulos[*count], disciplinas[i].titulo);
            (*count)++;  // Incrementa o contador de títulos salvos
            aux = 1;   // Marca que encontrou o código
            break;
        }
    }

    // Se o código não foi encontrado
    if(!aux){
        printf("Disciplina com o codigo %s nao encontrada.\n", codigo);
    }
}

void printPre(char prerequisitos[][10], int numPrerequisitos){
    char str[31] = "";  // String final que conterá os códigos concatenados
    int slen = 0;

    for(int i = 0; i < numPrerequisitos; i++){
        // Verifica se há espaço suficiente para o próximo pré-requisito
        int nlen = slen + strlen(prerequisitos[i]) + 1; // +1 para o espaço entre as strings

        if(nlen <= 31){
            // Se não for o primeiro pré-requisito, adiciona um espaço
            if(slen > 0){
                strcat(str, " ");
                slen++;
            }

            // Concatena o pré-requisito atual à string final
            strcat(str, prerequisitos[i]);
            slen += strlen(prerequisitos[i]);
        } else{
            break;  // Não há mais espaço para adicionar novos pré-requisitos
        }
    }

    // Exibe a string final com os pré-requisitos
    printf("%-30s\u2551 ", str);
}

void pause(){
    printf("\nPressione Enter para continuar...");
    getchar(); // Captura qualquer tecla
    getchar(); // Para consumir o '\n' deixado pelo scanf
}

void list();

void regist();

void record();

void agenda();

void actpend();

int main() {
    FILE *file;  
    char op = ' ';
    int A = 0;
    Atividade atividade[MAX_ATIVIDADES];

    //file = fopen("C:\\Users\\Aluno\\Documents\\ATP\\disciplinas.bin", "rb"); // Abrir arquivo no windows
    file = fopen("//home//adolfo//Downloads//arqs_projeto_final//disciplinas.bin","rb"); //Abrir arquivo no linux
    if(file == NULL){
        perror("Erro ao abrir o arquivo");
        return 0;
    } else{
        printf("Arquivo aberto com sucesso!\n");
    }

    fread(&quantidadeRegistros, sizeof(int), 1, file);
    fread(disciplinas, sizeof(Disciplina), quantidadeRegistros, file);
    fclose(file);

    do{
        //system("cls");//limpar a tela windows
        system("clear"); //limpar a tela Linux
        escreveTopo();        
        escreveFuncoes();
        scanf(" %c", &op);
        switch (op){
            case '1':
                list();
                pause();
                break;
            case '2':
                regist();
                pause();
                break;
            case '3':
                record();
                pause();
                break;
            case '4':
                agenda(atividade, &A);
                pause();
                break;
            case '5':
                actpend(atividade, &A);
                pause();
                break;
            case ' ':
                break;
            default:
                printf("Opcao invalida!\n");
                break;
        }
    }while(op != 'x');
    
    return 0;
}

void list(){
    escreveCabecalho();

    for(int i = 0; i < quantidadeRegistros; i++){
        // Imprimir código, curso, CH, semestre
        printf("\u2551%-10s\u2551%-40s\u2551%-10d\u2551%-10d\u2551", disciplinas[i].codigo, disciplinas[i].titulo, disciplinas[i].cargaHoraria, disciplinas[i].semestre);

        // Imprimir pré-requisitos
        if(disciplinas[i].numPrerequisitos > 0){
            for(int j = 0; j < disciplinas[i].numPrerequisitos; j++){
                printf("%s ", disciplinas[i].prerequisitos[j]);  // Exibir pré-requisitos
            }
        } else{
            printf("%-30s\u2551", "Nenhum");  // Caso não haja pré-requisitos
        }

        // Imprimir tipo da disciplina
        printf("%-15s\u2551\n", (disciplinas[i].tipo == Obrigatoria) ? "Obrigatoria" : "Optativa");  // Finaliza a linha da disciplina
    }
}

void regist(){
    Disciplina cadastro[MAX_DISCIPLINAS];  // Array para guardar as disciplinas que o aluno pretende cadastrar
    char titulos[MAX_DISCIPLINAS][100];  // Array para armazenar os títulos relacionados
    int N, count = 0;  // Contador de materias e de títulos
    
    printf("Quantas materias o aluno pretende cadastrar? ");
    scanf("%d", &N);
    printf("\n");

    if (N > MAX_DISCIPLINAS) {
        printf("Limite de disciplinas excedido.\n");
        return;
    }

    // Loop para ler os códigos das disciplinas que o aluno deseja cadastrar
    for(int i = 0; i < N; i++){
        printf("Digite o codigo da %dª disciplina: ", i + 1);
        scanf("%s", cadastro[i].codigo);  // Armazena o código no array de disciplinas
        printf("\n");
    }

    escreveFTopo("Disciplinas cadastradas", 50);

    // Loop para relacionar os códigos das disciplinas aos seus respectivos títulos
    for(int i = 0; i < N; i++){
        // Relaciona o código com o título e armazena no array titulos
        frelate(cadastro[i].codigo, titulos, &count);
        // Exibe o código e o título relacionados
        printf("\u2551%-10s\u2551%-40s\u2551\n", cadastro[i].codigo, titulos[count - 1]);
    }

    //formatação do final da tabela
    printf("\u255A");  // ╚
    for(int i = 0; i < 50; i++){
        printf("\u2550");  // ═
    }
    printf("\u255D\n");  // ╝

}

void record(){
    Disciplina concluidas[MAX_DISCIPLINAS];  // Array para guardar as disciplinas ja cursadas pelo usuario
    char titulos[MAX_DISCIPLINAS][100];  // Array para armazenar os títulos relacionados
    int N, count = 0;  // Contador de materias e de títulos

    printf("Quantas materias o aluno cursou? ");
    scanf("%d", &N);
    printf("\n");

    if (N > MAX_DISCIPLINAS) {
        printf("Limite de disciplinas excedido.\n");
        return;
    }

    // Loop para ler os códigos das disciplinas que o aluno ja cursou
    for (int i = 0; i < N; i++) {
        printf("Digite o codigo da %dª disciplina: ", i + 1);
        scanf("%s", concluidas[i].codigo);  // Armazena o código no array de disciplinas
        printf("\n");
    }

    escreveFTopo("Historico Escolar", 50);

    for(int i = 0; i < N; i++){
        // Relaciona o código com o título e armazena no array titulos
        frelate(concluidas[i].codigo, titulos, &count);
        // Exibe o código e o título relacionados
        printf("\u2551%-10s\u2551%-30s\u2551\n", concluidas[i].codigo, titulos[count - 1]);
    }

    //formatação do final da tabela
    printf("\u255A");  // ╚
    for(int i = 0; i < 50; i++){
        printf("\u2550");  // ═
    }
    printf("\u255D\n");  // ╝
}

void agenda(Atividade atividade[], int *A){
    int N;

    printf("Quantas atividades serao adicionadas a agenda? ");
    scanf("%d", &N);
    getchar();

    if (N > MAX_ATIVIDADES) {
        printf("Limite de atividades excedido.\n");
        return;
    }

    *A = N; //Variavel que vai servir de ponteiro para quantidade de atividades lidas
    for(int i = 0; i < N; i++){
        char aux;
        
        printf("Digite o titulo da atividade: ");
        fgets(atividade[i].titulo, 100, stdin);
        atividade[i].titulo[strcspn(atividade[i].titulo, "\n")] = 0;  // Remover \n no final

        printf("Digite a data (DD/MM/AAAA): ");
        fgets(atividade[i].data, 11, stdin);
        atividade[i].data[strcspn(atividade[i].data, "\n")] = 0;  // Remover \n no final

        printf("Sua atividade ja foi concluida? (S ou N) ");
        scanf(" %c", &aux);  // Espaço para ignorar espaços em branco
        getchar();


        if(aux == 'N'){
            atividade[i].status = 0;
        } else if(aux == 'S'){
            atividade[i].status = 1;
        } else{
            printf("\nEscolha invalida!\n");
            return;
        }
        printf("\n");

        printf("Atividade adicionada com sucesso!\n");
    }

    escreveFTopo("Agenda academica", 60);
    printf("\u2551%-30s\u2551%-15s\u2551%-13s\u2551\n", "Titulo", "Data", "Status");
    // Linha inferior das colunas
    printf("\u255A");  // ╚
    for(int i = 0; i < 60; i++){
        printf("\u2550");  // ═
    }
    printf("\u255D\n");  // ╝

    for(int i = 0; i < N; i++){
        printf("\u2551%-30s\u2551%-15s\u2551", atividade[i].titulo, atividade[i].data);
        printf("%-13s\u2551\n", (atividade[i].status == 0) ? "Pendente" : "Concluida");

    }

    //formatação do final da tabela
    printf("\u255A");  // ╚
    for(int i = 0; i < 60; i++){
        printf("\u2550");  // ═
    }
    printf("\u255D\n");  // ╝
}

void actpend(Atividade atividade[], int *A){
    escreveFTopo("Atividades Pendentes", 46);
    printf("\u2551%-31s\u2551%-14s\u2551\n", "Titulo", "Data");

    // Linha inferior das colunas
    printf("\u255A");  // ╚
    for(int i = 0; i < 46; i++){
        printf("\u2550");  // ═
    }
    printf("\u255D\n");  // ╝

    for(int i = 0; i < *A; i++){
        if (atividade[i].status == 0){  // Somente atividades pendentes
            printf("\u2551%-31s\u2551%-14s\u2551\n", atividade[i].titulo, atividade[i].data);
        }
    }

    //formatação do final da tabela
    printf("\u255A");  // ╚
    for(int i = 0; i < 46; i++){
        printf("\u2550");  // ═
    }
    printf("\u255D\n");  // ╝
}
