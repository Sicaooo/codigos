#include <stdio.h>
#include <string.h>

void sort(int ordem, int tamanho, int vetor[tamanho]) {
    int i, j, l, num, maior, pos = 0;
    for (i = 0; i < tamanho; i++) {
        if (i == 0) {
            maior = vetor[i];
        }
        else if (vetor[i] > maior) {
            maior = vetor[i];
            pos = i;
        }
    }
    vetor[pos] = vetor[0];
    vetor[0] = maior;
    for (i = 0; i < tamanho; i++) {
        for (j = 0; j < tamanho; j++) {
            if (vetor[i] < vetor[j]) {
                num = vetor[i];
                for (l = i; l > j; l--) {
                    vetor[l] = vetor[l-1];
                }
                vetor[j] = num;
            }
        }
    }
    if (ordem < 0) {
        int aux;
        for (i = 0; i < tamanho; i++) {
            aux = vetor[i];
            vetor[i] = vetor[tamanho-1 - i];
            vetor[tamanho-1 - i] = aux; 
        }
    }
}

int main() {
    int quantidade;
    printf("Insira o tamanho do vetor: ");
    scanf("%d", &quantidade);

    int vetor[quantidade];
    
    for (int i = 0; i < quantidade; i++) {
        printf("Insira o %do vetor: ", i+1);
        scanf("%d", &vetor[i]);
    }
    
    int ordem;
    char ordenacao[20];
    printf("Insira um numero positivo para organizar o vetor em ordem crescente e negativo para ordem decrescente: ");
    scanf("%d", &ordem);
    ordem >= 0 ? strcpy(ordenacao, "crescente") : strcpy(ordenacao, "decrescente");
    
    sort(ordem, quantidade, vetor);

    printf("Vetor ordenado em ordem %s: ", ordenacao);
    for (int i = 0; i < quantidade; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
    
    

    return 0;
}
/*
 0   1  2  3  4  5  6  7  8  9 10
{10, 1, 4, 2, 3, 7, 0, 9, 8, 5, 6}
{1, 10, 4, 2, 3, 7, 0, 9, 8, 5, 6}
{1, 4, 10, 2, 3, 7, 0, 9, 8, 5, 6}
{1, 2, 4, 10, 3, 7, 0, 9, 8, 5, 6}
{1, 2, 3, 4, 10, 7, 0, 9, 8, 5, 6}
{1, 2, 3, 4, 5, 10, 7, 0, 9, 8, 6}
{1, 2, 3, 4, 5, 6, 10, 7, 0, 9, 8}
{1, 2, 3, 4, 5, 6, 7, 10, 0, 9, 8}
{1, 2, 3, 4, 5, 6, 7, 8, 10, 0, 9}
{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 0}
{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10}
*/





