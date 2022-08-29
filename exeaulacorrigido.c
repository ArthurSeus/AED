#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){

    void * pBuffer = malloc(1);
    void * imprimir;
    char * tipoNumero = malloc(1);
    int opc;
    int i, numeroTotal = 0, numeroInt = 0, numeroFloat = 0, numeroDouble = 0;
    float f;
    double d;
    int * lugarInt;
    double * lugarDouble;
    float * lugarFloat;


    for (;;){

        printf("\n");
        printf("Deseja digitar...\n");
        printf("Digite 1 [int] \n");
        printf("Digite 2 [float] \n");
        printf("Digite 3 [double] \n");
        printf("Digite 4 para parar\n");
        printf("Sua escolha: ");
        scanf("%d", &opc);


        if (opc == 1){
            printf("Digite o int: ");
            scanf("%d", &i);

            pBuffer = realloc(pBuffer, (sizeof(int) * (numeroInt + 1)) + (sizeof(float) * numeroFloat) + (sizeof(double) * numeroDouble));

            lugarInt = (int *)(pBuffer + (sizeof(int) * numeroInt) + (sizeof(float) * numeroFloat) + (sizeof(double) * numeroDouble));
            *lugarInt = i;

            numeroInt++;
            numeroTotal++;
    
            tipoNumero = realloc(tipoNumero, sizeof(char) * numeroTotal);
            tipoNumero[numeroTotal - 1] = 'i'; //o problema foi ter usado "" ao invez de '' =(
            //printf("%c", tipoNumero[numeroTotal - 1]);
            
        }
        
        if (opc == 2){
            printf("Digite o float: ");
            scanf("%f", &f);

            pBuffer = realloc(pBuffer, (sizeof(int) * numeroInt)
             + (sizeof(float) * (numeroFloat + 1)) + (sizeof(double) * numeroDouble));

            lugarFloat = (float *)(pBuffer + (sizeof(int) * numeroInt) + (sizeof(float) * numeroFloat) + (sizeof(double) * numeroDouble));
            *lugarFloat = f;

            numeroFloat++;
            numeroTotal++;

            tipoNumero = realloc(tipoNumero, sizeof(char) * numeroTotal);
            tipoNumero[numeroTotal - 1] = 'f'; //o problema foi ter usado "" ao invez de '' =(
            //printf("%c", tipoNumero[numeroTotal - 1]);
        }

        if (opc == 3){
            printf("Digite o double: ");
            scanf("%lf", &d);

            pBuffer = realloc(pBuffer, (sizeof(int) * numeroInt)
             + (sizeof(float) * numeroFloat) + (sizeof(double) * (numeroDouble + 1)));

            lugarDouble = (double *)(pBuffer + (sizeof(int) * numeroInt) + (sizeof(float) * numeroFloat) + (sizeof(double) * numeroDouble));
            *lugarDouble = d;

            numeroDouble++; 
            numeroTotal++;

            tipoNumero = realloc(tipoNumero, sizeof(char) * numeroTotal);
            tipoNumero[numeroTotal - 1] = 'd'; //o problema foi ter usado "" ao invez de '' =(
            //printf("%c", tipoNumero[numeroTotal - 1]);
        }

        if (opc == 4){

            imprimir = pBuffer;
            printf("Todos numeros: ");
            for (int j = 0; j < numeroTotal; j++){
                 
                if (tipoNumero[j] == 'i'){
                    
                    printf(" %d |", *(int *)imprimir);
                    imprimir = imprimir + sizeof(int);
                }
                else if (tipoNumero[j] == 'f'){
                    
                    printf(" %f |", *(float *)imprimir);
                    imprimir = imprimir + sizeof(float);
                }
                else if (tipoNumero[j] == 'd'){
                    
                    printf(" %lf |", *(double *)imprimir);
                    imprimir = imprimir + sizeof(double);
                }
            }
            imprimir = pBuffer;
            printf("\n");
            printf("Todos inteiros: ");
            for (int j = 0; j < numeroTotal; j++){
                 
                 
                if (tipoNumero[j] == 'i'){
                    
                    printf(" %d |", *(int *)imprimir);
                    imprimir = imprimir + sizeof(int);
                }
                else if (tipoNumero[j] == 'f'){
                    
                    imprimir = imprimir + sizeof(float);
                }
                else if (tipoNumero[j] == 'd'){
                    
                    imprimir = imprimir + sizeof(double);
                }
            }
            imprimir = pBuffer;
            printf("\n");
            printf("Todos floats: ");
            for (int j = 0; j < numeroTotal; j++){
                 
                if (tipoNumero[j] == 'i'){
                    
                    imprimir = imprimir + sizeof(int);
                }
                else if (tipoNumero[j] == 'f'){
                    
                    printf(" %f |", *(float *)imprimir);
                    imprimir = imprimir + sizeof(float);
                }
                else if (tipoNumero[j] == 'd'){
                    
                    imprimir = imprimir + sizeof(double);
                }
            }
            imprimir = pBuffer;
            printf("\n");
            printf("Todos doubles: ");
            for (int j = 0; j < numeroTotal; j++){
                 
                if (tipoNumero[j] == 'i'){
                    
                    imprimir = imprimir + sizeof(int);
                }
                else if (tipoNumero[j] == 'f'){
                    
                    imprimir = imprimir + sizeof(float);
                }
                else if (tipoNumero[j] == 'd'){
                    
                    printf(" %lf |", *(double *)imprimir);
                    imprimir = imprimir + sizeof(double);
                }
            }
            printf("\n");

            free(pBuffer);
            free(tipoNumero);
            exit(0);


        }

    }


}