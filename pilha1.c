#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 10
//const int MAX = 10;

typedef struct{
    char nome[30];
    int idade;
}Pessoa;
 
typedef struct{
    Pessoa pessoas[MAX];
    int topo;
    int base;
    int limite;
}Pilha;


// Iniciar ED (RESET)
// •
// Inserir elemento (PUSH)
// •
// Remover elemento (POP)
// •
// Testa se ED está vazia (EMPTY)
// •
// Apaga todos os elementos (CLEAR)

void RESET(Pilha * pilha){
    //pilha->pessoas = NULL;
    pilha->topo = 0;
    pilha->base = 0;
    pilha->limite = MAX;
}

bool EMPTY(Pilha * pilha){
    return pilha->topo = 0;
}

bool FULL(Pilha * pilha){
    return pilha->topo = MAX;
}

void CLEAR(Pilha * pilha){
    if (EMPTY(pilha)){
        return;
    }
    
    pilha->topo = 0;
    // while (pilha->topo != 0){
    //     pilha->pessoas[pilha->topo] = NULL;
    //     pilha->topo--;
        
    // }
    // pilha->pessoas[pilha->base] = NULL;
    // return true;
}

void POP(Pilha *pilha, Pessoa *pessoa){
    if (EMPTY(pilha))
        return;
    
    pilha->topo--;

    *pessoa = pilha->pessoas[pilha->topo];
    printf("%d", pessoa->idade);
}

bool PUSH(Pilha *pilha, Pessoa *pessoa){
    if (!FULL(pilha)){
        pilha->pessoas[pilha->topo] = *pessoa;
        pilha->topo++;
        return true;
    }
    else {
        return false;
    }

}

void Listar(Pilha * pilha){
    Pilha * tmp;
    Pessoa * ptmp;
    ptmp = (Pessoa *)malloc(sizeof(Pessoa));
    tmp = (Pilha *)malloc(sizeof(Pilha));
    RESET(tmp);
    printf("Listando\n");
        POP(pilha, ptmp);
        PUSH(tmp, ptmp);
        printf("%s", ptmp->nome);
        printf("%d", ptmp->idade);
    //while(!EMPTY(pilha)){

        
    }



int main(void){
    int opc;
    Pilha * pilha;
    Pessoa * tmp;
    tmp = (Pessoa *)malloc(sizeof(Pessoa));
    pilha = (Pilha *)malloc(sizeof(Pilha));
    RESET(pilha);

    for (;;){

        printf("Menu\n");
        printf("0 para inserir\n");
        printf("1 deleta pessoa do topo\n");
        printf("2 deleta pessoa por nome\n");
        printf("3 limpa a lista\n");
        printf("4 lista pessoas\n");
        printf("5 Sair\n");
        printf("Sua escolha: ");
        scanf("%d", &opc);
        getchar();


        switch (opc)
        {
        case 0:
            printf("Digite um nome:");
            scanf("%[^\n]s", tmp->nome);
            printf("Digite a idade:");
            scanf("%d", &tmp->idade);
            getchar();
            printf("%d\n", tmp->idade);
            printf("%s\n", tmp->nome);
            PUSH(pilha, tmp);

            break;

        case 1:
            // tmp->idade = 43;
            // //*tmp = pilha->pessoas[0];
            // printf("%d\n", tmp->idade);
            
            break;

        case 2:
            break;

        case 3:
            break;

        case 4:
            Listar(pilha);
            break;

        case 5:
            break;
        

        }



    }
    
}