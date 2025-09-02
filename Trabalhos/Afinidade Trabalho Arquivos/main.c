#include <stdio.h> // <-- Possui o FILE Aqui.
#include <stdlib.h>
#include <locale.h>
#include <string.h>

#define LinuxSystem 1 

//Structs
typedef struct {
    int dia;
    int mes;
    int ano;
}data;

typedef struct {
    char nome[100];
    int idade;
    data nascimento;
    char email[100];
    long int phone;
    // Elementos de grau de afinidade:
    char time[80];
    char equipe[80];
    char profissao[80];
    char cidade[80];
    //Mais seis elementos:
    char comida_favo[80];
    char estilo_musi[80];
    char genero_film[80];
    char genero_seri[80];
    char hobbie[80];
    char sonho[80];
}registrado;

//registrado pessoa;
//registrado le_pessoa;

//Exigencias 25 PRÉ-Cadastrados, N°Itens 15, Peso;
// 2 Arquivos, 1 deles guarda os registrados e o outro guarda uma tabela de afinidades (ex.: João x Mario grau 10);
// data prazo final 3 Setembro entrega.
// Ctrl + ; // AutoComentarios

//Funções
void Menu_Style_Linux() {
/*
Bash Shell Color
30: Black
31: Red
32: Green
33: Yellow
34: Blue
35: Magenta
36: Cyan
37: White
*/
    
    printf("\n\e[90m.--------------------------------------------------------------------------------.\e[0m");
    printf("\n\e[90m| DAVI SANT'ANNA VIEIRA - Turma 4324 - Programação Prof.: Sauer                  |\e[0m");
    printf("\n.--------------------------------------------------------------------------------.");
    printf("\n|\e[34m  @@@@@@  @@@@@@@@ @@@ @@@  @@@ @@@ @@@@@@@   @@@@@@  @@@@@@@  @@@@@@@@  @@@@@@ \e[0m|");
    printf("\n|\e[34m @@!  @@@ @@!      @@! @@!@!@@@ @@! @@!  @@@ @@!  @@@ @@!  @@@ @@!      !@@     \e[0m|");
    printf("\n|\e[34m @!@!@!@! @!!!:!   !!@ @!@@!!@! !!@ @!@  !@! @!@!@!@! @!@  !@! @!!!:!    !@@!!  \e[0m|");
    printf("\n|\e[34m !!:  !!! !!:      !!: !!:  !!! !!: !!:  !!! !!:  !!! !!:  !!! !!:          !:! \e[0m|");
    printf("\n|\e[34m  :   : :  :       :   ::    :  :   :: :  :   :   : : :: :  :  : :: ::: ::.: :  \e[0m|");
    printf("\n|                                                                                |");
    printf("\n|\e[32m                                 . - MENU - .                                   \e[0m|");
    printf("\n|\e[32m               1 > Registrar                                                    \e[0m|");
    printf("\n|\e[32m               2 > Pesquisar por Característica                                 \e[0m|");
    printf("\n|\e[32m               3 > Buscar Afinidade entre Dois Registrados                      \e[0m|");
    printf("\n|\e[32m               4 > Tabela de Afinidades                                         \e[0m|");
    printf("\n|\e[32m               5 > Exit                                                         \e[0m|");
    printf("\n.--------------------------------------------------------------------------------.");
    printf("\n");
    printf("\e[31m!Entre com o número da opção desejada!\e[0m\n\e[33m>>\e[0m\e[32m ");
}

void Menu_Style_Win() {
    system("color 72");
    printf("\n.--------------------------------------------------------------------------------.");
    printf("\n| DAVI SANT'ANNA VIEIRA - Turma 4324 - Programação Prof.: Sauer                  |");
    printf("\n.--------------------------------------------------------------------------------.");
    printf("\n|  @@@@@@  @@@@@@@@ @@@ @@@  @@@ @@@ @@@@@@@   @@@@@@  @@@@@@@  @@@@@@@@  @@@@@@ |");
    printf("\n| @@!  @@@ @@!      @@! @@!@!@@@ @@! @@!  @@@ @@!  @@@ @@!  @@@ @@!      !@@     |");
    printf("\n| @!@!@!@! @!!!:!   !!@ @!@@!!@! !!@ @!@  !@! @!@!@!@! @!@  !@! @!!!:!    !@@!!  |");
    printf("\n| !!:  !!! !!:      !!: !!:  !!! !!: !!:  !!! !!:  !!! !!:  !!! !!:          !:! |");
    printf("\n|  :   : :  :       :   ::    :  :   :: :  :   :   : : :: :  :  : :: ::: ::.: :  |");
    printf("\n|                                                                                |");
    printf("\n|                                 . - MENU - .                                   |");
    printf("\n|               1 > Registrar                                                    |");
    printf("\n|               2 > Pesquisar por Característica                                 |");
    printf("\n|               3 > Buscador Afinidade entre Dois Registrados                    |");
    printf("\n|               4 > Tabela de Afinidades                                         |");
    printf("\n|               5 > Exit                                                         |");
    printf("\n.--------------------------------------------------------------------------------.");
    printf("\n");
    printf("!Entre com o número da opção desejada!\n>> ");
}

