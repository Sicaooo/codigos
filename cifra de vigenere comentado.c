#include <stdio.h>
#include <string.h>

void vigenere(const char *p, const char *c, const char o) { 
    char palavra_final[100]; // declaracao da variavel que irá armazenar a palavra final com 100 espaços
    unsigned int pos = 0; // incialização da variavel pos em 0
    if (o == 'c' || o == 'C') { // verifica se é para criptografar
        for (unsigned int i = 0; i < strlen(p); i++) { // incializa a variavel i e incrementa de 1 em 1 enquanto i for menor que o tamanho da palavra
            palavra_final[i] = (p[i] + c[pos] - 194) % 26 + 'a'; // *
            pos == (strlen(c) - 1) ? pos = 0 : pos++; // operador ternario: caso pos seja igual ao tamanho da chave - 1 ele irá zerar, caso contrario é incrementado em 1
        }
    }
    else { // executa caso não seja para criptografar
        for (unsigned int i = 0; i < strlen(p); i++) { // incializa a variavel i e incrementa de 1 em 1 enquanto i for menor que o tamanho da palavra
            palavra_final[i] = (p[i] - c[pos] + 26) % 26 + 'a'; // procedimento reverso do *
            pos == (strlen(c) - 1) ? pos = 0 : pos++; // operador ternario: caso pos seja igual ao tamanho da chave menos 1 ele irá zerar, caso contrario é incrementado em 1
        }
    }
    palavra_final[strlen(p)] = '\0'; // atribui ao último elemento de palavra_final o caractere nulo '\0' para que marque o fim da string
    printf("%s\n", palavra_final); // imprime a palavra_final
}


typedef char str[100]; // cria um tipo char de 100 espaços

int main() {
    char opcao; // declaração da variavel que vai informar se é pra criptografar ou descriptografar a palavra
    printf("digite C para criptografar e D para descriptografar: ");
    do {
        scanf("%c", &opcao); // pede se o usuario irá criptografar ou descriptografar
    } while (opcao != 'c' && opcao != 'C' && opcao != 'd' && opcao != 'D'); // repete o pedido de entrada caso a entrada não seja c, d, C, D

    str palavra, chave; // utiliza o tipo criado na linha 24 como tipo das variaveis palavra e chave
    printf("%s", opcao == 'c' || opcao == 'C' ? "insira o texto para criptografar: " : "insira o texto para descriptografar: ");
    scanf("%s", palavra);

    printf("insira a chave: ");
    scanf("%s", chave); // pede a palavra que sera usada como chave

    vigenere(palavra, chave, opcao); // chamada da função vigenere com os argumentos palavra, chave, e opcao

    return 0;
}

/*
a logica que eu pensei para a cifra funcionava assim: soma as posições da letra da palavra com a letra da chave e usar o resultado pra achar a letra no alfabeto (começando de 0), por exemplo:
L(palavra) = g, L(chave) = m, resultado = s porque 'g' é a 6ª letra do alfabeto e 'm' é a 12ª, 6 + 12 = 18, a 18ª letra do alfabeto é 's'. Daí é só aplica essa lógica na tabela ASCII

 a,  b,  c,  d,  e,   f,   g,   h,   i,   j,   k,   l,   m,   n,   o,   p,   q,   r,   s,   t,   u,   v,   w,   x,   y,   z
97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122

como 97 é o número equivalente ao 'a', se eu subtrair o código de uma letra qualquer por 97 eu tenho a posição da letra no alfabeto, portanto a minha lógica ficaria assim (utilizando as mesmas letras de antes):
(103 - 97) + (109 - 97) eu posso simplificar a conta para 103 + 109 - 194 = 18. 18 não significa uma letra na tabela ASCII, e pra isso eu tenho que somar ele com 97 novamente, o que transforma a equação em 
 (g)          (m)
103 + 109 - 194 + 97, que simplifica em 103 + 109 - 97 = 115. 115 na tabela ASCII é 's'. essa lógica sozinha tem um problema, existe a possibilidade do resutlado extrapolar o escopo do alfabeto, por exemplo:
103 + 117 - 97 = 123. Nesses momentos é necessário voltar ao começo do alfabeto, e pra isso subtraimos o 123 da soma, ficando 103 + 117 - 123 = 97.
(g)   (u)                                                                                                                     (g)   (u)         (a)

então temos duas fórmulas pra achar a letra criprografada: L(p) + L(c) - 97 quando L(p) + L(c) <= 219 e L(p) + L(c) - 123 para os outros casos

O operador ternario (?:) é um if/else de uma linha só, funcionando assim: condicao ? True : False. Assim eu coloco que palavra_final[i] vai receber o retorno da verificação p[i] + c[pos] <= 'a' + 'z',
que será uma das duas fórmulas de cima.
*/
