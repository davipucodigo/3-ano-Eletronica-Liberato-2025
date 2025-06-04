#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define ELEM 10

// PROVA 26/05 - TURMA 4324 - DAVI SANT'ANNA VIEIRA
typedef struct {
    char nome[50];
    int idade;
    float peso;
    float altura;
}individuo;

individuo pessoas[ELEM];

void aleatorio() {
    for (int i = 0; i < ELEM; i ++) {
        strcpy(pessoas[i].nome, "Fulano");
        pessoas[i].idade = 15+(rand()%85);
        pessoas[i].peso = 40+(rand()%80);
        pessoas[i].altura = 60+(rand()%138);
    }
}

int main()
{
    srand(time(NULL));
    aleatorio();
    int c;
    int loop = 1;
    int pos = 0;
    int confirma = 0;
    float digitado;
    while (loop == 1) {
        printf("\n\nMENU\n1)Exibir Estruturas\n2)MAIOR ALTURA\n3)MAIOR PESO\n4)MAIOR IDADE\n5)Consultar idade especifica\n6)Concultar altura especifica\n0)SAIR");
        printf("\n>> ");
        scanf("%d",&c);
        switch (c) {
            case 1:
                for (int i = 0;i < ELEM; i++) printf("\n\npessoas[%d] \nNome: %s\n Idade: %d\n Peso: %.2f\n Altura: %.2f", i+1, pessoas[i].nome ,pessoas[i].idade,pessoas[i].peso,pessoas[i].altura);
            break;
            case 2:
                //Mair Altura:
                for (int x = 0;x < ELEM; x++) {
                    pos=x;
                    for (int y = 0; y < ELEM; y++) {
                        if (pessoas[y].altura > pessoas[pos].altura && pos != y) {
                            confirma = 0;
                            break;
                        }else {
                            confirma = 1;
                        }
                    }
                    if (confirma == 1) {
                        break;
                    }
                }
                printf("MAIOR ALTURA: %s pessoas[%d] = %f", pessoas[pos].nome, 1+pos, pessoas[pos].altura);
            break;
            case 3:
                //Maior Peso:
                for (int x = 0;x < ELEM; x++) {
                    pos=x;
                    for (int y = 0; y < ELEM; y++) {
                        if (pessoas[y].peso > pessoas[pos].peso && pos != y) {
                            confirma = 0;
                            break;
                        }else {
                            confirma = 1;
                        }
                    }
                    if (confirma == 1) {
                        break;
                    }
                }
                printf("MAIOR PESO: %s pessoas[%d] = %f", pessoas[pos].nome, 1+pos, pessoas[pos].peso);
            break;
            case 4:
                //Maior idade:
                for (int x = 0;x < ELEM; x++) {
                    pos=x;
                    for (int y = 0; y < ELEM; y++) {
                        if (pessoas[y].idade > pessoas[pos].idade && pos != y) {
                            confirma = 0;
                            break;
                        }else {
                            confirma = 1;
                        }
                    }
                    if (confirma == 1) {
                        break;
                    }
                }
                printf("MAIOR IDADE: %s pessoas[%d] = %d", pessoas[pos].nome, 1+pos, pessoas[pos].idade);
            break;
            case 5:
                //Consultar idade:
                printf("\n  >> ");
                scanf("%f",&digitado);
                fflush(stdin);
                for (int y = 0; y < ELEM; y++) {
                    if (digitado == pessoas[y].idade) {
                        printf("\nIDADE ESPECIFICA ACHADA! %s pessoas[%d] = %d", pessoas[y].nome, 1+y, pessoas[y].idade);
                        break;
                    }
                }
            break;
            case 6:
                //Consultar Altura:
                //Consultar idade:
                printf("\n  >> ");
                scanf("%f",&digitado);
                fflush(stdin);
                for (int y = 0; y < ELEM; y++) {
                    if (digitado == pessoas[y].altura) {
                        printf("\nALTURA ESPECIFICA ACHADA! %s pessoas[%d] = %f", pessoas[y].nome, 1+y, pessoas[y].altura);
                        break;
                    }
                }
            break;
            case 0:
                loop = 0;
            break;
        }
    }
    return 0;
}