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
    // Linha superior do cabeçalho
    printf("\u2554");  // ╔
    for(int i = 0; i < 120; i++){
        printf("\u2550");  // ═
    }
    printf("\u2557\n");  // ╗

    printf("\u2551%-10s\u2551%-50s\u2551%-10s\u2551%-10s\u2551%-20s\u2551%-15s\u2551\n", "Codigo", "Titulo", "CH", "Semestre", "Pre-Req", "Tipo");
    printf("\u255F");  // ╟

    for(int i = 0; i < 10; i++) printf("\u2550");  // Código
    printf("\u256B");  // ╫

    for(int i = 0; i < 50; i++) printf("\u2550");  // Titulo
    printf("\u256B");

    for(int i = 0; i < 10; i++) printf("\u2550");  // Carga Horária
    printf("\u256B");

    for(int i = 0; i < 10; i++) printf("\u2550");  // Semestre
    printf("\u256B");

    for(int i = 0; i < 20; i++) printf("\u2550");  // Pré-requisitos
    printf("\u256B");

    for(int i = 0; i < 15; i++) printf("\u2550");  // Tipo de Disciplina
    printf("\u255F\n");  // Finaliza a linha separadora
}

void escreveFuncoes(){
    printf("\u2551%-40s%-40s%-40s\u2551\n\u2551%-40s%-40s%-40s\u2551\n", "1 - Listar matriz curricular", "3 - Apresentar historico escolar", "5 - Apresentar tarefas pendentes", "2 - Cadastrar disciplinas", "4 - Gerenciar agenda" , "x - Sair");
    // Função de controle

    // Linha inferior
    printf("\u255A");  // ╚
    for(int i = 0; i < 120; i++){
        printf("\u2550");  // ═
    }
    printf("\u255D\n");  // ╝
}

// Função para paginação de titulos das tabelas
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
    int codigo;                  // Código alfanumérico da disciplina
    char titulo[51];                  // Título da disciplina
    int cargaHoraria;                 // Carga horária da disciplina
    int semestre;                     // Semestre em que a disciplina é oferecida
    char prerequisitos[50];           // Lista de códigos das disciplinas pré-requisito
    TipoDisciplina tipo;              // Tipo da disciplina (Optativa ou Obrigatória)
} Disciplina;

// Definição da struct para uma atividade
typedef struct {
    char titulo[30];      // Título da atividade
    char data[11];         // Data da atividade (DD/MM/AAAA)
    int status;            // Status da atividade (Pendente ou Concluída)
} Atividade;

// Variáveis globais
Disciplina disciplinas[MAX_DISCIPLINAS] = {
    389, "Introducao a Engenharia de Software", 54, 1, "", 0,
    390, "Fundamentos de Algebra e Calculo", 54, 1, "", 0,
    391, "Logica e Pensamento Computacional", 54, 1, "", 0,
    392, "Escrita Cientifica para Computacao", 27, 1, "", 0,
    393, "Ingles Instrumental", 27, 1, "", 0,
    // Semestre 2
    394, "Algoritmos e Estruturas de Dados I", 54, 2, "", 0,
    395, "Arquitetura de Computadores", 54, 2, "", 0,
    396, "Calculo Diferencial e Integral", 54, 2, "", 0,
    397, "Programacao Orientada a Objetos", 54, 2, "", 0,
    398, "Sistemas Operacionais I", 54, 2, "", 0,
    // Semestre 3
    399, "Algoritmos e Estruturas de Dados II", 54, 3, "DPAAIN.394", 0,
    400, "Banco de Dados I", 54, 3, "", 0,
    401, "Engenharia de Requisitos", 54, 3, "", 0,
    402, "Grafos e Otimizacao", 54, 3, "", 0,
    403, "Introducao a Inteligencia Artificial", 54, 3, "", 0,
    // Semestre 4
    404, "Engenharia de Software I", 54, 4, "", 0,
    405, "Sistemas Distribuidos", 54, 4, "DPAAIN.398", 0,
    406, "Teoria da Computacao", 54, 4, "", 0,
    407, "Banco de Dados II", 54, 4, "DPAAIN.400", 0,
    408, "Computacao Grafica", 54, 4, "", 0,
    // Semestre 5
    409, "Engenharia de Software II", 54, 5, "DPAAIN.404", 0,
    410, "Seguranca da Informacao", 54, 5, "", 0,
    411, "Computacao em Nuvem", 54, 5, "", 0,
    412, "Programacao Paralela", 54, 5, "", 0,
    413, "TCC I", 54, 5, "", 0,
    // Semestre 6
    414, "TCC II", 54, 6, "DPAAIN.413", 0,
    415, "Engenharia de Software III", 54, 6, "DPAAIN.409", 0,
    416, "Sistemas Embarcados", 54, 6, "", 0,
    417, "Computacao Ubicua", 54, 6, "", 0,
    418, "Qualidade de Software", 54, 6, "DPAAIN.409", 0,
    // Semestre 7
    419, "Desenvolvimento Web", 54, 7, "", 0,
    420, "Desenvolvimento Mobile", 54, 7, "", 0,
    421, "Sistemas de Tempo Real", 54, 7, "", 0,
    422, "Inteligencia Artificial Avancada", 54, 7, "DPAAIN.403", 0,
    423, "Aprendizado de Maquina", 54, 7, "DPAAIN.403", 1,
    // Semestre 8
    424, "Empreendedorismo Tecnologico", 54, 8, "", 0,
    425, "Gestao de Projetos", 54, 8, "", 0,
    426, "Inovacao e Tecnologia", 54, 8, "", 1,
    427, "Computacao Quantica", 54, 8, "", 1,
    428, "Ciencias de Dados", 54, 8, "", 1,
    429, "Seguranca Computacional Avancada", 54, 8, "", 1,
    430, "Arquitetura de Software Avancada", 54, 8, "DPAAIN.404", 1,
    431, "Design de Interface Humano-Computador", 54, 8, "", 1,
    432, "Desenvolvimento de Jogos Digitais", 54, 8, "", 1,
    433, "Inteligencia de Negocios", 54, 8, "", 1,
    // Semestre 9
    434, "Topicos Especiais em Engenharia de Software", 54, 9, "", 0,
    435, "Sistemas Embarcados", 54, 9, "", 0,
    436, "Inteligencia Artificial Avancada", 54, 9, "", 0,
    437, "Acessibilidade e Inclusao Digital", 54, 9, "", 0,
    438, "Gerenciamento de Projetos de Software", 54, 9, "", 0,
};
int quantidadeRegistros = MAX_DISCIPLINAS;

