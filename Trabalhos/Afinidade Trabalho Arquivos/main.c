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
    char nome[100];     //--> Não usado para pontuar
    int idade;                  //--> 1
    data nascimento;    //--> Não usado para pontuar   
    char email[100];    //--> Não usado para pontuar
    long int phone;     //--> Não usado para pontuar
    // Elementos de grau de afinidade:
    char time[80];              //--> 1
    char equipe[80];            //--> 1
    char profissao[80];         //--> 1
    char cidade[80];            //--> 1
    //Mais seis elementos:
    char comida_favo[80];       //--> 1
    char estilo_musi[80];       //--> 1
    char genero_film[80];       //--> 1
    char genero_seri[80];       //--> 1
    char hobbie[80];            //--> 1
    char sonho[80];             //--> 1
    // Tudo peso 1, grau maximo de afinidade 11.
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

void Preencher_e_Gravar_Stuct(registrado *p) {
    char Data[10];
    int nome_valido = 0;

    printf("\n\nAbrindo Registro...[ ⭮ ]");
    printf("\n-== Registre o Individuo ==-\n");

    while (!nome_valido) {
        printf("Nome: "); scanf("%s", p->nome);

        // Verifica se já existe no arquivo
        FILE *LE_ARQUIVO = fopen("Registrados.bin", "rb");
        if (LE_ARQUIVO) {
            registrado temp;
            nome_valido = 1;
            while (fread(&temp, sizeof(registrado), 1, LE_ARQUIVO)) {
                if (!strcmp(temp.nome, p->nome)) {
                    printf("Nome já existe! Escolha outro.\n");
                    nome_valido = 0;
                    break;
                }
            }
            fclose(LE_ARQUIVO);
        } else {
            // Se arquivo não existe, nome é automaticamente válido por que neste caso o arquivo ainda não foi criado
            nome_valido = 1;
        }
    }
    
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

    printf("\nRegistrando...[ ⭮ ], %s", p->nome);
    //Escrevendo Arquivo
    FILE * ESCREVE_ARQUIVO;
    ESCREVE_ARQUIVO = fopen("Registrados.bin", "a+b");
    if (!ESCREVE_ARQUIVO) printf("Não foi possível escrever");
    fwrite(p, sizeof(registrado), 1, ESCREVE_ARQUIVO);
    fclose(ESCREVE_ARQUIVO);
    printf("\nRegistrado.[ ✓ ]");
}

