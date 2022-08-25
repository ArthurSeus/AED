#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Pessoa
{
    char nome[10]; 
    int idade;
    int altura;
};

int main(void){
    struct Pessoa * pessoas = malloc(1);
    int i = 0;
    char escolha[4];
    for(;;){
        pessoas = realloc(pessoas, (sizeof(struct Pessoa) * (i + 1)));
        printf("Digite um nome: ");
        scanf("%[^\n]s", pessoas[i].nome);
        getchar();
        printf("Digite a idade: ");
        scanf("%d", &pessoas[i].idade);
        getchar();
        printf("Digite o telefone: ");
        scanf("%d", &pessoas[i].altura);
        getchar();
        printf("Deseja parar? [sim para parar]: ");
        scanf("%[^\n]s", escolha);
        getchar();
        if (strcmp(escolha, "sim") == 0 || strcmp(escolha, "Sim") == 0 || strcmp(escolha, "s") == 0){
            for (int j = 0; j < i; j++){
                printf("%s", pessoas[j].nome);
                printf("%d", pessoas[j].idade);
                printf("%d", pessoas[j].altura);
            }

        }


        i++;





    }
}