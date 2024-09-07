#include <stdio.h>

int main() {
    int qnt;
    scanf("%d", &qnt);
    int arr[qnt];

    for (int i = 0; i < qnt; i++) {
        scanf("%d", &arr[i]);
    }

    int num;
    scanf("%d", &num);

    int pos, cont = 0, contem = 0;
    int inicio = 0, fim = qnt - 1, meio;

    do {
        meio = (inicio + fim) / 2;
        cont++;
        if (arr[meio] == num) {
            pos = meio;
            contem++;
            break;
        }
        else if (arr[meio] < num) {
            inicio = meio + 1;
        }
        else {
            fim = meio - 1;
        }
    } while (inicio <= fim);

    if (contem == 1)
        printf("%d\n%d", pos, cont);
    else
        printf("x nao pertence ao vetor A\n%d", cont);

    return 0;
}