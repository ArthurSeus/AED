#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char nome[10];
    int idade;
}SPessoa;

typedef struct 
{
    SPessoa pessoa;
    struct SNodo * prox;
}SNodo;

typedef struct 
{
    SNodo * pFirst;
    int numeroPessoas;
}SLista;


SNodo * criaNodo(void)
{
	SNodo * start;
	start = (SNodo *)malloc(sizeof(SNodo));
	start->prox = NULL;
	return start;
}


void adicionar(SPessoa * pessoa, SLista * sent){
    SNodo * newN = criaNodo();
    if(sent->numeroPessoas==0){
        sent->pFirst = newN;
    }
    
    SNodo * tracer = sent->pFirst;
    for(tracer; tracer->prox != NULL; tracer = tracer->prox);
    
    if(sent->numeroPessoas > 0){
        tracer->prox = newN;
    }
    //tracer->prox = newN;
    newN->pessoa = *pessoa;
    sent->numeroPessoas = sent->numeroPessoas + 1;
    //list = newN;
}

void listar(SLista * sent){
    SNodo * tracer = sent->pFirst;
    printf("Lista tem %d usuarios:\n", sent->numeroPessoas);
    while(tracer != NULL){
        printf("Nome:%s|", tracer->pessoa.nome);
        printf("Idade:%d\n", tracer->pessoa.idade);
        tracer = tracer->prox;
    }
}

void remover(SLista * sent, SPessoa * pessoa){

    if(sent->numeroPessoas == 0){
        return;
    }

    SNodo * excluir;
    SNodo * tracer = sent->pFirst;
    SNodo * fronttracer = sent->pFirst;
    if(strcmp(tracer->pessoa.nome, pessoa->nome) == 0){
        excluir= sent->pFirst;
        sent->pFirst = tracer->prox;
        free(excluir);
        sent->numeroPessoas = sent->numeroPessoas - 1;
        return;
    }

    while(fronttracer != NULL){
        fronttracer = fronttracer->prox;

        if(strcmp(fronttracer->pessoa.nome, pessoa->nome) == 0){
            excluir = fronttracer;
            tracer->prox = fronttracer->prox;
            free(excluir);
            return;
        }

        tracer = tracer->prox;
        }
        
    }


void clear(SLista * sent){

    SNodo * excluir;
    SNodo * tracer = sent->pFirst;

    while(tracer != NULL){
        excluir = tracer;
        free(excluir);
        tracer = tracer->prox;
    }
        
}


int main(void){
    int opc;
    SLista * sent = (SLista *)malloc(sizeof(SLista));
    SPessoa * tmp = (SPessoa *)malloc(sizeof(SPessoa));

    for (;;){

        printf("Menu\n");
        printf("[1]adiciona pessoa\n");
        printf("[2]remove pessoa\n");
        printf("[3]lista pessoas\n");
        printf("[4]Sair\n");
        //printf("[5]adiciona pessoa\n");
        printf("Sua escolha: ");
        scanf("%d", &opc);
        getchar();


        switch (opc)
        {
        case 1:
            printf("Digite o nome: ");
            scanf("%[^\n]s", tmp->nome);
            printf("Digite a idade: ");
            scanf("%d", &(tmp->idade));
            getchar();
            adicionar(tmp, sent);
            break;

        case 2:
            printf("Digite o nome: ");
            scanf("%[^\n]s", tmp->nome);
            remover(sent, tmp); 
            break;

        case 3:
            listar(sent);
            break;

        case 4:
            clear(sent);
            free(sent);
            free(tmp);
            exit(0);
            break;     

        }

    }
}