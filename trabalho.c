#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// typedef struct
// {
//     char nome[10];
//     int idade;
//     long telefone;
//     void * prox;
//     void * anterior;
// }SPessoa;

// typedef struct 
// {
//     SPessoa pessoa;
//     struct SNodo * prox;
// }SNodo;

// typedef struct 
// {
//     SNodo * pFirst;
//     int numeroPessoas;
// }SLista;


void * criaSentinela(void){
    void * sentinela = (void *)malloc(sizeof(int) * 2);
    int * elementos = (int *)sentinela;
    int ** pont = (int **)(sentinela + sizeof(int));
    *elementos = 0;
    *pont = NULL;
    return sentinela;
}


void * criaNodo(void * sentinela, int * idade, long * telefone, char * nome, int * var)
{
	void * start = (void *)malloc((sizeof(int)) + (sizeof(char) * 11) + (sizeof(int)) + (sizeof(long)) + (sizeof(int) * 2));
    int * pidade = (int *)(start + (sizeof(int)) + (sizeof(char) * 11));
    long * ptelefone =  (long *)(start + (sizeof(int)) + (sizeof(char) * 11) + (sizeof(int)));
    char * pnome = (char *)(start + (sizeof(int)));
    int * pnumElementos = (int *)start;
    int * numSent = (int *)sentinela;
    for(*var = 0; *var < 11; *var = *var + 1){
        pnome[*var] = nome[*var];
    }
    *pidade = *idade;
    *ptelefone = *telefone;
    *pnumElementos = *numSent;

	return start;
}



void inserir(void * nodo, void * sentinela){
    int * elementos = (int *)sentinela;
    int ** pont = (int **)(sentinela + sizeof(int));

    int * apontanodo = (int *)nodo;

    if(*elementos == 1){
        pont = &apontanodo;
        *elementos = *elementos + 1;
        
        return;
    }
    
    apontanodo = (int *)(pont + ((sizeof(int)) + (sizeof(char) * 11) + (sizeof(int)) + (sizeof(long)) + (sizeof(int))));
    pont = &apontanodo;
    void * tracer; //sentinela para o primeiro;
    //while((*tracer != NULL) && strcmp(*tracer, newp -> item) < 1)
	// {
	// 	tracer = &(*tracer)->next;
	// }
    
    // if(sent->numeroPessoas > 0){
    //     tracer->prox = newN;
    // }
    
    // newN->pessoa = *pessoa;
    // *elementos = *elementos + 1;
    
}
    // char ** nome;
    // char * pnome = (char *)(nodo + sizeof(int));
    // nome = &pnome;
// void listar(SLista * sent){
//     SNodo * tracer = sent->pFirst;
//     printf("Lista tem %d usuarios:\n", sent->numeroPessoas);
//     while(tracer != NULL){
//         printf("Nome:%s|", tracer->pessoa.nome);
//         printf("Idade:%d\n", tracer->pessoa.idade);
//         tracer = tracer->prox;
//     }
// }

// void remover(SLista * sent, SPessoa * pessoa){

//     if(sent->numeroPessoas == 0){
//         return;
//     }

//     SNodo * excluir;
//     SNodo * tracer = sent->pFirst;
//     SNodo * fronttracer = sent->pFirst;
//     if(strcmp(tracer->pessoa.nome, pessoa->nome) == 0){
//         excluir= sent->pFirst;
//         sent->pFirst = tracer->prox;
//         free(excluir);
//         sent->numeroPessoas = sent->numeroPessoas - 1;
//         return;
//     }

//     while(fronttracer != NULL){
//         fronttracer = fronttracer->prox;

//         if(strcmp(fronttracer->pessoa.nome, pessoa->nome) == 0){
//             excluir = fronttracer;
//             tracer->prox = fronttracer->prox;
//             free(excluir);
//             sent->numeroPessoas = sent->numeroPessoas - 1;
//             return;
//         }

//         tracer = tracer->prox;
//     }
        
// }


// void clear(SLista * sent){

//     SNodo * excluir;
//     SNodo * tracer = sent->pFirst;

//     while(tracer != NULL){
//         excluir = tracer;
//         free(excluir);
//         tracer = tracer->prox;
//     }
        
// }


int main(void){
    void * pBuffer = (void *)malloc((sizeof(int) * 3) + (sizeof(char) * 11) + sizeof(long) + sizeof(int));
    int * opc = (int *)pBuffer;
    int * var1 = (int *)(pBuffer + sizeof(int));
    int * idade = (int *)(pBuffer + (sizeof(int) * 3) + (sizeof(char) * 10) + sizeof(long));
    long * telefone =  (long *)(pBuffer + (sizeof(int) * 3) + (sizeof(char) * 10));
    char * nome = (char *)(pBuffer + (sizeof(int) * 3));
    void * sentinela = criaSentinela();

    *idade = 1;
    *telefone = 4567;
    nome[0] = 'a';
    nome[1] = 'r';
    nome[2] = 't';
    nome[3] = 'h';
    nome[4] = '\0';
    void * nodo = criaNodo(sentinela, idade, telefone, nome, var1);
    char * abc = (char*)(nodo + sizeof(int));
    //printf("%s\n", abc);
    inserir(nodo, sentinela);
    inserir(nodo, sentinela);
    char * prox = (char *)(sentinela + sizeof(int));
    printf("%s\n", prox);
    //printf("%d\n", *prox);
    //printf("%d", );
    // adicionar(tmp, sent);
    // tmp->idade = 2;
    // tmp->nome[0] = 'b';
    // adicionar(tmp, sent);
    //listar(sent);
    // tmp->nome[0] = 'a';
    // remover(sent, tmp);
    // listar(sent);
    // for (;;){

    //     printf("Menu\n");
    //     printf("[1]adiciona pessoa\n");
    //     printf("[2]remove pessoa\n");
    //     printf("[3]lista pessoas\n");
    //     printf("[4]Buscar por usuario\n");
    //     printf("[5]Sair\n");
    //     printf("Sua escolha: ");
    //     scanf("%d", opc);
    //     getchar();


    //     switch (*opc)
    //     {
    //     case 1:
    //         printf("Digite o nome: ");
    //         scanf("%[^\n]s", nome);
    //         printf("Digite a idade: ");
    //         scanf("%d", idade);
    //         getchar();
    //         printf("Digite o telefone: ");
    //         scanf("%ld", telefone);
    //         getchar();
    //         //inserir(sentinela, criaNodo(nome, idade, telefone));
    //         break;

        // case 2:
        //     printf("Digite o nome: ");
        //     scanf("%[^\n]s", tmp->nome);
        //     remover(sent, tmp); 
        //     break;

        // case 3:
        //     listar(sent);
        //     break;

        // case 4:
        //     clear(sent);
        //     free(sent);
        //     free(tmp);
        //     exit(0);
        //     break;     

    //     }

    // }
}