// Função para relacionar o codigo da disciplina com seus titulos
void frelate(int *codigo, char titulos[MAX_DISCIPLINAS][51], int *count){
    int aux = 0; // Variável para auxiliar a busca pelo codigo da disciplina

    for(int i = 0; i < quantidadeRegistros; i++){
        if (disciplinas[i].codigo == *codigo) {
            strcpy(titulos[*count], disciplinas[i].titulo);
            (*count)++;  // Incrementa o contador de títulos salvos
            aux = 1;   // Marca que encontrou o código
            break;
        }
    }

    // Se o código não foi encontrado
    if (!aux) {
        // Preenche o título com a mensagem de erro
        snprintf(titulos[*count], 51, "Disciplina com o codigo %d nao encontrada.", *codigo);
        (*count)++; // Incrementa o contador mesmo assim
    }
}

void list();

void regist();

void record();

void agenda();

void actpend();

void savefile(Disciplina *disciplinas, int total) {
    //file = fopen("\\disciplinas.txt", "w"); // Abrir e escrever arquivo no Windows
    FILE *file = fopen("//disciplinas.txt", "w"); // Abrir e escrever arquivo no Linux

    if (file == NULL) {
        printf("Erro ao abrir o arquivo para gravação.\n");
        return;
    }

    for (int i = 0; i < total; i++) {
        fprintf(file, "%d;%s;%d;%d;%s;%d\n", 
                disciplinas[i].codigo, 
                disciplinas[i].titulo, 
                disciplinas[i].cargaHoraria, 
                disciplinas[i].semestre, 
                disciplinas[i].prerequisitos, 
                disciplinas[i].tipo);
    }

    fclose(file);
}

void scanfile(Disciplina *disciplinas) {
    //FILE *file = fopen("\\disciplinas.txt", "r"); // Abrir e ler arquivo no windows
    FILE *file = fopen("//disciplinas.txt", "r"); // Abrir e ler arquivo no Linux
    if (file == NULL) {
        printf("Erro ao abrir o arquivo para leitura.\n");
        return;
    }

    int i = 0;
    char buffer[256];
    while (fgets(buffer, sizeof(buffer), file) != NULL && i < quantidadeRegistros){
            sscanf(buffer, "%d;%50[^;];%d;%d;%20[^;];%d", 
            &disciplinas[i].codigo, 
            disciplinas[i].titulo, 
            &disciplinas[i].cargaHoraria, 
            &disciplinas[i].semestre, 
            disciplinas[i].prerequisitos, 
            (int*)&disciplinas[i].tipo);
            i++;
    }

    fclose(file);
}

int main() {
    char op = ' ';
    int A = 0;
    Atividade atividade[MAX_ATIVIDADES];

    // Chama a função para gravar o arquivo binário
    savefile(disciplinas, quantidadeRegistros);
    
    // Chama a função para ler o arquivo binário
    scanfile(disciplinas);

    do{
        //system("cls"); // Limpar a tela windows
        system("clear"); // Limpar a tela Linux
        escreveTopo();        
        escreveFuncoes();
        printf("Digite a opcao desejada: ");
        scanf(" %c", &op);
        switch (op){
            case '1':
                list();
                break;
            case '2':
                regist();
                break;
            case '3':
                record();
                break;
            case '4':
                agenda(atividade, &A);
                break;
            case '5':
                actpend(atividade, &A);
                break;
            case ' ':
                break;
            case 'x':
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida!\n");
                break;
        }

        if (op != 'x') {
            printf("Pressione qualquer tecla para continuar...\n");
            getchar(); // Espera o usuário pressionar uma tecla para continuar
            getchar(); // Captura o Enter
        }
    }while(op != 'x');
    
    return 0;
}

