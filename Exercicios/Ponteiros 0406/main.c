#include <stdio.h>
#include <stdlib.h>

// AULA Ponteiros - DIA 04/06/2025 - Programação
int num = 3; // Variavel.
int *address; // Ponteiro (Apontam para o endereço da variavel na memória).


int main() {
    /* Ponteiro
    Evitar uso de variaveis globais para não ocupar a memoria tanto. Antigamente era escasso a quantida de memoria. 
    Hoje em dia ainda é usado para otimizar devido a sua caracteristica de não copiar o valor de uma variavel para outra variavel
    toda vez que precisa passar a diante o mesmo, mas sim apontar para a variavel onde o valor está guardado.
    */

    address = &num; // Atribuindo o endereço da variavel ao ponteiro.
    //        ↑Endereço (&)
    //
    // Operadores do Ponteiro.
    //                                                 ↓Valor guardado no endereço do ponteiro (*).
    printf("Endereço: %d, Valor: %d", address, *address );
    printf("\n\n");


    return 0;
}