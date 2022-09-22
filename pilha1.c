#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
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

Pilha * RESET(Pilha * pilha){
    pilha = (Pilha *)malloc(sizeof(Pilha));
    pilha->topo = 0;
    pilha->base = 0;
    pilha->limite = MAX;
    return pilha;
}

bool EMPTY(Pilha * pilha){
    return pilha->topo == 0;
}

bool FULL(Pilha * pilha){
    return pilha->topo == MAX;
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
    pilha->pessoas[pilha->topo].idade = 0;
    pilha->pessoas[pilha->topo].nome[0] = '\0';
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
    if(EMPTY(pilha))
        return;
    Pilha * tmp = RESET(tmp);
    Pessoa * ptmp = (Pessoa *)malloc(sizeof(Pessoa));;
    printf("Listando\n");
    while(!EMPTY(pilha)){
        POP(pilha, ptmp);
        PUSH(tmp, ptmp);
        printf("Nome:%s | ", ptmp->nome);
        printf("Idade:%d\n", ptmp->idade);
    }
    while(!EMPTY(tmp)){
        POP(tmp, ptmp);
        PUSH(pilha, ptmp);
    }
    free(tmp);
    free(ptmp);
}

int main(void){
    int opc;
    Pessoa * tmp = (Pessoa *)malloc(sizeof(Pessoa));
    Pilha * pilha = RESET(pilha);
    Pilha * deletaPorNome = RESET(deletaPorNome);
    char deletaNome[30];

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
            scanf("%d", &(tmp->idade));
            getchar();
            PUSH(pilha, tmp);

            break;

        case 1:
            POP(pilha, tmp);
            
            break;

        case 2:
            printf("Digite um nome:");
            scanf("%[^\n]s", deletaNome);
            while(!EMPTY(pilha)){
                POP(pilha, tmp);
                if(!(strcmp(tmp->nome, deletaNome) == 0))
                    PUSH(deletaPorNome, tmp);
            }
            while(!EMPTY(deletaPorNome)){
                POP(deletaPorNome, tmp);
                PUSH(pilha, tmp);
            }

            
            break;

        case 3:
            CLEAR(pilha);
            break;

        case 4:
            Listar(pilha);
            break;

        case 5:
            free(pilha);
            free(tmp);
            free(deletaPorNome);
            exit(0);
            break;
        

        }



    }
    
}