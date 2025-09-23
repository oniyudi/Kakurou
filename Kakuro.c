#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int ler_tamanho_matriz(){
    int numero;
    do{
    printf("Escolha o tamanho da matriz do Kakuro (Max. 8): ");
    scanf("%d", &numero);}while(numero <1 || numero > 8);
    return numero;
}

void preencher_vetor(int mat[][8],int tam){
    int i,c,excluido,soma = 0, sorteio;

    for(i=1; i<tam; i++){
        for(c = 1; c<tam; c++){
            excluido = rand() %2; //excluido, é para saber se a posicao vai ter um valor ou não;
            if(excluido == 1){
                sorteio = rand() %9+1; //preenchendo a posicao com um valor aleatorio;
                printf("Sorteio = %d; linha = %d; Coluna = %d\n", sorteio, i, c);
                mat[i][c] = sorteio;
                soma+=sorteio;
            }
            else
            {
                mat[i][c] = 0;
            }
        }
        mat[i][0] = soma;
        soma = 0;
    }
}

void efetuar_soma_colunas(int mat[][8], int tam)
{
    int i, c, soma = 0;
}

void apresentar_matriz(int mat[][8], int tam)
{
    int i, c;
    for(i = 0; i < tam; i++)
    {
        for(c = 0; c < tam; c++)
        {
            printf("%d\t", mat[i][c]);
        }
        printf("\n");
    }
}

int main()
{
    srand(time(NULL));
    int tamanho, matriz_principal[8][8] /*matriz_b[8][8]*/; // matriz principal é a colinha
    tamanho = ler_tamanho_matriz();

    printf("O tamanho da matriz: %d\n", tamanho);

    preencher_vetor(matriz_principal, tamanho);

    apresentar_matriz(matriz_principal, tamanho);

    return 0;
}