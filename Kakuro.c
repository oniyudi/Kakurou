#include <stdio.h>
#include <stdlib.h>

int ler_tamanho_matriz(){
    int numero;
    do{
    printf("Escolha o tamanho da matriz do Kakuro (Max. 8): ");
    scanf("%d", &numero);}while(numero <1 || numero > 8);
    return numero;
}

int preencher_vetor(int mat[][8],int tam){
    int i,c,excluido,soma = 0;

    for(i=1; i<tam; i++){
        for(c = 1; c<tam; c++){
            excluido = rand() %2; //excluido, é para saber se a posicao vai ter um valor ou não;
            if(excluido == 1){
               mat[i][c] = rand() %9+1; //preenchendo a posicao com um valor aleatorio;
               soma+=mat[i][c];
            }
        }
        mat[i][0] = soma;
    }
}

int main()
{
    int tamanho, matriz_principal[8][8], matriz_b[8][8];
    tamanho = ler_tamanho_matriz();

    printf("O tamanho da matriz: %d", tamanho);

    return 0;
}