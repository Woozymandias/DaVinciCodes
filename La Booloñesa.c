#include <stdio.h>
#include <stdlib.h>

int ifp(char* f){     // ifp = Identificador de fórmula proposicional

    if((f[0] >= 112 && f[0] <= 122) || f[0] == '(' || f[0] == '~'){
        int i = 0;
        int pi = 0,pf = 0;
        while(f[i] != '\0'){
            if(f[i] == '(')
                pi++;
            if(f[i] == ')')
                pf++;
            i++;
        }
        if(pi != pf)
            return 0;
        i = 0;
        while(f[i] != '\0'){
            if(f[i] >= 112 && f[i] <= 122){
                if(f[i+1] != '&' && f[i+1] != '|' && f[i+1] != '>' && f[i+1] != ')' && f[i+1] != '\0')
                    return 0;
                if(f[i+1] == '\0' && i < 2)
                    return 0;
            }else if(f[i] == '~'){
                if((f[i+1] < 112 || f[i+1] > 122) && f[i+1] != '~' && f[i+1] != '(')
                    return 0;
            }else if(f[i] == '&' || f[i] == '|' || f[i] == '>'){
                if((f[i+1] < 112 || f[i+1] > 122) && f[i+1] != '(' && f[i+1] != '~')
                    return 0;
            }else if(f[i] == '('){
                if((f[i+1] < 112 || f[i+1] > 122) && f[i+1] != '~' && f[i+1] != '(')
                    return 0;
            }else if(f[i] == ')'){
                if(f[i+1] != '&' && f[i+1] != '|' && f[i+1] != '>' && f[i+1] != '\0' && f[i+1] != ')')
                    return 0;
                if(f[i+1] == '\0' && i < 2)
                    return 0;
            }else{
                return 0;
            }
            i++;
        }
    }else{
        return 0;
    }
    return 1;

}

void probreak(char* f){

    char* aux = (char*)malloc(11*sizeof(char));
    int i,j,temp,sts;

    for(i=0;i<11;i++)
        aux[i] = 'o';
    i = 0;
    while(f[i] != '\0'){
        if(f[i] >= 112 && f[i] <= 122){
            temp = (int)f[i] - 112;
            if(aux[temp] != f[i])
                aux[temp] = f[i];
        }
        i++;
    }
    aux[i] = '\0';
    i = 0;
    while(aux[i] != '\0' && i < 11){
        if(aux[i] != 'o')
            printf("%c\n",aux[i]);
        i++;
    }

    i = 0;
    while(f[i] != '\0'){
        if(f[i] == '~'){
            j = i + 1;
            while((f[j] < 112 || f[j] > 122) && f[j] == '~'){
                printf("~");
                j++;
            }
            printf("~%c\n",f[j]);
        }
        i++;
    }

    i = 0;
    while(f[i] != '\0'){
        if(f[i] == '&' || f[i] == '|' || f[i] == '>'){
            if((f[i+1] >= 112 && f[i+1] <= 122) && (f[i-1] >= 112 && f[i-1] <= 122)){
                j = 2;
                while(i-j >= 0 && f[i-j] == '~')
                    j++;
                if(i-j < 0){
                    for(temp=i-j+1;temp<i;temp++)
                        printf("~");
                    printf("%c%c%c\n",f[i-1],f[i],f[i+1]);
                }else if(f[i-j] != '('){
                    for(temp=i-j;temp<=i;temp++)
                        printf("~");
                    printf("%c%c%c\n",f[i-1],f[i],f[i+1]);
                }
            }
        }
        i++;
    }

    i = 0;
    while(f[i] != '\0'){
        if(f[i] == '('){
            sts = 0;
            j = i+1;
            temp = 0;
            while(sts != 1){
                if(f[j] == '('){
                    temp++;
                }else if(f[j] == ')' && temp == 0){
                    for(temp=i;temp<=j;temp++)
                        printf("%c",f[temp]);
                    puts("");
                    sts = 1;
                }else if(f[j] == ')' && temp != 0){
                    temp--;
                }
                j++;
            }
        }
        i++;
    }
    printf("%s\n",f);

}

int main(){

    char* form = (char*)malloc(100*sizeof(char));
    scanf(" %100[^\n]",form);
    if(ifp(form) == 1){
        printf("\nFormula valida (proposicional)!\n\n");
        printf("Sub-formulas:\n");
        probreak(form);
        puts("");
    }else{
        printf("Formula invalida!\n");
    }

return 0;
}
