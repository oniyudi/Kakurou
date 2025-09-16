#include <stdio.h>

int ler_tamanho_matriz(){
    int numero;
    do{
    printf("Escolha o tamanho da matriz do Kakuro (Max. 8)");
    scanf("%d", &numero);}while(numero <1 || numero > 8);
    return numero;
}

void main()
{
    int tamanho;
    tamanho = ler_tamanho_matriz();   
}