#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h> 


typedef struct {
    int numero;
    int idade;
    float peso;
    float altura;
}registro;

registro pessoa[50];

int main () {
    srand(time(NULL));

    for (int x = 0; x < 50; x++) {
        pessoa[x].numero = x;
        pessoa[x].idade = 1+rand()%80;
        pessoa[x].peso = 40+(rand()%40)+0.01*(rand()%90); // kg
        pessoa[x].altura = 1+0.01*(rand()%90); // metros
        //
        printf("\nCodigo: %d, Idade: %d, Peso: %.2f, Altura: %.2f.", pessoa[x].numero, pessoa[x].idade, pessoa[x].peso, pessoa[x].altura);
    }

    // CODIGO QUE VERIFICA MAIOR OU MENOR IDADE:
    // [posição][Valor]
    int GUARDA[2][1] = {0,0};
    int ENCONTROU = 0;
    // Guarda Valor da Lista, Compará verificando se é o maior, se não for o maior guarda outro e repete o procedimento.
    for (int x = 0; x < 50; x++) {
        GUARDA[0][0] = x;
        GUARDA[1][0] = pessoa[x].idade;
        for (int y = 0; y < 50; y++) {
            if (pessoa[y].idade > GUARDA[1][0]) {
                ENCONTROU = 0;
                break;
            }else {
                ENCONTROU = 1;
            }
        }
        if (ENCONTROU == 1) {
            break;
        }
    }
    printf("\nCodigo: %d, de Maior Idade: %d", GUARDA[0][0], GUARDA[1][0]);

    // Guarda Valor da Lista, Compará verificando se é o menor, se não for o maior guarda outro e repete o procedimento.
    ENCONTROU = 0;
    for (int x = 0; x < 50; x++) {
        GUARDA[0][0] = x;
        GUARDA[1][0] = pessoa[x].idade;
        for (int y = 0; y < 50; y++) {
            if (pessoa[y].idade < GUARDA[1][0]) {
                ENCONTROU = 0;
                break;
            }else {
                ENCONTROU = 1;
            }
        }
        if (ENCONTROU == 1) {
            break;
        }
    }
    printf("\nCodigo: %d, de Menor Idade: %d", GUARDA[0][0], GUARDA[1][0]);
    printf("\n");
    return 0;
}