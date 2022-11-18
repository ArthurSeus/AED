#include <stdio.h>
#include <stdlib.h>

int descobre(int arr[], int size){
    int test[size + 1];
    for(int i = 0; i < size + 1; i++){
        test[i] = i;
    }
    for(int i = 0; i < size; i++){
        test[arr[i]] = -999;
    }
    for(int i = 0; i < size + 1; i++){
        if(test[i] != -999){
            return test[i];
        }
    }
}

int main(void){
    int tam, num;
    printf("Escolha o tamanho do array: ");
    scanf("%d", &tam);
    getchar();
    int arr[tam];
    for(int i = 0; i < tam; i++){
        printf("Digito: ");
        scanf("%d", &num);
        getchar();
        arr[i] = num;
    }
    int size = sizeof(arr)/sizeof(arr[0]);
    printf("Numero que falta: %d", descobre(arr, size));
}