#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
// \n
char jogo[3][3];
char j1, j2, x, o;
int l, c; //auxiliares para linhas e colunas da matriz
int fim = 0;
char continua;
int opc;

int jogoinicial()
{
    jogo[0][0] = '1'; jogo[0][1] = '2'; jogo[0][2] = '3';
    jogo[1][0] = '4'; jogo[1][1] = '5'; jogo[1][2] = '6';
    jogo[2][0] = '7'; jogo[2][1] = '8'; jogo[2][2] = '9';
}

void jogotabuleiro()
{
    printf("||=================================||\n");
    printf("||         Jogador 1 (%c)           ||\n", j1);
    printf("||              vs                 ||\n");
    printf("||         Jogador 2 (%c)           ||\n", j2);
    printf("||                                 ||\n");
    printf("||                                 ||\n");
    printf("||           |     |               ||\n");
    printf("||        %c  |  %c  |  %c            ||\n",jogo[0][0], jogo[0][1], jogo[0][2]);
    printf("||           |     |               ||\n");
    printf("||      -----------------          ||\n");
    printf("||           |     |               ||\n");
    printf("||        %c  |  %c  |  %c            ||\n",jogo[1][0], jogo[1][1], jogo[1][2]);
    printf("||           |     |               ||\n");
    printf("||      -----------------          ||\n");
    printf("||           |     |               ||\n");
    printf("||        %c  |  %c  |  %c            ||\n",jogo[2][0], jogo[2][1], jogo[2][2]);
    printf("||           |     |               ||\n");
    printf("||                                 ||\n");
    printf("||                                 ||\n");
    printf("||=================================||\n");
}

void jogador1()
{
        int erro;
        printf("Jogador 1, diga a linha e coluna da casa que deseja preencher. ");
        printf("\nLinha(1-3): ");
        scanf("%d%*c", &l);
        printf("Coluna (1-3): ");
        scanf("%d%*c", &c);

        if(l < 1 || l > 3 || c < 1 || c > 3){
            erro = 1;
            do{
                printf("Coluna e/ou linha inválidas. Jogador 1, coloque uma casa válida.");
                printf("\nLinha(1-3): ");
                scanf("%d%*c", &l);
                printf("Coluna (1-3): ");
                scanf("%d%*c", &c);

                if(l < 1 || l > 3 || c < 1 || c > 3){
                    erro = 1;
                } else if(jogo[l-1][c-1] == 'X' || jogo[l-1][c-1] == 'O'){
                    erro = 1;
                }else if(jogo[l-1][c-1] != 'X' && jogo[l-1][c-1] != 'O'){
                    erro = 0;
                }

            }while (erro == 1);
        } else if (jogo[l-1][c-1] == 'X' || jogo[l-1][c-1] == 'O'){
            erro = 1;
            do {
                printf("Coluna e/ou linha inválidas. Jogador 1, coloque uma casa válida.");
                printf("\nLinha(1-3): ");
                scanf("%d%*c", &l);
                printf("Coluna (1-3): ");
                scanf("%d%*c", &c);

                if (jogo[l-1][c-1] != 'X' && jogo[l-1][c-1] != 'O'){
                    erro = 0;
                }
            }while (erro == 1);
        }

        jogo[l-1][c-1] = j1;

}

void jogador2()
{
        int erro;
        printf("Jogador 2, diga a linha e coluna da casa que deseja preencher. ");
        printf("\nLinha(1-3): ");
        scanf("%d%*c", &l);
        printf("Coluna (1-3): ");
        scanf("%d%*c", &c);

        if(l < 1 || l > 3 || c < 1 || c > 3){
            erro = 1;
            do{
                printf("Coluna e/ou linha inválidas. Jogador 2, coloque uma casa válida.");
                printf("\nLinha(1-3): ");
                scanf("%d%*c", &l);
                printf("Coluna (1-3): ");
                scanf("%d%*c", &c);

                if(l < 1 || l > 3 || c < 1 || c > 3){
                    erro = 1;
                } else if(jogo[l-1][c-1] == 'X' || jogo[l-1][c-1] == 'O'){
                    erro = 1;
                }else if(jogo[l-1][c-1] != 'X' && jogo[l-1][c-1] != 'O'){
                    erro = 0;
                }

            }while (erro == 1);
        } else if (jogo[l-1][c-1] == 'X' || jogo[l-1][c-1] == 'O'){
            erro = 1;
            do {
                printf("Coluna e/ou linha inválidas. Jogador 2, coloque uma casa válida.");
                printf("\nLinha(1-3): ");
                scanf("%d%*c", &l);
                printf("Coluna (1-3): ");
                scanf("%d%*c", &c);

                if(l < 1 || l > 3 || c < 1 || c > 3){
                    erro = 1;
                } else if(jogo[l-1][c-1] == 'X' || jogo[l-1][c-1] == 'O'){
                    erro = 1;
                }else if(jogo[l-1][c-1] != 'X' && jogo[l-1][c-1] != 'O'){
                    erro = 0;
                }
            }while (erro == 1);
        }

        jogo[l-1][c-1] = j2;

}

