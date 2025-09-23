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

void efetuar_soma_colunas(int mat[][8], int tam)
{
    int i, c, soma = 0;
    mat[0][0] = 0;
    for(c = 1; c < tam; c++)
    {
        for(i = 1; i < tam; i++)
        {
            soma += mat[i][c];
        }
        mat[0][c] = soma;
        soma = 0;
    }
}

void preencher_vetor(int mat[][8],int tam){
    int i,c,excluido,soma = 0, sorteio;

    for(i=1; i<tam; i++){
        for(c = 1; c<tam; c++){
            excluido = rand() %2; //excluido, é para saber se a posicao vai ter um valor ou não;
            if(excluido == 1){
                sorteio = rand() %9+1; //preenchendo a posicao com um valor aleatorio;
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
    
    efetuar_soma_colunas(mat, tam);
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

void preencher_matriz_jogo(int mat_main[][8], int mat_game[][8], int tam)
{
    int i, c, sorteio;
    for(i = 0; i < tam; i++)
    {
        for(c = 0; c < tam; c++)
        {
            if(mat_main[i][c] == 0)
            {
                sorteio = rand() %9+1;
                mat_game[i][c] = sorteio;
            }
            else
            {
                mat_game[i][c] = mat_main[i][c];
            }
        }
    }
    mat_game[0][0] = 0;
}

int main()
{
    srand(time(NULL));
    int tamanho, matriz_principal[8][8], matriz_b[8][8]; // matriz principal é a colinha
    tamanho = ler_tamanho_matriz();

    printf("O tamanho da matriz: %d\n", tamanho);

    preencher_vetor(matriz_principal, tamanho);

    apresentar_matriz(matriz_principal, tamanho);

    preencher_matriz_jogo(matriz_principal, matriz_b, tamanho);
    printf("\nApresentando a matriz do jogador:\n");
    apresentar_matriz(matriz_b, tamanho);

    return 0;
}