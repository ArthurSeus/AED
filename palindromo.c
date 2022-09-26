#include <stdlib.h>
#include <stdio.h>
#include <string.h>


typedef struct{
    char * palavra;
    int base;
    int topo;
    int numletras;
}Pilha;


Pilha * Reset(void){
    Pilha * pilha = (Pilha *)malloc(sizeof(Pilha));
    pilha->base = 0;
    pilha->topo = 0;
    pilha->numletras = 0;
    pilha->palavra = (char *)malloc(sizeof(char));
    return pilha;
}


void PUSH(Pilha * pilha, char letra[1]){
    pilha->numletras = pilha->numletras + 1;
    pilha->palavra = realloc(pilha->palavra, (sizeof(char) * pilha->numletras));
    pilha->palavra[pilha->topo] = letra[0];
    pilha->topo = pilha->topo + 1;
}


void POP(Pilha * pilha, char letra[1]){
    if(pilha->numletras == 0){
        printf("pilha vazia!");
        return;
    }

    pilha->topo = pilha->topo - 1;
    pilha->numletras = pilha->numletras - 1;
    letra[0] = pilha->palavra[pilha->topo];
    pilha->palavra = realloc(pilha->palavra, (sizeof(char) * pilha->numletras));
}

void CLEAR(Pilha * pilha){
    free(pilha->palavra);
    free(pilha);
    
}

int main(void){
    char letra[1];
    char letracmp[1];
    letra[0] = '\0';
    letracmp[0] = '\0';
    int numeroCompara = 0;
    int iguais = 0;

    Pilha * pilha = Reset();
    Pilha * comparar = Reset();

    while(letra[0] != 'x'){
        printf("digite uma letra: ");
        scanf("%c", letra);
        getchar();
        if(letra[0] != 'x'){
            PUSH(pilha, letra);
        }
    }

    if (pilha->numletras % 2 == 1 || pilha->numletras == 0){
        printf("Nao é um palindromo!\n");
        CLEAR(pilha);
        CLEAR(comparar);
        exit(0);
    }

    numeroCompara = (pilha->numletras) / 2;
    
    for(int i = 0; i < numeroCompara;i++){
        POP(pilha, letra);
        PUSH(comparar, letra);
    }
    for(int i = 0; i < numeroCompara;i++){
        POP(pilha, letra);
        POP(comparar, letracmp);
        if(letra[0] == letracmp[0]){
            iguais++;
        }
    }
    if(iguais == numeroCompara){
        printf("é um palindromo!\n");
    }else{
        printf("Nao é um palindromo!\n");
    }

    CLEAR(pilha);
    CLEAR(comparar);

}