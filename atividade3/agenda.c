#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void * adicionar(void *pBuffer, char *nome, int idade, long telefone, int *num_usuarios);
int listar(void *pBuffer, int *num_usuarios);
int buscar(void *pBuffer, char *nome, int*num_usuarios);
void *  remover(void *pBuffer, char *nome, int*num_usuarios);
int menu(void);


int main(void){
    
    int opc;
    char nome[10]; 
    int idade;
    long telefone;
    void * pBuffer = malloc(1);
    int num_usuarios = 0;

    for(;;)
    {
        opc = menu();
        switch(opc)
        {
            case 1:
                printf("Digite um nome: ");
                scanf("%[^\n]s", nome);
                getchar();
                printf("Digite a idade: ");
                scanf("%d", &idade);
                getchar();
                printf("Digite o telefone: ");
                scanf("%ld", &telefone);
                getchar();
            

                pBuffer = adicionar(pBuffer, nome, idade, telefone, &num_usuarios);
                break;
            case 2:
                printf("Digite um nome para remover da lista: ");
                scanf("%[^\n]s", nome);
                getchar();
                pBuffer = remover(pBuffer, nome, &num_usuarios);
                break;
            case 3:
                listar(pBuffer, &num_usuarios);
                break;
            case 4:
                printf("Digite um nome para procurar na lista: ");
                scanf("%[^\n]s", nome);
                getchar();
                buscar(pBuffer, nome, &num_usuarios);
                break;
            case 5:
                free(pBuffer);
                exit(0);
                break;
            
        }
    }
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
		printf("\t 4. Buscar por usuário\n");
        printf("\t 5. Sair\n");
		printf("-- Digite sua escolha: ");
        if (scanf("%d", &c) == 1) {
            continue;
        } else {
        printf("Failed to read integer.\n");
        break;
        }

	} while (c <= 0 || c > 5);

	getchar();
	return c;
}

void * adicionar(void *pBuffer, char *nome, int idade, long telefone, int *num_usuarios){

    char * lugar_nome;
    int * lugar_idade;
    long * lugar_telefone;

    //printf("%d\n", *num_usuarios);
    
    //void *reserva;
    pBuffer = realloc(pBuffer, (((sizeof(char) * 10) + sizeof(int) + (sizeof(long))) * (*num_usuarios)));

    
    lugar_nome = (pBuffer + (((sizeof(char) * 10) + sizeof(int) + sizeof(long)) * (*num_usuarios)));
    lugar_idade = (pBuffer + (((sizeof(char) * 10) + sizeof(int) + sizeof(long)) * (*num_usuarios)) + (sizeof(char) * 10));
    lugar_telefone = (pBuffer + (((sizeof(char) * 10) + sizeof(int) + sizeof(long)) * (*num_usuarios)) + (sizeof(char) * 10) + sizeof(int));

    for (int j = 0; j < strlen(nome); j++){
        *(lugar_nome + (sizeof(char) * j)) = nome[j];
    }

    *lugar_idade = idade;
    *lugar_telefone = telefone;
    
    *num_usuarios = *num_usuarios + 1;
        
    //printf("%s\n", (char*)pBuffer);
    //printf("%d\n", *(int*)(pBuffer + sizeof(char) * 10));
    // printf("%ld\n", *(long*)(pBuffer + sizeof(char) * 10 + sizeof(int)));
   

    return pBuffer;
}

int listar(void *pBuffer, int *num_usuarios){

    if (*num_usuarios == 0){
        printf("Lista está vazia\n");
        return 0;
    }

    void * lista;

    for (int i = 0; i < *num_usuarios; i++){
        lista = (pBuffer + (((sizeof(char) * 10) + sizeof(int) + sizeof(long)) * i));
        printf("usuário %d:", (i+1));
        printf(" Nome: %s |", (char*)lista);
        printf(" Idade: %d |", *(int*)(lista + sizeof(char) * 10));
        printf(" Telefone: %ld |\n", *(long*)(lista + sizeof(char) * 10 + sizeof(int)));
    }
    return 0;
    
}

int buscar(void *pBuffer, char *nome, int*num_usuarios){

    if (*num_usuarios == 0){
        printf("Lista está vazia!\n");
        return 0;
    }

    void * achar;

    for (int i = 0; i < *num_usuarios; i++){
        achar = (pBuffer + (((sizeof(char) * 10) + sizeof(int) + sizeof(long)) * i));
        if (strstr((char*)achar, nome) == (char*)achar){
            printf("usuário %d:", (i+1));
            printf(" Nome: %s |", (char*)achar);
            printf(" Idade: %d |", *(int*)(achar + sizeof(char) * 10));
            printf(" Telefone: %ld |\n", *(long*)(achar + sizeof(char) * 10 + sizeof(int)));
            return 0;
        }
    }

    printf("Usuário não está na lista!\n");

    return 0;
}


void * remover(void *pBuffer, char *nome, int *num_usuarios){

    if (*num_usuarios == 0){
        printf("Lista está vazia!\n");
        return 0;
    }

    int j = *num_usuarios;
    void * achar;
    char * lugar_nome_velho, * lugar_nome_novo;
    int * lugar_idade_velho, * lugar_idade_novo;
    long * lugar_telefone_velho, * lugar_telefone_novo;

    for (int i = 0; i < *num_usuarios; i++){
        achar = (pBuffer + (((sizeof(char) * 10) + sizeof(int) + sizeof(long)) * i));
        if (strstr((char*)achar, nome) == (char*)achar){

            if (i == (*num_usuarios - 1) ){
                pBuffer = realloc(pBuffer, (((sizeof(char) * 10) + sizeof(int) + (sizeof(long))) * (j - 1)));
                printf("%s removido!\n", nome);
                j--;
                //return pBuffer;
            }else{
                for (int k = i; k < (*num_usuarios - 1); k++){
                    lugar_nome_velho = (pBuffer + (((sizeof(char) * 10) + sizeof(int) + sizeof(long)) * k));
                    lugar_idade_velho = (pBuffer + (((sizeof(char) * 10) + sizeof(int) + sizeof(long)) * k) + (sizeof(char) * 10));
                    lugar_telefone_velho = (pBuffer + (((sizeof(char) * 10) + sizeof(int) + sizeof(long)) * k) + (sizeof(char) * 10) + sizeof(int));
                    lugar_nome_novo = (pBuffer + (((sizeof(char) * 10) + sizeof(int) + sizeof(long)) * (k + 1)));
                    lugar_idade_novo = (pBuffer + (((sizeof(char) * 10) + sizeof(int) + sizeof(long)) * (k + 1)) + (sizeof(char) * 10));
                    lugar_telefone_novo = (pBuffer + (((sizeof(char) * 10) + sizeof(int) + sizeof(long)) * (k + 1)) + (sizeof(char) * 10) + sizeof(int));
                    for (int o = 0; o < 10; o++){
                        *(lugar_nome_velho + (sizeof(char) * o)) = *(lugar_nome_novo + (sizeof(char) * o));
                    } 
                    *lugar_idade_velho = *lugar_idade_novo;
                    *lugar_telefone_velho = *lugar_telefone_novo;

                }
                printf("%s removido!\n", nome);
                pBuffer = realloc(pBuffer, (((sizeof(char) * 10) + sizeof(int) + (sizeof(long))) * (j - 1)));
                j--;
            }
        }
    }

    if (j == *num_usuarios){
        printf("Usuário não está na lista!\n");
        return pBuffer;
    }

    *num_usuarios = j;
    return pBuffer;
    
}