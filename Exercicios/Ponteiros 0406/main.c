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

int divisorTensao (float *ve, float *vs, float *r1, float *r2) {
    if (*r1 == 0 || *r2 == 0 && *ve > 0 && *vs > 0) { 
        if (*r1 == 0 && *r2 == 0) {
            printf("\nR1 e R2 naõ devem ser zero ao mesmo tempo.\n");
            return 0;
        }
        // Calcula R
        else if (*r1 == 0) {
            //calcula
            //R1 = R2 * (Vin / Vout - 1)
            *r1 = *r2 * (*ve / *vs - 1);
            return *r1; 
        }

        else if (*r2 == 0) {
            //calcula
            // R2 = (Vout * R1) / (Vin - Vout)
            *r2 = (*vs * *r1) / (*ve - *vs);
            return *r2;
        }
    }

    if (*r1 < 0 || *r2 < 0 || *vs < 0 || *ve < 0) {
        return 0;
    }
}

void ordena_alfa (char *p1, char *p2 ) {
    // 97 á 122 minusculas
    if (*p1 < *p2) {
        printf("\nEm ordem Alfabetica: ");
        for (int x = 0; x < 50; x++) {
            printf("%c", *p1);
            p1++;
        }
        printf(" ");
        for (int x = 0; x < 50; x++) {
            printf("%c", *p2);
            p2++;
        }
        printf("\n");
    }

    if (*p1 > *p2) {
        printf("\nEm ordem Alfabetica: ");
        for (int x = 0; x < 50; x++) {
            printf("%c", *p2);
            p2++;
        }
        printf(" ");
        for (int x = 0; x < 50; x++) {
            printf("%c", *p1);
            p1++;
        }
        printf("\n");
    }
}

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
    /*
    float R1, R2, Vcc, Vs;
    Vcc = 10;
    Vs = 2.5;
    // Caso 1
    R1 = 0;
    R2 = 1000;
    divisorTensao(&Vcc,&Vs,&R1,&R2);
    printf("\nR1 = %f ohms\n", R1);
    printf("\nR2 = %f ohms\n", R2);

    // Caso 2
    R1 = 1000;
    R2 = 0;
    divisorTensao(&Vcc,&Vs,&R1,&R2);
    printf("\nR1 = %f ohms\n", R1);
    printf("\nR2 = %f ohms\n", R2);

    //Caso 3
    R1 = 0;
    R2 = 0;
    divisorTensao(&Vcc,&Vs,&R1,&R2);
    printf("\nR1 = %f ohms\n", R1);
    printf("\nR2 = %f ohms\n", R2);
    */
    
    //7#)
    /*
    char string1[50] = "abelha";
    char string2[50] = "bola";
    ordena_alfa(string1,string2);
    */

    return 0;
}