void list() {
    escreveCabecalho();

    for (int i = 0; i < quantidadeRegistros; i++) {
        // Imprimir dados do arquivo
        printf("\u2551DPAAIN.%-3d\u2551%-50s\u2551%-10d\u2551%-10d\u2551%-20s\u2551%-15s\u2551\n", 
                disciplinas[i].codigo, 
                disciplinas[i].titulo, 
                disciplinas[i].cargaHoraria, 
                disciplinas[i].semestre,
                (strcmp(disciplinas[i].prerequisitos, "") != 0) ? disciplinas[i].prerequisitos : "Nenhum",
                (disciplinas[i].tipo == 0) ? "Obrigatoria" : "Optativa");
        
    }

    // Formatação do final da tabela
    printf("\u255A");  // ╚
    for (int i = 0; i < 120; i++) {
        printf("\u2550");  // ═
    }
    printf("\u255D\n");  // ╝
}

void regist(){
    Disciplina cadastro[MAX_DISCIPLINAS];         // Array para guardar as disciplinas ja cursadas pelo usuario
    char titulos[MAX_DISCIPLINAS][51] = {{'\0'}}; // Array para armazenar os títulos relacionados
    int N, count = 0;                             // Contador de materias e de títulos
    
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
        scanf("%d", &cadastro[i].codigo);  // Armazena o código no array de disciplinas
        printf("\n");
    }

    escreveFTopo("Disciplinas cadastradas", 61);

    // Loop para relacionar os códigos das disciplinas aos seus respectivos títulos
    for(int i = 0; i < N; i++){
        // Relaciona o código com o título e armazena no array titulos
        frelate(&cadastro[i].codigo, titulos, &count);
        // Exibe o código e o título relacionados
        printf("\u2551DPAAIN.%-3d\u2551%-50s\u2551\n", cadastro[i].codigo, titulos[count - 1]);

    }

    // Formatação do final da tabela
    printf("\u255A");  // ╚
    for(int i = 0; i < 61; i++){
        printf("\u2550");  // ═
    }
    printf("\u255D\n");  // ╝

}

void record(){
    Disciplina concluidas[MAX_DISCIPLINAS];       // Array para guardar as disciplinas ja cursadas pelo usuario
    char titulos[MAX_DISCIPLINAS][51] = {{'\0'}}; // Array para armazenar os títulos relacionados
    int N, count = 0;                             // Contador de materias e de títulos

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
        scanf("%d", &concluidas[i].codigo);  // Armazena o código no array de disciplinas concluidas
        printf("\n");
    }

    escreveFTopo("Historico Escolar", 61);

    for(int i = 0; i < N; i++){
        // Relaciona o código com o título e armazena no array titulos
        frelate(&concluidas[i].codigo, titulos, &count);
        // Exibe o código e o título relacionados
        printf("\u2551DPAAIN.%-3d\u2551%-50s\u2551\n", concluidas[i].codigo, titulos[count - 1]);
    }

    // Formatação do final da tabela
    printf("\u255A");  // ╚
    for(int i = 0; i < 61; i++){
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

    *A = N; // Variavel que vai servir de ponteiro para quantidade de atividades lidas
    for(int i = 0; i < N; i++){
        char aux;
        
        printf("Digite o titulo da atividade: ");
        fgets(atividade[i].titulo, 30, stdin);
        atividade[i].titulo[strcspn(atividade[i].titulo, "\n")] = 0;  // Remover \n no final

        printf("Digite a data de entrega (DD/MM/AAAA): ");
        fgets(atividade[i].data, 11, stdin);
        atividade[i].data[strcspn(atividade[i].data, "\n")] = 0;  // Remover \n no final

        printf("Sua atividade ja foi concluida? (s ou n) ");
        scanf(" %c", &aux);
        getchar();

        if(aux == 'N' || aux == 'n'){
            atividade[i].status = 0;
        } else if(aux || 'S' && aux == 's'){
            atividade[i].status = 1;
        } else{
            printf("\nEscolha invalida!\n");
            return;
        }
        printf("\n");
        printf("Atividade adicionada com sucesso!\n");
        printf("\n");
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

    // Formatação do final da tabela
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

    // Formatação do final da tabela
    printf("\u255A");  // ╚
    for(int i = 0; i < 46; i++){
        printf("\u2550");  // ═
    }
    printf("\u255D\n");  // ╝
}
