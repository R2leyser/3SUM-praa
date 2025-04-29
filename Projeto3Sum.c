#include <stdio.h>
#include <stdlib.h>
#include "threesum.h"

/* Variáveis Globais */
int *A;

int main () {
    // Declaração das Variáveis
    int n;
    printf("\n ---Projeto 01 - 3SUM--- \n");

    printf("\n Definir o tamanho do Array: ");
    scanf("%d", &n);

    A = (int*) malloc (n * sizeof(int));

    for(int i=0; i<n; i++) {
        printf(" Entre com o %d elemento do Array: ", i+1);
        scanf("%d", &A[i]);
    }

    /*TO DO: Conforme forem implementando, removam os comentários */

    ImprimeArray(A, "Array Infor.   ", n);
    printf("\n\n");
    printf(" --- 3SUM FORCA BRUTA --- \n");
    treeSumForcaBruta(A, n);
    printf("\n\n");
    printf(" --- 3SUM MELHORADO --- \n");
    treeSumMelhorado(A, n);

    //ImprimeQtdOperacoes();
}
