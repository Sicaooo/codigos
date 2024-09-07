#include <stdio.h>
#include <string.h>

void vigenere(const char *p, const char *c, const char o) { 
    char palavra_final[100];
    int pos = 0;
    if (o == 'c') {
        for (int i = 0; i < strlen(p); i++) {
            palavra_final[i] = p[i] + c[pos] - 'a' <= 'z' ? p[i] + c[pos] - 'a' : p[i] + c[pos] - 'z' - 1;
            pos == (strlen(c) - 1) ? pos = 0 : pos++;
        }
    }
    else {
        for (int i = 0; i < strlen(p); i++) {
            palavra_final[i] = p[i] - c[pos] + 'a' >= 'a' ? p[i] - c[pos] + 'a' : p[i] - c[pos] + 'z' + 1;
            pos == (strlen(c) - 1) ? pos = 0 : pos++;
        }
    }
    palavra_final[strlen(p)] = '\0';
    printf("%s\n", palavra_final);
}


typedef char str[100];

int main() {
    char opcao;
    printf("digite C para criptografar e D para descriptografar: ");
    do {
        scanf("%c", &opcao);
    } while (opcao != 'c' && opcao != 'C' && opcao != 'd' && opcao != 'D');

    str palavra, chave; 
    printf("%s", opcao == 'c' ? "insira o texto para criptografar: " : "insira o texto para descriptografar: ");
    scanf("%s", palavra);

    printf("insira a chave: ");
    scanf("%s", chave);

    vigenere(palavra, chave, opcao);

    return 0;
}