void Gerar_Tabela_de_Afinidade() {
    printf("\n\n-== Tabela Afinidade ==-");
    printf("\nCruzando Dados Registrados...[ ⭮ ]\n");
    int grau_afinidade = 0;
    registrado pcompara;
    registrado ppercorre;

    FILE * COMPARA;
    FILE * PERCORRE;
    FILE * ESCREVE;

    //Apagar o conteúdo e Reescrever Depois no Cruzamento.
    ESCREVE = fopen("AfinidadeTabela.txt","w+t");
    fclose(ESCREVE);

    COMPARA = fopen("Registrados.bin", "rb");
    PERCORRE = fopen("Registrados.bin", "rb");

    while (fread(&pcompara, sizeof(registrado), 1, COMPARA)) {
        while (fread(&ppercorre, sizeof(registrado), 1, PERCORRE)) {
            //Cruzamento de Dados e Grau de Afinidade.
            if (strcmp(pcompara.nome,ppercorre.nome) != 0) {
                printf("\n| %s ---> %s |", pcompara.nome, ppercorre.nome);
                if (pcompara.idade == ppercorre.idade) grau_afinidade++; // 1
                if (!(strcmp(pcompara.time,ppercorre.time))) grau_afinidade++;    // 2
                if (!(strcmp(pcompara.equipe,ppercorre.equipe))) grau_afinidade++;    // 3
                if (!(strcmp(pcompara.profissao,ppercorre.profissao))) grau_afinidade++;    // 4
                if (!(strcmp(pcompara.cidade,ppercorre.cidade))) grau_afinidade++;    // 5
                if (!(strcmp(pcompara.comida_favo,ppercorre.comida_favo))) grau_afinidade++;    // 6
                if (!(strcmp(pcompara.estilo_musi, ppercorre.estilo_musi))) grau_afinidade++;    // 7
                if (!(strcmp(pcompara.genero_film, ppercorre.genero_film))) grau_afinidade++;    // 8
                if (!(strcmp(pcompara.genero_seri, ppercorre.genero_seri))) grau_afinidade++;    // 9
                if (!(strcmp(pcompara.hobbie, ppercorre.hobbie))) grau_afinidade++;    // 10
                if (!(strcmp(pcompara.sonho, ppercorre.sonho))) grau_afinidade++;    // 11
                printf(" Grau de Afinidade: %d;",grau_afinidade);
                printf(
            "\n   Time: %s %s"
                    "\n   Equipe: %s %s"
                    "\n   Profissão: %s %s"
                    "\n   Cidade: %s %s"
                    "\n   Comida: %s %s"
                    "\n   Estilo Musica: %s %s"
                    "\n   Genero Filme: %s %s"
                    "\n   Genero Série: %s %s"
                    "\n   Hobbie: %s %s"
                    "\n   Sonho: %s %s\n",
                    pcompara.time, ppercorre.time,
                    pcompara.equipe, ppercorre.equipe,
                    pcompara.profissao, ppercorre.profissao,
                    pcompara.cidade, ppercorre.cidade,
                    pcompara.comida_favo, ppercorre.comida_favo,
                    pcompara.estilo_musi, ppercorre.estilo_musi,
                    pcompara.genero_film, ppercorre.genero_film,
                    pcompara.genero_seri, ppercorre.genero_seri,
                    pcompara.hobbie, ppercorre.hobbie,
                    pcompara.sonho, ppercorre.sonho
                );
                printf("\nDados Cruzados[ ✓ ]");
                printf("\nGravando no Arquivo...[ ⭮ ]");

                ESCREVE = fopen("AfinidadeTabela.txt","a+t");
                if (!ESCREVE) printf("Não foi possível Gravar.[ X ]");
                else printf("\nGravado no Arquivo[ ✓ ]");

                fprintf(ESCREVE,
                    "\n| %s ---> %s | Grau: %d"
                    "\n   Time: %s %s"
                    "\n   Equipe: %s %s"
                    "\n   Profissão: %s %s"
                    "\n   Cidade: %s %s"
                    "\n   Comida: %s %s"
                    "\n   Estilo Musica: %s %s"
                    "\n   Genero Filme: %s %s"
                    "\n   Genero Série: %s %s"
                    "\n   Hobbie: %s %s"
                    "\n   Sonho: %s %s\n",
                    pcompara.nome, ppercorre.nome, grau_afinidade,
                    pcompara.time, ppercorre.time,
                    pcompara.equipe, ppercorre.equipe,
                    pcompara.profissao, ppercorre.profissao,
                    pcompara.cidade, ppercorre.cidade,
                    pcompara.comida_favo, ppercorre.comida_favo,
                    pcompara.estilo_musi, ppercorre.estilo_musi,
                    pcompara.genero_film, ppercorre.genero_film,
                    pcompara.genero_seri, ppercorre.genero_seri,
                    pcompara.hobbie, ppercorre.hobbie,
                    pcompara.sonho, ppercorre.sonho
                );
                fclose(ESCREVE);

                printf("\n");
                grau_afinidade = 0;
            }
        }
        fseek(PERCORRE, 0, SEEK_SET); //Volta pro inicio.
    }

    fclose(COMPARA);
    fclose(PERCORRE);

}

