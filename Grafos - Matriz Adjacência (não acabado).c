#include <stdio.h>
#include <stdlib.h>

void carregar_grafo(void){

    FILE* grafo = fopen("entrada.txt","r");
    char linha[10];
    int g[2],l[3];  //g irá guardar numero de vertices e arestas, respectivamente, enquanto L guardará os 3 dados de cada linha
    int i,j,aux,compar; 
    fgets(linha,sizeof(linha),grafo);
    i = 0;
    j = 0;
    aux = 0;
    printf("%s\n",linha);   //teste para verificar se o fgets funcionou
    while(linha[i] != '\0'){    //laço para definição do número de vértices e arestas
        if(linha[i] == ' '){
            g[j] = aux;
            j++;
            aux = 0;
        }else if(((int)linha[i] >= 48) && ((int)linha[i] <= 57)){
            aux = (aux * 10) + ((int)linha[i] - 48);
        }
        i++;
    }
    printf("%d %d\n",g[1],g[2]);    //teste para verificar se as operações no laço de repetição funcionaram
    int** mat = (int**)malloc(g[1]*sizeof(int*));
    for(i=0;i<g[1];i++)
        mat[i] = (int*)malloc(g[1]*sizeof(int));
    for(i=0;i<g[1];i++){
        for(j=0;j<g[1];j++)
            mat[i][j] = 0;  //a matriz é preenchida com 0
    }
    while(fgets(linha,sizeof(linha),grafo) != NULL){    //laço para posicionamento dos pesos na matriz
        i = 0;
        j = 0;
        aux = 0;
        compar = 0;
        while(linha[i] != '\0'){
            if(linha[i] == ' ' && (int)linha != 45){
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
        mat[l[1]-1][l[2]-1] = l[3];
        mat[l[2]-1][l[1]-1] = l[3];
    }
    for(i=0;i<g[1];i++){
        for(j=0;j<g[1];j++)
            printf("%d ",mat[i][j]);
        puts("");
    }
    fclose(grafo);

}

int main(){

    carregar_grafo();

return 0;
}
