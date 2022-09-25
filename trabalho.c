#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void * criaSentinela(void){
    void * sentinela = (void *)malloc(sizeof(int) + sizeof(int*));
    int * elementos = (int *)sentinela;
    int ** pont = (int **)(sentinela + sizeof(int));
    *elementos = 0;
    *pont = NULL;
    return sentinela;
}


void * criaNodo(int * idade, long * telefone, char * nome, int * var, void * sentinela)
{
	void * start = (void *)malloc((sizeof(int)) + (sizeof(char) * 11) + (sizeof(int)) + (sizeof(long)) + (sizeof(void**) * 2));
    int * pidade = (int *)(start + (sizeof(int)) + (sizeof(char) * 11));
    long * ptelefone =  (long *)(start + (sizeof(int)) + (sizeof(char) * 11) + (sizeof(int)));
    char * pnome = (char *)(start + (sizeof(int)));
    int * pnumElementos = (int *)start;
    int * elementos = (int*)sentinela;
    void ** pAnt = (void **)(start + ((sizeof(int)) + (sizeof(char) * 11) + (sizeof(int)) + (sizeof(long))));
    void ** pProx = (void **)(start + ((sizeof(int)) + (sizeof(char) * 11) + (sizeof(int)) + (sizeof(long)) + (sizeof(void*))));
    for(*var = 0; *var < 11; *var = *var + 1){
        pnome[*var] = nome[*var];
    }
    
    *pidade = *idade;
    *ptelefone = *telefone;
    *pnumElementos = *elementos;
    *pAnt = NULL;
    *pProx = NULL;

	return start;
}


void inserir(int * var, void * sentinela, int * idade, long * telefone, char * nome){

    int * elementos = (int *)sentinela;//numero de elementos
    void * nodo = criaNodo(idade, telefone, nome, var, sentinela);
    void ** pont = (void **)(sentinela + sizeof(int));//aponta
    void ** pProxOld = NULL;
    void ** pProxNew = NULL;
    void ** pAntOld = NULL;
    void ** pAntNew = NULL;

    if(*elementos == 0){
        *pont = nodo;
        *elementos = *elementos + 1;
        return;
    }
    void ** tracer = pont;
    char * nomeNovo = (char *)(nodo + sizeof(int));
    char * nomeVelho = (char *)(*tracer + sizeof(int));

    *var = 0;

    while((*var < *elementos) && (strcmp(nomeVelho, nomeNovo) < 1)){
        tracer = (*tracer + ((sizeof(int)) + (sizeof(char) * 11) + (sizeof(int)) + (sizeof(long)) + (sizeof(void*))));
        nomeVelho = (char *)(*tracer + sizeof(int));
        *var = *var + 1;
    }

    if(*var == 0){//mudar o sentinela
        pProxNew = (void **)(nodo + ((sizeof(int)) + (sizeof(char) * 11) + (sizeof(int)) + (sizeof(long)) + (sizeof(void*))));
        pAntOld = (void **)(*tracer + ((sizeof(int)) + (sizeof(char) * 11) + (sizeof(int)) + (sizeof(long))));
        *pProxNew = *tracer;
        *pAntOld = nodo;
        *pont = nodo;
        *elementos = *elementos + 1;
        return ;
    }

    void ** backTracer = (*tracer + ((sizeof(int)) + (sizeof(char) * 11) + (sizeof(int)) + (sizeof(long))));
    pAntOld = (void **)(*tracer + ((sizeof(int)) + (sizeof(char) * 11) + (sizeof(int)) + (sizeof(long))));
    *pAntOld = nodo;

    pProxNew = (void **)(nodo + ((sizeof(int)) + (sizeof(char) * 11) + (sizeof(int)) + (sizeof(long)) + sizeof(void*)));
    *pProxNew = *tracer;

    pAntNew = (void **)(nodo + ((sizeof(int)) + (sizeof(char) * 11) + (sizeof(int)) + (sizeof(long))));
    *pAntNew = *backTracer;

    pProxOld = (void **)(*backTracer + ((sizeof(int)) + (sizeof(char) * 11) + (sizeof(int)) + (sizeof(long)) + (sizeof(void*)))); 
    *pProxOld = nodo;

    *elementos = *elementos + 1;
    return ;
}