// //Funções
// void Registrar() {
//     char Data[10];
//     printf("\n\n...Abrindo Registro.");
//     printf("\n-== Registre o Individuo ==-\n");
//     printf("Nome: "); scanf("%s",pessoa.nome);
//     fflush(stdin);
//     printf("Idade: "); scanf("%d",&pessoa.idade);
//     fflush(stdin);
//     //data
//     printf("Data 00/00: ");
//     scanf("%s", Data);
//     fflush(stdin);
//     pessoa.nascimento.dia = ((Data[0]-'0') * 10) + (Data[1]-'0');
//     pessoa.nascimento.mes = ((Data[3]-'0') * 10) + (Data[4]-'0');
//     pessoa.nascimento.ano = 2025-pessoa.idade;
//     printf("    Data Escolhida: %d/%d/%d", pessoa.nascimento.dia, pessoa.nascimento.mes, pessoa.nascimento.ano);
//     //continua
//     printf("\nEmail: "); scanf("%s",pessoa.email);
//     printf("Phone: "); scanf("%d",&pessoa.phone);
//     printf("Time: "); scanf("%s",pessoa.time);
//     printf("Equipe: "); scanf("%s",pessoa.equipe);
//     printf("Profissão: "); scanf("%s",pessoa.profissao);
//     printf("Cidade: "); scanf("%s",pessoa.cidade);
//     printf("Comida Favorita: "); scanf("%s",pessoa.comida_favo);
//     printf("Estilo Musical: "); scanf("%s",pessoa.estilo_musi);
//     printf("Genero Filme: "); scanf("%s",pessoa.genero_film);
//     printf("Genero Série: "); scanf("%s",pessoa.genero_seri);
//     printf("Hobbie: "); scanf("%s",pessoa.hobbie);
//     printf("Sonho: "); scanf("%s",pessoa.sonho);
    
//     //Cadastrado
//     printf("\n...Cadastrando\n");

//     FILE * myfile;
//     myfile = fopen("Registrados.bin", "a+b");
//     fwrite(&pessoa, sizeof(registrado), 1, myfile);
//     printf("Cadastrado.");
//     fclose(myfile);

//     // Puchando dados
//     printf(" \nDados: ");
//     FILE * fileread;
//     fileread = fopen("Registrados.bin", "r");

//     while(!feof(fileread))
//     {
//         fread(&le_pessoa, sizeof(registrado), 1, fileread);
//         if(!(strcmp(plido->nome, pessoa.nome))) {
//             break;
//         }
//     }
//     printf("%s %d %d/%d/%d %s",plido->nome, plido->idade, plido->nascimento.dia, plido->nascimento.mes, plido->nascimento.ano, plido->cidade);
//     printf("\nTel/Email: %d %s",plido->phone, plido->email);
//     printf("\nGostos: %s %s %s %s %s %s %s %s", plido->time, plido->equipe,plido->comida_favo, plido->estilo_musi, plido->genero_film, plido->genero_seri, plido->hobbie, plido->sonho);
//     fclose(fileread);
// }

void Preencher_Struct(registrado *p) {
    char Data[10];
    printf("\n\n...Abrindo Registro.");
    printf("\n-== Registre o Individuo ==-\n");
    printf("Nome: "); scanf("%s", p->nome);
    printf("Idade: "); scanf("%d", &p->idade);
    // Data
    printf("Data 00/00: ");
    scanf("%s", Data);
    p->nascimento.dia = ((Data[0]-'0') * 10) + (Data[1]-'0');
    p->nascimento.mes = ((Data[3]-'0') * 10) + (Data[4]-'0');
    p->nascimento.ano = 2025 - p->idade;
    printf("    Data Escolhida: %d/%d/%d", p->nascimento.dia, p->nascimento.mes, p->nascimento.ano);

    printf("\nEmail: "); scanf("%s", p->email);
    printf("Phone: "); scanf("%d", &p->phone);
    printf("Time: "); scanf("%s", p->time);
    printf("Equipe: "); scanf("%s", p->equipe);
    printf("Profissão: "); scanf("%s", p->profissao);
    printf("Cidade: "); scanf("%s", p->cidade);
    printf("Comida Favorita: "); scanf("%s", p->comida_favo);
    printf("Estilo Musical: "); scanf("%s", p->estilo_musi);
    printf("Genero Filme: "); scanf("%s", p->genero_film);
    printf("Genero Série: "); scanf("%s", p->genero_seri);
    printf("Hobbie: "); scanf("%s", p->hobbie);
    printf("Sonho: "); scanf("%s", p->sonho);

    //Escrevendo Arquivo
    FILE * ESCREVE_ARQUIVO;
    ESCREVE_ARQUIVO = fopen("Registrados.bin", "a+b");
    fwrite(p, sizeof(registrado), 1, ESCREVE_ARQUIVO);
    printf("Cadastrado.");
    fclose(ESCREVE_ARQUIVO);
}

int main () {
    //Locale Troca para o pt_br
    setlocale(LC_ALL,"Portuguese");
    //Variaveis
    int exit = 1;
    int op;
    registrado pessoa;

    //Menu
    do {
        //Troca de Menu para cada Sistema, Desabilite o define LinuxSystem se estiver usando Windows
        if (LinuxSystem) Menu_Style_Linux();
        else Menu_Style_Win();

        //Entrada de Opções
        scanf("%d", &op);
        fflush(stdin);

        //Ações
        switch (op) {
            case 1:
                // Função Registra
                Preencher_Struct(&pessoa);
            break;
            case 2:
                // Função Pesquisa Caracteristica
            break;
            case 3:
                // Buscar Afinidade entre dois Registrados
            break;
            case 4:
                //Tabela de Afinidade
            break;
            case 5:
                //Sair
                exit = 0;
            break;
        }
    }while(exit);
}