#include <stdio.h>
#include <stdlib.h>

void carregar_grafo(void){

    FILE* grafo = fopen("entrada.txt","r");
    char linha[10];
    int g[2],l[3];
    int i,j,aux,compar;
    fgets(linha,sizeof(linha),grafo);
    i = 0;
    j = 0;
    aux = 0;
    printf("%s",linha);
    while(linha[i] != '\0'){
        if(linha[i] == ' '){
            g[j] = aux;
            j++;
            aux = 0;
        }else if((int)linha[i] >= 48 && (int)linha[i] <= 57){
            aux = (aux * 10) + ((int)linha[i] - 48);
        }
        i++;
    }
    printf("%d %d\n",g[0],g[1]);
    int** mat = (int**)malloc(g[0]*sizeof(int*));
    for(i=0;i<g[0];i++)
        mat[i] = (int*)malloc(g[0]*sizeof(int));
    for(i=0;i<g[0];i++){
        for(j=0;j<g[0];j++)
            mat[i][j] = 0;
    }
    while(fgets(linha,sizeof(linha),grafo) != NULL){
        i = 0;
        j = 0;
        aux = 0;
        compar = 0;
        while(linha[i] != '\0'){
            if(linha[i] == ' '){
                if(compar == 1)
                    aux = aux*(-1);
                l[j] = aux;
                j++;
                aux = 0;
            }else if(((int)linha[i] >= 48) && ((int)linha[i] <= 57)){
                aux = (aux * 10) + ((int)linha[i] - 48);
            }else if((int)linha[i] == 45){
                compar = 1;
            }
            i++;
        }
        mat[l[0]-1][l[1]-1] = l[2];
        mat[l[1]-1][l[0]-1] = l[2];
    }
    for(i=0;i<g[0];i++){
        for(j=0;j<g[0];j++)
            printf("%d ",mat[i][j]);
        puts("");
    }
    fclose(grafo);

}

int main(){

    carregar_grafo();

return 0;
}