void listar(int * var, void * sentinela){
    int * elementos = (int *)sentinela;//numero de elementos
    void ** pont = (void **)(sentinela + sizeof(int));//aponta
    void ** tracer = pont;
    char * pnome = (char *)(*tracer + sizeof(int));
    int * pidade = (int *)(*tracer  + (sizeof(int)) + (sizeof(char) * 11));
    long * ptelefone =  (long *)(*tracer  + (sizeof(int)) + (sizeof(char) * 11) + (sizeof(int)));

    printf("Lista tem %d pessoas:\n", *elementos);
    for(*var = 0; *var < *elementos; *var = *var + 1){
        printf("Nome:%s|", pnome);
        printf("Idade:%d|", *pidade);
        printf("Telefone:%ld\n", *ptelefone);
        tracer = (*tracer + ((sizeof(int)) + (sizeof(char) * 11) + (sizeof(int)) + (sizeof(long)) + (sizeof(void*))));
        pidade = (int *)(*tracer  + ((sizeof(int)) + (sizeof(char) * 11)));
        ptelefone = (long *)(*tracer  + (sizeof(int)) + (sizeof(char) * 11) + (sizeof(int)));
        pnome = (char *)(*tracer  + (sizeof(int)));
    }
}

// void remover(int * var, void * sentinela){
//     int * elementos = (int *)sentinela;//numero de elementos
//     void ** pont = (void **)(sentinela + sizeof(int));//aponta
    // void ** tracer = pont;
    // char * pnome = (char *)(*tracer + sizeof(int));
    // int * pidade = (int *)(*tracer  + (sizeof(int)) + (sizeof(char) * 11));
    // long * ptelefone =  (long *)(*tracer  + (sizeof(int)) + (sizeof(char) * 11) + (sizeof(int)));

    // if(*elementos == 0){
    //     return;
    // }

    // while((*var < *elementos) && (strcmp(nomeVelho, nomeNovo) < 1)){



    // }
    // SNodo * excluir;
    // SNodo * tracer = sent->pFirst;
    // SNodo * fronttracer = sent->pFirst;
    // if(strcmp(tracer->pessoa.nome, pessoa->nome) == 0){
    //     excluir= sent->pFirst;
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
        



int main(void){
    void * pBuffer = (void *)malloc((sizeof(int) * 2) + (sizeof(char) * 11) + sizeof(long) + sizeof(int));
    int * opc = (int *)pBuffer;
    int * var1 = (int *)(pBuffer + sizeof(int));
    int * idade = (int *)(pBuffer + (sizeof(int) * 2) + (sizeof(char) * 10) + sizeof(long));
    long * telefone =  (long *)(pBuffer + (sizeof(int) * 2) + (sizeof(char) * 10));
    char * nome = (char *)(pBuffer + (sizeof(int) * 2));
    void * sentinela = criaSentinela();
    

    *idade = 1;
    *telefone = 1;
    nome[0] = 'z';
    nome[1] = 'r';
    nome[2] = 't';
    nome[3] = 'h';
    nome[4] = '\0';
    //void * nodo = criaNodo(idade, telefone, nome, var1, sentinela);
    inserir(var1, sentinela, idade, telefone, nome);

    //char * abc = (char*)(nodo + sizeof(int));
    //printf("%s\n", abc);
    *idade = 2;
    *telefone = 2;
    nome[0] = 'b';
    nome[1] = 'a';
    nome[2] = 'f';
    nome[3] = 'a';
    nome[4] = '\0';
    //nodo = criaNodo(idade, telefone, nome, var1, sentinela);
    inserir(var1, sentinela, idade, telefone, nome);
    *idade = 3;
    *telefone = 3;
    nome[0] = 'f';
    nome[1] = 'r';
    nome[2] = 't';
    nome[3] = 'h';
    nome[4] = '\0';
    //void * nodo = criaNodo(idade, telefone, nome, var1, sentinela);
    inserir(var1, sentinela, idade, telefone, nome);
    listar(var1, sentinela);
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