void Buscar_por_Posicao() {
    //Variaveis
    registrado agora;
    int conta_todos = 0;
    int escolha_posição = 0;
    char minhabusca[100];
    
    //Lê para contar elementos e escolher posição
    FILE * PERCORRE;
    PERCORRE = fopen("Registrados.bin", "rb");
        while (fread(&agora, sizeof(registrado), 1, PERCORRE)) {
            conta_todos++;
        }

        printf("\nNúmero de registrados: %d",conta_todos);
    fclose(PERCORRE);

    //Buscando por posição
    // printf("\n Digite a posição: "); 
    // scanf("%d", &escolha_posição);
    // if (escolha_posição > conta_todos) {
    //     printf("Número invalido, só há %d registrados. ", conta_todos);
    // }else {
    //     conta_todos = 0;
    //     PERCORRE = fopen("Registrados.bin", "rb");
    //     while (fread(&agora, sizeof(registrado), 1, PERCORRE)) {
    //         conta_todos++;
    //         if (escolha_posição == conta_todos) {
    //             printf("%s", agora.nome);
    //         }
    //     }
    //     fclose(PERCORRE);
    // }
    
    //Buscando por caracteristica
    printf("\n"
        "\n 1) Time"
        "\n 2) Equipe"
        "\n 3) Profissão"
        "\n 4) Cidade"
        "\n 5) Comida"
        "\n 6) Estilo Musica"
        "\n 7) Genero Filme"
        "\n 8) Genero Série"
        "\n 9) Hobbie"
        "\n 10) Sonho"
        "\nDigite o numero correspondente a caracteristica desejada: "); 
    scanf("%d", &escolha_posição);
    //caracteristica buscada
    printf("Digite a caracterista: ");
    scanf("%s", minhabusca);
    switch (escolha_posição)
    {
        case 1://Time
            PERCORRE = fopen("Registrados.bin", "rb");
            while (fread(&agora, sizeof(registrado), 1, PERCORRE)) {
                if (!(strcmp(agora.time, minhabusca))) {
                    printf(" %s ", agora.nome);
                }
            }
            fclose(PERCORRE);
            break;
        case 2://========================Equipe
            PERCORRE = fopen("Registrados.bin", "rb");
            while (fread(&agora, sizeof(registrado), 1, PERCORRE)) {
                if (!(strcmp(agora.equipe, minhabusca))) {
                    printf(" %s ", agora.nome);
                }
            }
            fclose(PERCORRE);
            break;
        case 3://========================profissao
            PERCORRE = fopen("Registrados.bin", "rb");
            while (fread(&agora, sizeof(registrado), 1, PERCORRE)) {
                if (!(strcmp(agora.profissao, minhabusca))) {
                    printf(" %s ", agora.nome);
                }
            }
            fclose(PERCORRE);
            break;
        case 4://========================Cidade
            PERCORRE = fopen("Registrados.bin", "rb");
            while (fread(&agora, sizeof(registrado), 1, PERCORRE)) {
                if (!(strcmp(agora.cidade, minhabusca))) {
                    printf(" %s ", agora.nome);
                }
            }
            fclose(PERCORRE);
            break;
        case 5://========================Comida
            PERCORRE = fopen("Registrados.bin", "rb");
            while (fread(&agora, sizeof(registrado), 1, PERCORRE)) {
                if (!(strcmp(agora.comida_favo, minhabusca))) {
                    printf(" %s ", agora.nome);
                }
            }
            fclose(PERCORRE);
            break;
        case 6://========================Estilo Musica
            PERCORRE = fopen("Registrados.bin", "rb");
            while (fread(&agora, sizeof(registrado), 1, PERCORRE)) {
                if (!(strcmp(agora.estilo_musi, minhabusca))) {
                    printf(" %s ", agora.nome);
                }
            }
            fclose(PERCORRE);
            break;
        case 7://========================Genero Filme
            PERCORRE = fopen("Registrados.bin", "rb");
            while (fread(&agora, sizeof(registrado), 1, PERCORRE)) {
                if (!(strcmp(agora.genero_film, minhabusca))) {
                    printf(" %s ", agora.nome);
                }
            }
            fclose(PERCORRE);
            break;
        case 8://========================Genero Série
            PERCORRE = fopen("Registrados.bin", "rb");
            while (fread(&agora, sizeof(registrado), 1, PERCORRE)) {
                if (!(strcmp(agora.genero_seri, minhabusca))) {
                    printf(" %s ", agora.nome);
                }
            }
            fclose(PERCORRE);
            break;
        case 9://========================Hobbie
            PERCORRE = fopen("Registrados.bin", "rb");
            while (fread(&agora, sizeof(registrado), 1, PERCORRE)) {
                if (!(strcmp(agora.hobbie, minhabusca))) {
                    printf(" %s ", agora.nome);
                }
            }
            fclose(PERCORRE);
            break;
        case 10://========================Sonho
            PERCORRE = fopen("Registrados.bin", "rb");
            while (fread(&agora, sizeof(registrado), 1, PERCORRE)) {
                if (!(strcmp(agora.sonho, minhabusca))) {
                    printf(" %s ", agora.nome);
                }
            }
            fclose(PERCORRE);
            break;
        default:
            printf("Número digitado para caracteristica não corresponde.");
            break;
    }
    
    // ========================== // ============================= //
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
                Preencher_e_Gravar_Stuct(&pessoa);
                Gerar_Tabela_de_Afinidade();
            break;
            case 2:
                // Função Pesquisa Caracteristica
                Buscar_por_Posicao();
            break;
            case 3:
                // Buscar Afinidade entre dois Registrados
            break;
            case 4:
                //Tabela de Afinidade
                Gerar_Tabela_de_Afinidade();
            break;
            case 5:
                //Sair
                exit = 0;
            break;
        }
    }while(exit);
}