#include <stdio.h>

int main() {
    int numeros[10], i, l;
    for (i = 0; i < 10; i++) {
        scanf("%d", &numeros[i]);
        if (numeros[i] <= 0){
            numeros[i] = 1;
        }
    }

    for (l = 0; l < 10; l++) {
        printf("X[%d] = %d\n", l, numeros[l]);
    }

    return 0;
}