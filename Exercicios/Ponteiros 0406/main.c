#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int mainExercicio () {
    float vet[5] = {1.1,2.2,3.3,4.4,5.5};
    float *f;
    int i;
    f = vet;
    printf("contador/valor/valor/endereco/endereco");
    for(i = 0 ; i <= 4 ; i++)
    {
        printf("\ni = %d",i);
        printf(" vet[%d] = %.1f",i, vet[i]);
        printf(" *(f + %d) = %.1f",i, *(f+i));
        printf(" &vet[%d] = %p",i, &vet[i]);
        printf(" (f + %d) = %p",i, f+i);
    }
}

void troca(int * p1, int * p2) {
    printf("\nNumero1 = %d, Numero2 = %d", *p1,*p2);
    int aux = *p1; // *ponteiro se refere ao valor.
    *p1 = *p2; //Sendo assim eu troco o valor armazenado no enderoço.
    *p2 = aux;
    printf("\nNumero1 = %d, Numero2 = %d", *p1,*p2);
    printf("\ntrocado\n");

}

int ordena (int *nm1, int *nm2, int *nm3, char ordem) {
    int aux;
    if (ordem == 'c') {
        if (*nm1 > *nm2) {
            aux = *nm1; // Guarda nm1;
            *nm1 = *nm2; // Troca valor de nm1 por valor de nm2
            *nm2 = aux; // Troca valor do nm2 por valor guardado
        }
        if (*nm2 > *nm3) {
            aux = *nm2;
            *nm2 = *nm3; 
            *nm3 = aux; 
        }
        if (*nm1 > *nm2) {
            aux = *nm1;
            *nm1 = *nm2;
            *nm2 = aux;
        }
    }

    if (ordem == 'd') {
        if (*nm1 < *nm2) {
            aux = *nm1; // Guarda nm1;
            *nm1 = *nm2; // Troca valor de nm1 por valor de nm2
            *nm2 = aux; // Troca valor do nm2 por valor guardado
        }
        if (*nm2 < *nm3) {
            aux = *nm2;
            *nm2 = *nm3; 
            *nm3 = aux; 
        }
        if (*nm1 < *nm2) {
            aux = *nm1;
            *nm1 = *nm2;
            *nm2 = aux;
        }
    }
    printf("\nLista: n1=%d n2=%d n3=%d\n", *nm1, *nm2, *nm3);
}

int sinal(float *frequencia, float *periodo) {
    if (*frequencia == 0 && *periodo != 0) {
        // f = 1/T
        *frequencia = 1 / *periodo;
        
        return 0;
    }
    if (*periodo == 0 && *frequencia != 0) {
        // T = 1/f
        *periodo = 1 / *frequencia;

        return 0;
    }
    if (*frequencia == 0 && *periodo == 0) {
        return -1;
    }
}

int triangulo_retangulo(float *oposto, float *adjacente, float *hipotenusa) {
    if (*oposto != 0 && *adjacente != 0 && *hipotenusa == 0) {
        // sqrtf(pow(a) + pow(b)) = h
        *hipotenusa = sqrtf((*oposto * *oposto) + (*adjacente * *adjacente));
        return 0;
    } 
    if (*oposto != 0 && *adjacente == 0 && *hipotenusa != 0) {
        *adjacente = sqrtf((*hipotenusa * *hipotenusa) - (*oposto * *oposto));
        return 0; 
    } 
    if (*oposto == 0 && *adjacente != 0 && *hipotenusa != 0) {
        *oposto = sqrtf((*hipotenusa * *hipotenusa) - (*adjacente * *adjacente));
        return 0; 
    } 
}

/*void ordena_alfa (char *p1, char *p2 ) {
    // 97 á 122 minusculas
    if (*p1 > *p2) {
    }
}*/

int main() {
    //==================================== EXERCICIOS LISTA PONTEIROS ============================================== //
    //#1)
    //mainExercicio();

    //#2)
    /*
    int num1 = 5;
    int num2 = 10;
    troca(&num1,&num2);
    */

    //#3)
    /*
    int n1,n2,n3;
    n1 = 5;
    n2 = 3;
    n3 = 2;
    ordena(&n1,&n2,&n3,'c');
    ordena(&n1,&n2,&n3,'d');
    */

    //#4)
    /*
    float periodo = 0;
    float frequencia = 60;
    sinal(&frequencia,&periodo);
    printf("\nFrequencia: %fHz  Periodo: %fs\n",frequencia,periodo);
    */

    //5#)
    // Use gcc main.c -o main -lm
    // devido ao ambiente linux.
    /*
    float a,b,h;
    a = 12;
    b = 12;
    h = 0;
    triangulo_retangulo(&a,&b,&h);
    printf("h = %f", h);
    */

    //6#)

    //7#)
    char string1[50] = "gato";
    char string2[50] = "cachorro";
    //ordena_alfa(&string1,&string2);


    return 0;
}