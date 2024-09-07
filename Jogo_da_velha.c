#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define RED "\033[1;31m" // define uma chamada constante para o código ANSI de deixar string em vermelho
#define RESET "\033[0m" // define uma chamada constante para o código ANSI de deixar string em branco
#define GREEN "\033[92m" // define uma chamada constante para o código ANSI de deixar string em verde

char jogada (int indicador) { // indica de quem é a vez de jogar
    char lance;
    if (indicador % 2 == 0) {
        lance = 'X';
    }                                         
    else {                          
        lance = 'O';
    }
    return lance; // retorna 'x' ou 'o' dependendo se a variavel "x_ou_o" é par ou impar respectivamente.
}

void limpar_matriz (char matriz[3][3]) { // limpa os elementos da matriz para que não apareça números perdidos da memória 
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            matriz[i][j] = ' ';
        }
    }
}

int verificacao(char matriz[3][3]) { // verifica se o jogo deve continuar ou se há algum vencedor. (return 0 = jogador O venceu / return 2 = jogador X venceu / return 3 = jogo empatou / return 1 = o jogo (não acabou)
    int terminou = 0, i, j; // variavel controle se a partida terminou ou não
    for (i = 0; i < 3; i++) { // verifica se todos os elementos do jogo da velha são 'x' ou 'o'
        for (j = 0; j < 3; j++) {
            if (matriz[i][j] == 'X' || matriz[i][j] == 'O') {

            }
            else {
                terminou = 1; // atribui 1 a variavel "terminou" caso haja um elemento difernete de 'x' ou 'o' na matriz
            }
        }
    }

    for (i = 0; i < 3; i++) { // verifica se há um ganhador
        if (matriz[i][0] == matriz[i][1] && matriz[i][0] == matriz[i][2]) {
            if (matriz[i][0] == 'X') {
                return 2;
            }
            else if (matriz[i][0] == 'O') {
                return 0;
            }
        }
        else if (matriz[0][i] == matriz[1][i] && matriz[0][i] == matriz[2][i]) {
            if (matriz[0][i] == 'X') {
                return 2;
            }
            else if (matriz[0][i] == 'O') {
                return 0;
            }
        }
        else if (matriz[0][0] == matriz[1][1] && matriz [0][0] == matriz[2][2]) {
            if (matriz[0][0] == 'X') {
                return 2;
            }
            else if (matriz[0][0] == 'O') {
                return 0;
            }
        }
        else if (matriz[2][0] == matriz[1][1] && matriz[2][0] == matriz[0][2]) {
            if (matriz[2][0] == 'X') {
                return 2;
            }
            else if (matriz[2][0] == 'O') {
                return 0;
            }
        }
    }
    if (terminou == 0) {
        return 3; // retorna 3 caso todos os espaços do jogo da velha tenham sido preenchidos e ninguém tenha ganhado (empate)
    }
    else {
        return 1; // retorna 1 caso ainda há espaços para jogar e ninguém tenha ganhado
    } 
}

void entrada_nomes(char nomes[2][50], int player) { // entrada do(s) nome(s) de quem estiver jogando
    if (player == 1) {
        printf("Insira o nome do jogador:\n");
    }
    else {
        printf("Insira o nome dos jogadores:\n");
    }
    printf("Jogador X: ");
    scanf("%s", nomes[0]); // entrada nome jogador X
    if (player == 2) {
        printf("Jogador O: ");
        scanf("%s", nomes[1]); // entrada nome jogador O       
    }
    else {
        strcpy(nomes[1], "Computador"); // define o jogador 2 como sendo o computador caso a quantidade de jogadores seja igual a 1
    }
}  

void placar(int x, int o) { // exibe o placar da partida
    printf("\nPlacar:\n");
    printf("Jogador X %d x %d Jogador O", x, o);
}

void coordenadas(int xy[2], char vez, int player, int x) { // entrada das coordenadas
    if (player == 2) {
        printf("Jogador %c informe a linha: ", vez);
        scanf("%d", &xy[0]);
        printf("Jogador %c informe a coluna: ", vez);
        scanf("%d", &xy[1]);
    }
    else if (vez == 'X') {
        printf("Jogador X informe a linha: ");
        scanf("%d", &xy[0]);
        printf("Jogador X informe a coluna: ");
        scanf("%d", &xy[1]);
    }
    else if (vez == 'O') {
        srand(time(NULL)); // geração de uma seed usando o tempo atual do sistema como base
        int numerox = rand() % 3; // geração de um número aleatorio entre 0 e 2
        srand(time(NULL) + x); // utilização da variavel "x" para que a seed seja diferente da primeira seed gerada
        int numeroy = rand() % 3;
        
        xy[0] = numerox; 
        xy[1] = numeroy;
        // soma 1 ao número gerado e atribui seu valor as variaveis de posicao
    }  
}

