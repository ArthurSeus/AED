#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void menu(int * opc);

struct Pessoa
{
    char nome[30]; 
    int idade;
    long telefone;
};

int main(void){
    struct Pessoa pessoas[10];
    void *pBuffer = malloc((sizeof(int) * 6) + (sizeof(char) * 10));
    int * opc = pBuffer;
    int * limite = (pBuffer + sizeof(int));
    int * num_usuarios = (pBuffer + (sizeof(int) * 2));
    int * variavel = (pBuffer + (sizeof(int) * 3));
    int * outra_variavel = (pBuffer + (sizeof(int) * 4));
    int * loop_char = (pBuffer + (sizeof(int) * 5));
    char * nome = (pBuffer + (sizeof(int) * 6));
    *limite = 10;
    *num_usuarios = 0;

    for (;;){
        menu(opc);
        switch (*opc)
        {
            case 1:
            
                if (*num_usuarios < *limite){

                    printf("Digite um nome: ");
                    scanf("%[^\n]s", pessoas[*num_usuarios].nome);
                    getchar();
                    printf("Digite a idade: ");
                    scanf("%d", &pessoas[*num_usuarios].idade);
                    getchar();
                    printf("Digite o telefone: ");
                    scanf("%ld", &pessoas[*num_usuarios].telefone);
                    getchar();
                    *num_usuarios = *num_usuarios + 1;
                }else{
                    printf("Lista no tamanho máximo!");
                }
                
                break;
    
            case 2:
                printf("Digite um nome para remover da lista: ");
                scanf("%[^\n]s", nome);
                
                for ( *variavel = 0; *variavel < *num_usuarios; *variavel = *variavel + 1){
                    if (strcmp(pessoas[*variavel].nome, nome) == 0){
                        if ((*variavel + 1) == *num_usuarios){
                            for (*loop_char = 0; *loop_char < 10; *loop_char = *loop_char + 1){
                                pessoas[*variavel].nome[*loop_char] = '\0';
                            }
                            pessoas[*variavel].idade = 0;
                            pessoas[*variavel].telefone = 0;

                        }else{
                            for (*outra_variavel = *variavel; *outra_variavel < (*num_usuarios - 1); *outra_variavel = *outra_variavel + 1){
                                for (*loop_char = 0; *loop_char < 10; *loop_char = *loop_char + 1){
                                    pessoas[*outra_variavel].nome[*loop_char] = pessoas[*outra_variavel + 1].nome[*loop_char];
                                }
                                pessoas[*outra_variavel].idade = pessoas[*outra_variavel + 1].idade;
                                pessoas[*outra_variavel].telefone = pessoas[*outra_variavel + 1].telefone;
                            }
                            for (*loop_char = 0; *loop_char < 10; *loop_char = *loop_char + 1){
                                    pessoas[*num_usuarios].nome[*loop_char] = '\0';
                                }
                                pessoas[*num_usuarios].idade = 0;
                                pessoas[*num_usuarios].telefone = 0;
                        }
                        *num_usuarios = *num_usuarios - 1;
                    }
                }
                break;

            case 3:
                for (*variavel = 0; *variavel < *num_usuarios; *variavel = *variavel + 1){
                    printf("Nome: %s, Idade: %d, Telefone: %ld\n",pessoas[*variavel].nome, pessoas[*variavel].idade, pessoas[*variavel].telefone);
                }
                
                break;

            case 4:
                printf("Digite um nome para procurar na lista: ");
                scanf("%[^\n]s", nome);
                *outra_variavel = 0;
                for (*variavel = 0; *variavel < *num_usuarios; *variavel = *variavel + 1){
                    if (strcmp(pessoas[*variavel].nome, nome) == 0){
                        printf("Nome: %s, Idade: %d, Telefone: %ld\n",pessoas[*variavel].nome, pessoas[*variavel].idade, pessoas[*variavel].telefone);
                        *outra_variavel = *outra_variavel + 1;
                    }
                }
                if (*outra_variavel == 0){
                    printf("Usuario não está na lista!\n");
                }
                
                break;

            case 5:
                free(pBuffer);
                //free(pessoas);
                exit(0);
                break;
    }
    }



}


void menu(int * opc)
{
	*opc = 0;


	do
    {
	    printf("\t-- MENU --\n");
		printf("\t 1. Adicionar nome\n");
		printf("\t 2. Remover nome\n");
		printf("\t 3. Listar\n");
		printf("\t 4. Buscar por usuário\n");
        printf("\t 5. Sair\n");
		printf("-- Digite sua escolha: ");
        if (scanf("%d", opc) == 1) {
            continue;
        } else {
        printf("Failed to read integer.\n");
        break;
        }

	} while (*opc <= 0 || *opc > 5);

    //printf("%d", **opc);
	getchar();
    
}

