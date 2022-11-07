#include <stdlib.h>
#include <stdio.h>


typedef struct{
    int numero;
    struct Nodo * left, * right;
}Nodo;


int Altura(Nodo * pRaiz){
    int left, right;
    if(pRaiz == NULL){
        return 0;
    }

    left = Altura(pRaiz->left);
    right = Altura(pRaiz->right);

    if(left > right){
        return left + 1;
    }
    else{
        return right + 1;
    }
}

int FB(Nodo * pRaiz){
    if(pRaiz == NULL){
        return 0;
    }
    return Altura(pRaiz->left) - Altura(pRaiz->right);
}


int Insere(Nodo ** pRaiz, int num){
    if(*pRaiz == NULL){
        *pRaiz = (Nodo*)malloc(sizeof(Nodo));
        (*pRaiz)->left = NULL;
        (*pRaiz)->right = NULL;
        (*pRaiz)->numero= num;
        return 1;
    }

    if(num < (*pRaiz)->numero){
        Insere(&((*pRaiz)->left), num);
        return 1;
    }

    if(num >= (*pRaiz)->numero){
        Insere(&((*pRaiz)->right), num);
        //printf("%d", (*pRaiz)->right);
        return 1;
    }

    return 1;
}

int VerificaArvore(Nodo ** ppRaiz){
    int left, right, fb;
    if(*ppRaiz == NULL){
        return 0;
    }
    
    fb = FB(*ppRaiz);
    if(fb < - 1 || fb > 1){
        return 1;
    }

    left = VerificaArvore(&(*ppRaiz)->left);
    right = VerificaArvore(&(*ppRaiz)->right);
    
    if((left || right) == 1){
        return 1;
    }
    
    return 0;
}

void Limpa(Nodo ** pRaiz){
    //int left, right;
    if(*pRaiz == NULL){
        return;
    }

    Limpa(&((*pRaiz)->left));
    Limpa(&((*pRaiz)->right));

    free(*pRaiz);
    return;
}

int main(void){
    int num = 0;
    Nodo * pRaiz = NULL;

    while(num != 999){
        printf("Insira numeros[999 para parar]: ");
        scanf("%d", &num);
        getchar();
        if(num != 999){
            Insere(&pRaiz, num);
        }

    }

    int fb = VerificaArvore(&pRaiz);

    if(fb == 0){
        printf("Arvore é avl!\n");
    }else{
        printf("Arvore nao é avl!\n");
    }
    
    Limpa(&pRaiz);
}