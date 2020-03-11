#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

char** plataforma(){

    int i,j,mint[5][5];
    char** mat = (char**)malloc(5*sizeof(char*));
    for(i=0;i<5;i++)
        mat[i] = (char*)malloc(5*sizeof(char));
    for(i=0;i<5;i++){
        for(j=0;j<5;j++){
            if((i == 0 || i == 2 || i == 4) && (j == 1 || j == 3)){
                mat[i][j] = '|';
            }else if((j == 0 || j == 2 || j == 4) && (i == 1 || i == 3)){
                mat[i][j] = '-';
            }else if(i == 1){
                if(j == 1 || j == 3)
                    mat[i][j] = '+';
            }else if(j == 1){
                if(i == 1 || i == 3)
                    mat[i][j] = '+';
            }else if(i == 3 && j == 3){
                mat[i][j] = '+';
            }else{
                mat[i][j] = 0;
            }
        }
    }
    return mat;

}

void imprimir_plataforma(char** mat){

    int i,j;
    puts("");
    for(i=0;i<5;i++){
        printf(" ");
        for(j=0;j<5;j++)
            printf("%c",mat[i][j]);
        puts("");
    }
    puts("");

}

int jogada(char** mat,int x,int y,int player){

    if(x < 1 || x > 3 || y < 1 || y > 3)
        return 0;
    if(x == 1)
        x = 0;
    else if(x == 3)
        x = 4;
    if(y == 1)
        y = 0;
    else if(y == 3)
        y = 4;
    if(mat[x][y] == 0){
        if(player == 1)
            mat[x][y] = 'o';
        else
            mat[x][y] = 'x';
        return 1;
    }else
        return 0;

}

char status(char** m){

    int i,j,st,vazio = 0;
    for(i=0;i<5;i=i+2){
        st = 0;
        for(j=0;j<5;j=j+2){
            if(m[i][j] == 'o')
                st++;
            if(m[i][j] == 'x')
                st--;
            if(m[i][j] == 0)
                vazio++;
        }
        if(st == 3)
            return 'o';
        if(st == -3)
            return 'x';
    }
    for(i=0;i<5;i=i+2){
        st = 0;
        for(j=0;j<5;j=j+2){
            if(m[j][i] == 'o')
                st++;
            if(m[j][i] == 'x')
                st--;
        }
        if(st == 3)
            return 'o';
        if(st == -3)
            return 'x';
    }
    if(m[0][0] == 'o' && m[2][2] == 'o' && m[4][4] == 'o')
        return 'o';
    if(m[0][4] == 'o' && m[2][2] == 'o' && m[4][0] == 'o')
        return 'o';
    if(m[0][0] == 'x' && m[2][2] == 'x' && m[4][4] == 'x')
        return 'x';
    if(m[0][4] == 'x' && m[2][2] == 'x' && m[4][0] == 'x')
        return 'x';
    if(vazio == 0)
        return 'n';
    else
        return 'y';

}

int main(){

    setlocale(LC_ALL,"portuguese");
    int i,j;
    char op;
    char** mat = plataforma();
    int t = mat[0][0];
    imprimir_plataforma(mat);

    do{
        system("Cls");
        printf("Iniciar jogo? (y/n): ");
        scanf(" %c",&op);
    }while(op != 'y' && op != 'Y' && op != 'n' && op != 'N');

    while(op == 'y' || op == 'Y'){
        do{
            int x;
            do{
                system("Cls");
                imprimir_plataforma(mat);
                printf("Jogador 1(o) => escolha uma posição válida (LxC): ");
                scanf("%d%d",&i,&j);
                x = jogada(mat,i,j,1);
            }while(x == 0);
            if(status(mat) == 'y'){
                do{
                    system("Cls");
                    imprimir_plataforma(mat);
                    printf("Jogador 2(x) => escolha uma posição válida (LxC): ");
                    scanf("%d%d",&i,&j);
                    x = jogada(mat,i,j,2);
                }while(x == 0);
            }
        }while(status(mat) == 'y');

        char st = status(mat);
        system("Cls");
        imprimir_plataforma(mat);
        if(st == 'o')
            printf("O jogador 1 é o vencedor!\n");
        else if(st == 'x')
            printf("O jogador 2 é o vencedor!\n");
        else
            printf("Empate!\n");
        system("pause");

        do{
            system("Cls");
            imprimir_plataforma(mat);
            printf("Continuar jogando? (y/n): ");
            scanf(" %c",&op);
        }while(op != 'y' && op != 'Y' && op != 'n' && op != 'N');
        if(op == 'y' || op == 'Y')
            mat = plataforma();
    }

    system("Cls");
    printf("Game over!\n");
    system("pause");

return 0;
}
