#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int menu(void);
char * adicionar(char *lista, char *newsub);
char * remover(char *lista, char *nome);
int listar(char *lista);


int main()
{
    int opc;
    char *lista;
    char nome[20];

    lista = (char *)malloc(sizeof(char));

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
            scanf("%[^\n]s", nome);
            lista = adicionar(lista, nome);
            printf("Sua lista: %s\n", lista);
            break;
            
            case 2:
            printf("Digite um nome para ser removido:");
            //scanf("%[^\n]s", nome);
            lista = remover(lista, nome);
            printf("Sua lista: %s\n", lista); 
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
		scanf("%d", &c);
	} while (c <= 0 || c > 4);

	getchar();
	return c;
}

char *adicionar(char *before, char *newsub)
{
    
    int new_length = strlen(newsub);
    int before_length = strlen(before);
    //printf("%d", new_length);
    //printf("%d", before_length);
    
  
    char *after;


    after = (char *)malloc((before_length + new_length + 1) * sizeof(char));



    int j = 0;
    int k = 0;
  
    while (j < (before_length + new_length))
    {
        if (j < before_length)
        {
            after[j] = before[j];
            j++;
        }

        else
        {
            after[j] = newsub[k];
            j++;
            k++;
        }
    }
  
    after[j] = '\0';

    return after;
}


char * remover(char *lista, char *nome)
{
    int j = 0;
    int i = 0;
    int remove = strlen(nome);
    int list = strlen(lista);
    char *after;

    after = (char *)malloc((list) * sizeof(char));
  
    while (i < list)
    {
        if (strstr(&lista[i], nome) == &lista[i])
        {  
            after = (char *)realloc(after, sizeof(char) * (list - remove));
            i += remove;
        }
        
        after[j] = lista[i];
        j++;
        i++;
    }
  
    after[j] = '\0';

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
