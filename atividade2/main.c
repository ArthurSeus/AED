#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int menu(void);
char * adicionar(char *lista, char *nome);
char * remover(char *lista, char *nome);
int listar(char *lista);


int main()
{
    int opc;
    char *lista;
    char nome[20];

    lista = (char *)malloc(sizeof(char));
    strcpy(lista, "\0");

    //testes
    //lista = (char *)malloc(34* sizeof(char));
    //strcpy(lista, "arthurjosecarlosrobertojuliamaria");
    //opc = 2;
    //strcpy(nome, "roberto");
    
    
    for(;;)
    {
        //comentar opc para debug
        opc = menu();
        switch(opc)
        {
            case 1:
            printf("Digite um nome para ser adicionado:");
            if (scanf("%[^\n]s", nome) == 1) {
                lista = adicionar(lista, nome);
                printf("Sua lista: %s\n", lista);
                break;
            }
            printf("Nao foi possivel ler.\n");
            break;
            

            case 2:
            printf("Digite um nome para ser removido:");
            if (scanf("%[^\n]s", nome) == 1) {
                lista = remover(lista, nome);
                printf("Sua lista: %s\n", lista); 
                break;
            }
            printf("Nao foi possivel ler.\n");
            break;
            

            case 3:
            listar(lista);
            break;


            case 4:
            free(lista);
            exit(0);
            break;
        }
    }

    return 0;
}

int menu(void)
{
	int c = 0;

	do
    {
	    printf("\t-- MENU --\n");
		printf("\t 1. Adicionar nome\n");
		printf("\t 2. Remover nome\n");
		printf("\t 3. Listar\n");
		printf("\t 4. Sair\n");
		printf("-- Digite sua escolha: ");
        if (scanf("%d", &c) == 1) {
            continue;
        } else {
        printf("Failed to read integer.\n");
        break;
        }

	} while (c <= 0 || c > 4);

	getchar();
	return c;
}

char *adicionar(char *lista, char *nome)
{
    
    int remove = strlen(nome);
    int list = strlen(lista);
    char *after;


    after = (char *)malloc((list + remove + 1) * sizeof(char));



    int j = 0;
    int k = 0;
  
    while (j < (list + remove))
    {
        if (j < list)
        {
            after[j] = lista[j];
            j++;
        }

        else
        {
            after[j] = nome[k];
            j++;
            k++;
        }
    }
  
    after[j] = '\0';
    free(lista);
    return after;
}


char * remover(char *lista, char *nome)
{
    int j = 0;
    int i = 0;
    int remove = strlen(nome);
    int list = strlen(lista) + 1;
    char *after;

    after = (char *)malloc((list) * sizeof(char));
  
    while (i < (list))
    {
        if (strstr(&lista[i], nome) == &lista[i])
        {  
            after = (char *)realloc(after, sizeof(char) * (list - remove));
            i += remove;
        }
        if (strstr(&lista[i], nome) != &lista[i])
        {
            after[j] = lista[i];
            j++;
            i++;
        }

    }
    
    free(lista);
    return after;
}


int listar(char *lista){
    
    int i = 0;
    printf("Lista de Nomes: ");

    while (i < strlen(lista))
    {
        printf("%c", lista[i]);
        i++;
    }

    printf("\n");
    return 0;
}
