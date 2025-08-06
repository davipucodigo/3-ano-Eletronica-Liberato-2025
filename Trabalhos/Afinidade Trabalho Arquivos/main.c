#include <stdio.h> // <-- Possui o FILE Aqui.
#include <stdlib.h>
#include <locale.h>

#define LinuxSystem 1 

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

int main () {
    setlocale(LC_ALL,"Portuguese");

    //Variaveis;
    int exit = 0;

    //Menu
    do {
        //Troca de Menu para cada Sistema, Desabilite o define LinuxSystem se estiver usando Windows.
        if (LinuxSystem) Menu_Style_Linux();
        else Menu_Style_Win();
        
        //Entrada de Opções
        int op;
        scanf("%d", &op);
        fflush(stdin);

    }while(exit);
}