int main() { // função responsável por rodar o programa
    setlocale(LC_ALL, "Portuguese_Brazil"); // expande a tabela ASCII para que permita acentos
    
    int i, j;
    int qnt_jogadores; // variavel que armazena quantos jogadores estão jogando
    printf("Quantas pessoas irão jogar? (1/2): ");
    scanf("%d", &qnt_jogadores);
    while (qnt_jogadores != 1 && qnt_jogadores != 2) { // validação da entrada
        printf(RED "Quantidade de jogadores inválida, insira novamente: " RESET);
        scanf("%d", &qnt_jogadores);
    }
    // bloco de código que armazena e valida a quantidade de jogadores

    char nomes[2][50]; // variaveis que armazenarão os nomes dos jogadores X e O
    entrada_nomes(nomes, qnt_jogadores);
    int jogar_novamente; // cria a variavel controle pra verificar se deve haver mais um jogo ou não
    int pontoX = 0, pontoO = 0; // variavel que controla o placar da partida;
    do {
        char jogo_da_velha[3][3]; // matriz que será usada como jogo da velha
        limpar_matriz(jogo_da_velha); // chamada da função limpar_matriz
        int x_ou_o = 0; // variavel pra indicar se é a vez do x ou o
        int posicao[2]; // variaveis responsável por localizar a jogada

        do { // inicia o jogo da velha
            int contador = 0;
            coordenadas(posicao, jogada(x_ou_o), qnt_jogadores, contador);
            while (posicao[0] < 0 || posicao[0] > 2 || posicao[1] < 0 || posicao[1] > 2 || 
            jogo_da_velha[posicao[0]][posicao[1]] == 'X' || jogo_da_velha[posicao[0]][posicao[1]] == 'O') {  // validação das possíveis
                if (qnt_jogadores == 2) {
                    while (getchar() != '\n');
                    printf(RED "\nposição inválida, insira novamente\n" RESET);
                }
                else if (qnt_jogadores == 1 && jogada(x_ou_o) == 'X') {
                    while (getchar() != '\n');
                    printf(RED "\nposição inválida, insira novamente\n" RESET);
                }
                contador++;
                coordenadas(posicao, jogada(x_ou_o), qnt_jogadores, contador);

            }
            
            jogo_da_velha[posicao[0]][posicao[1]] = jogada(x_ou_o); // atribuição do valor da jogada na posição inserida

            printf("\n");
            for (i = 0; i < 3; i++) { // mostra na tela o jogo da velha
                for (j = 0; j < 3; j++) { // formata o jogo da velha
                    printf(" %c ", jogo_da_velha[i][j]);
                    if (j < 2) {
                        printf("|");
                    }
                }
                printf("\n");
                if (i < 2) {
                    printf("---|---|---\n");
                }
            }
            
            x_ou_o++; // soma 1 a variavel controle da vez

            if (verificacao(jogo_da_velha) == 2) { // imprime a mensagem de vitória ou empate
                printf(GREEN "%s venceu." RESET, nomes[0]);
                pontoX++;
            }
            else if(verificacao(jogo_da_velha) == 0) {
                printf(GREEN "%s venceu." RESET, nomes[1]);
                pontoO++;
            }
            else if(verificacao(jogo_da_velha) == 3) {
                printf("O jogo empatou");
            }
            printf("\n");

        } while (verificacao(jogo_da_velha) == 1); // verifica se o jogo deve continuar / fim do código responsável pelo jogo
        
        printf("\n\nDigite 1 para jogar novamente ou 2 para sair: ");
        scanf("%d", &jogar_novamente); // entrada da verificação se deve haver mais um jogo ou não
        while (jogar_novamente != 1 && jogar_novamente != 2) {
            printf(RED "Opção inválida. Digite 1 para jogar novamente ou 2 para sair: " RESET);
            scanf("%d", &jogar_novamente); // entrada da verificação se deve haver mais um jogo ou não
        }

        char resposta[4];
        if (jogar_novamente == 1) { // verifica se são os mesmos jogadores ou não
            printf("São os mesmos jogadores? (sim/nao): ");
            scanf("%s", resposta); // entrada da resposta
            while (strcmp(resposta, "sim") != 0 && strcmp(resposta, "nao") != 0) { // valida a resposta
                printf(RED "Opção inválida. Digite sim caso sejam as mesmas pessoas a jogar, e nao caso não sejam: " RESET);
                scanf("%s", resposta); // entrada da resposta
            }

            if (strcmp(resposta, "sim") == 0) {

            }
            else { // caso não sejam as mesmas pessoas a jogar novamente, imprime o placar final da partida passada e pede a entrada dos nomes dos novos jogadores
                placar(pontoX, pontoO);
                printf("\n");
                printf("Quantas pessoas irão jogar? (1/2): ");
                scanf("%d", &qnt_jogadores);
                while (qnt_jogadores != 1 && qnt_jogadores != 2) {
                    printf(RED "Quantidade de jogadores inválida, insira novamente: " RESET);
                    scanf("%d", &qnt_jogadores);
                }
                entrada_nomes(nomes, qnt_jogadores);
            }
        }
    } while (jogar_novamente == 1); // verifica se deve haver mais um jogo

    placar(pontoX, pontoO);
    printf("\n");

    return 0;
    // FIM DO PROGRAMA
}