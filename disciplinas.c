#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_PREREQUISITOS 10
#define MAX_DISCIPLINAS 50
#define MAX_SEMESTRES 10

void escreveTopo() {
    printf("\u2554");  // ╔
    
    for (int i = 0; i < 185; i++) {
        printf("\u2550");  // ═
    }
    
    printf("\u2557\n");  // ╗

    printf("\u2551");  
    printf("%-180s", "Matriz Curricular Engenharia de Software");
    printf("\u2551\n");  // ║

    printf("\u255A");  // ╚

    for (int i = 0; i < 185; i++) {
        printf("\u2550");  // ═
    }

    printf("\u255D\n");  // ╝
}

void escreveCabecalho() {
    printf("\u2551 %-10s \u2551 %-30s \u2551 %-10s \u2551 %-10s \u2551 %-30s \u2551 %-15s \u2551\n", "Codigo", "Curso", "CH", "Semestre", "Pre-Req", "Tipo de Disciplina");
    printf("\u255F");  // ╟

    for (int i = 0; i < 10; i++) printf("\u2550");  // Código
    printf("\u256B");  // ╫

    for (int i = 0; i < 30; i++) printf("\u2550");  // Curso
    printf("\u256B");

    for (int i = 0; i < 10; i++) printf("\u2550");  // Carga Horária
    printf("\u256B");

    for (int i = 0; i < 10; i++) printf("\u2550");  // Semestre
    printf("\u256B");

    for (int i = 0; i < 30; i++) printf("\u2550");  // Pré-requisitos
    printf("\u256B");

    for (int i = 0; i < 15; i++) printf("\u2550");  // Tipo de Disciplina
    printf("\u255F\n");  // Finaliza a linha separadora
}


void escreveFuncoes(){
    printf("Digite a opção desejada: ");
    printf("1 - Listar matriz curricular\n");
    printf("2 - Cadastrar disciplinas\n");
    printf("3 - Apresentar histórico escolar\n");
    printf("4 - Gerenciar agenda\n");
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

void printPre(char prerequisitos[][10], int numPrerequisitos) {
    char str[31] = "";  // String final que conterá os códigos concatenados
    int slen = 0;

    for(int i = 0; i < numPrerequisitos; i++) {
        // Verifica se há espaço suficiente para o próximo pré-requisito
        int nlen = slen + strlen(prerequisitos[i]) + 1; // +1 para o espaço entre as strings

        if(nlen <= 31) {
            // Se não for o primeiro pré-requisito, adiciona um espaço
            if (slen > 0) {
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

/*void pause() {
    printf("\nPressione Enter para continuar...");
    getchar(); // Captura qualquer tecla
    getchar(); // Para consumir o '\n' deixado pelo scanf
}*/

void list();

void regist();

int main() {
    FILE *file;  
    char op = ' ';  

    //file = fopen("C:\\Users\\Aluno\\Documents\\ATP\\disciplinas.bin", "rb"); // Abrir arquivo no windows
    file = fopen("//home//adolfo//Downloads//arqs_projeto_final//disciplinas.bin","rb"); //Abrir arquivo no linux
    if (file == NULL){
        perror("Erro ao abrir o arquivo");
        return 0;
    } else {
        printf("Arquivo aberto com sucesso!\n");
    }

    fread(&quantidadeRegistros, sizeof(int), 1, file);
    printf("Quantidade de registros lidos: %d\n", quantidadeRegistros);
    fread(disciplinas, sizeof(Disciplina), quantidadeRegistros, file);
    fclose(file);

    do{
        //system("cls");//limpar a tela windows
        system("clear"); //limpar a tela Linux
        escreveTopo();        
        escreveFuncoes();
        scanf("%c", &op);
        switch (op){
            case '1':
                list();
                //pause();
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
    
    return 0;
}

void list() {
    for (int i = 0; i < quantidadeRegistros; i++) {
        // Imprimir código, curso, CH, semestre
        printf("\u2551 %-10s \u2551 %-30s \u2551 %-10d \u2551 %-10d \u2551 ", disciplinas[i].codigo, disciplinas[i].titulo, disciplinas[i].cargaHoraria, disciplinas[i].semestre);

        // Imprimir pré-requisitos
        if (disciplinas[i].numPrerequisitos > 0) {
            for (int j = 0; j < disciplinas[i].numPrerequisitos; j++) {
                printf("%s ", disciplinas[i].prerequisitos[j]);  // Exibir pré-requisitos
            }
        } else {
            printf("%-30s\u2551 ", "Nenhum");  // Caso não haja pré-requisitos
        }

        // Imprimir tipo da disciplina
        const char* tipo = (disciplinas[i].tipo == Obrigatoria) ? "Obrigatória" : "Optativa";
        printf("%-15s \u2551\n", tipo);  // Finaliza a linha da disciplina
    }
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
