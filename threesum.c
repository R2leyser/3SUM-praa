#include <stdio.h>
#include <stdlib.h>
#include "threesum.h"
#include <limits.h>

int qtdOperacoes3SumFB = 0;
int qtdOperacoes3SumMelhorado = 0;

/* treeSumForcaBruta(): */
void treeSumForcaBruta(int A[], int n) {
    MergeSortRecursivo(A, 0, n-1, n);
    int Triplas[3] = {0};
    if(A[0] == 0 && A[1] == 0 && A[2] == 0) {
        printf("A soma de %d + %d + %d = 0\n", A[0], A[1], A[2]);
    }    
    for(int i = 0; i<n-2; i++){
        qtdOperacoes3SumFB++;
        for(int j = i+1; j<n-1; j++){
            qtdOperacoes3SumFB++;
            for(int k = j+1; k<n; k++){
                qtdOperacoes3SumFB++;
                if (A[i] + A[j] + A[k] == 0 && (A[i] != Triplas[0] || A[j] != Triplas[1] || A[k] != Triplas[2]) ) {   
                    printf("A soma de %d + %d + %d = 0\n", A[i], A[j], A[k]);
                    Triplas[0] = A[i];
                    Triplas[1] = A[j];
                    Triplas[2] = A[k];
                }
                qtdOperacoes3SumFB+=3;
            }
        }
    }

}

/* treeSumMelhorado(): */
void treeSumMelhorado(int A[], int n) {
    MergeSortRecursivo(A, 0, n-1, n);
    int Triplas[3] = {0};
    if(A[0] == 0 && A[1] == 0 && A[2] == 0) {
        printf("A soma de %d + %d + %d = 0\n", A[0], A[1], A[2]);
    }
    for (int i = 0; i < n-2; i++) {
        qtdOperacoes3SumMelhorado++;
        for (int j = i+1; j < n-1; j++) {
            qtdOperacoes3SumMelhorado++;
            int x = -(A[i] + A[j]);
            int k = BuscaBinaria(x, A, j+1, n-1);
            if (k != INT_MAX && (A[i] != Triplas[0] || A[j] != Triplas[1] || A[k] != Triplas[2]) ) {
                printf("A soma de %d + %d + %d = 0\n", A[i], A[j], A[k]);
                Triplas[0] = A[i];
                Triplas[1] = A[j];
                Triplas[2] = A[k];
            }
            qtdOperacoes3SumMelhorado+=3;
        }
    }
}

/* BuscaBinaria(): */
int BuscaBinaria (int x, int A[], int inicio, int fim)
{
    while (inicio <= fim) {
        qtdOperacoes3SumMelhorado++;
        int meio = (inicio + fim) / 2;
        if (A[meio] == x) {
            return meio;
        } else if (A[meio] < x) {
            qtdOperacoes3SumMelhorado++;
            inicio = meio + 1;
        } else {
            qtdOperacoes3SumMelhorado++;
            fim = meio - 1;
        }
        qtdOperacoes3SumMelhorado++;
    }
    return INT_MAX; // Não encontrado
}

/* MergeSortRecursivo(): */
void MergeSortRecursivo(int A[], int inicio, int fim, int n)
{
    if (inicio < fim) {
        int meio = (inicio + fim) / 2;
        MergeSortRecursivo(A, inicio, meio, n);
        MergeSortRecursivo(A, meio + 1, fim, n);
        IntercalaSemSentinela(A, inicio, meio, fim, n);
    }
}

/* IntercalaSemSentinela(): */
void IntercalaSemSentinela(int A[], int inicio, int meio, int fim, int n) {
    int i = inicio;
    int j = meio + 1;
    int k = 0;
    int *B = (int*) malloc ((fim - inicio + 1) * sizeof(int));

    while (i <= meio && j <= fim) {
        if (A[i] < A[j]) {
            B[k++] = A[i++];
        } else {
            B[k++] = A[j++];
        }
    }

    while (i <= meio) {
        B[k++] = A[i++];
    }

    while (j <= fim) {
        B[k++] = A[j++];
    }

    for (int l = 0; l < k; l++) {
        A[inicio + l] = B[l];
    }

    free(B);
}

/* ImprimeArray(): */
void ImprimeArray(int A[], char Msg[], int n)
{
    printf("%s", Msg);
    printf("[ " );
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("]");
    printf("\n");
}

/* ImprimeQtdOperacoes():  */
void ImprimeQtdOperacoes()
{
    printf("\n\n");
    printf(" --- 3SUM FORCA BRUTA --- \n");
    printf("Quantidade de Operações: %d\n", qtdOperacoes3SumFB);
    printf("\n\n");
    printf(" --- 3SUM MELHORADO --- \n");
    printf("Quantidade de Operações: %d\n", qtdOperacoes3SumMelhorado);
}