void verificaDiag()
{
    if (jogo[0][0] == jogo[1][1] && jogo[1][1] == jogo[2][2]){
        if(jogo[0][0] == 'X'){
            vitoria();
            printf("|| - Vitória do Jogador %c          ||\n", x);
            printf("||                                 ||\n");
            printf("||- = * = - || - ( ) - || - = * = -||\n");
            fim = 1;
        } else {
            vitoria();
            printf("|| - Vitória do Jogador %c          ||\n", o);
            printf("||                                 ||\n");
            printf("||- = * = - || - ( ) - || - = * = -||\n");
            fim = 1;
        }
    }

    if(jogo[0][2] == jogo[1][1] && jogo[1][1] == jogo[2][0]){
        if(jogo[0][0] == 'X'){
            vitoria();
            printf("|| - Vitória do Jogador %c          ||\n", x);
            printf("||                                 ||\n");
            printf("||- = * = - || - ( ) - || - = * = -||\n");
            fim = 1;
        } else {
            vitoria();
            printf("|| - Vitória do Jogador %c          ||\n", o);
            printf("||                                 ||\n");
            printf("||- = * = - || - ( ) - || - = * = -||\n");
            fim = 1;
        }
    }
}

void verificaLinha()
{
    if(jogo[0][0] == jogo[0][1] && jogo[0][1] == jogo[0][2]){
        if(jogo[0][0] == 'X'){
            vitoria();
            printf("|| - Vitória do Jogador %c          ||\n", x);
            printf("||                                 ||\n");
            printf("||- = * = - || - ( ) - || - = * = -||\n");
        } else {
            vitoria();
            printf("|| - Vitória do Jogador %c          ||\n", o);
            printf("||                                 ||\n");
            printf("||- = * = - || - ( ) - || - = * = -||\n");
        }
        fim = 1;
    };
    if(jogo[1][0] == jogo[1][1] && jogo[1][1] == jogo[1][2]){
        if(jogo[1][0] == 'X'){
            vitoria();
            printf("|| - Vitória do Jogador %c          ||", x);
            printf("||                                 ||\n");
            printf("||- = * = - || - ( ) - || - = * = -||\n");
        } else {
            vitoria();
            printf("|| - Vitória do Jogador %c          ||\n", o);
            printf("||                                 ||\n");
            printf("||- = * = - || - ( ) - || - = * = -||\n");
        }
        fim = 1;
    }
    if(jogo[2][0] == jogo[2][1] && jogo[2][1] == jogo[2][2]){
        if(jogo[2][0] == 'X'){
            vitoria();
            printf("|| - Vitória do Jogador %c          ||", x);
            printf("||                                 ||\n");
            printf("||- = * = - || - ( ) - || - = * = -||\n");
        } else {
            vitoria();
            printf("|| - Vitória do Jogador %c          ||\n", o);
            printf("||                                 ||\n");
            printf("||- = * = - || - ( ) - || - = * = -||\n");
        }
        fim = 1;
    }
}

void verificaCol()
{
    if(jogo[0][0] == jogo[1][0] && jogo[1][0] == jogo[2][0]){
        if(jogo[0][0] == 'X'){
            vitoria();
            printf("|| - Vitória do Jogador %c          ||", x);
            printf("||                                 ||\n");
            printf("||- = * = - || - ( ) - || - = * = -||\n");
        } else {
            vitoria();
            printf("|| - Vitória do Jogador %c          ||\n", o);
            printf("||                                 ||\n");
            printf("||- = * = - || - ( ) - || - = * = -||\n");
        }
        fim = 1;
    }
    if(jogo[0][1] == jogo[1][1] && jogo[1][1] == jogo[2][1]){
        if(jogo[0][1] == 'X'){
            vitoria();
            printf("|| - Vitória do Jogador %c          ||", x);
            printf("||                                 ||\n");
            printf("||- = * = - || - ( ) - || - = * = -||\n");
        } else {
            vitoria();
            printf("|| - Vitória do Jogador %c          ||\n", o);
            printf("||                                 ||\n");
            printf("||- = * = - || - ( ) - || - = * = -||\n");
        }
        fim = 1;
    }
    if(jogo[0][2] == jogo[1][2] && jogo[1][2] == jogo[2][2]){
        if(jogo[0][2] == 'X'){
            vitoria();
            printf("|| - Vitória do Jogador %c          ||\n", x);
            printf("||                                 ||\n");
            printf("||- = * = - || - ( ) - || - = * = -||\n");
        } else {
            vitoria();
            printf("|| - Vitória do Jogador %c          ||\n", o);
            printf("||                                 ||\n");
            printf("||- = * = - || - ( ) - || - = * = -||\n");
        }
        fim = 1;
    }
}

void vitoria()
{
    printf("||- = * = - Jogo da Velha - = * = -||\n");
    printf("||                                 ||\n");
    printf("||Feito por: João Pedro Seiji Onaka||\n");
    printf("||                                 ||\n");
    printf("||- = * = - || - ( ) - || - = * = -||\n");
    jogotabuleiro();
    printf("||- = * = - Final de Jogo - = * = -||\n");
    printf("||             PARABÉNS!           ||\n");
    printf("||                                 ||\n");
}

int main()
{
    setlocale(LC_ALL, "Portuguese");

    jogoinicial();
    printf("||- = * = - Jogo da Velha - = * = -||\n");
    printf("||                                 ||\n");
    printf("||Feito por: João Pedro Seiji Onaka||\n");
    printf("||                                 ||\n");
    printf("||- = * = - || - ( ) - || - = * = -||\n\n");

    printf("Jogador 1 irá jogar com:\n[1] X\n[2] O\nOpção: ");
    scanf("%d%*c", &opc);
    if (opc == 1){
        j1 = 'X';
        x = '1';
        j2 = 'O';
        o = '2';
    } else if (opc == 2){
        j1 = 'O';
        o = '1';
        j2 = 'X';
        x = '2';
    }

    system("cls");

    do{

        jogotabuleiro();
        jogador1();
        system("cls");

        verificaDiag();
        verificaLinha();
        verificaCol();

        if(fim == 0){
        jogotabuleiro();
        jogador2();
        system("cls");

        verificaDiag();
        verificaLinha();
        verificaCol();
        }

    }while (fim == 0);

    return 0;
}
