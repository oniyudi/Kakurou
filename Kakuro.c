#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TF 9

//função para ler o tamanho lógico da matriz
int ler_tamanho_matriz(int *tl_col, int *tl_lin){
    do{
    printf("Escolha a quantidade de linhas no Kakuro (Max. 8): ");
    scanf("%d", tl_lin);}while(*tl_lin <1 || *tl_lin > 8);
    tl_lin += 1;
    do{
    printf("Escolha a quantidade de colunas no Kakuro (Max. 8): ");
    scanf("%d", tl_col);}while(*tl_col <1|| *tl_col > 8);
    tl_col += 1;
}

//calcula a soma das colunas
void efetuar_soma_colunas(int mat[][TF], int tl_col, int tl_lin)
{
    int i, c, soma = 0;
    mat[0][0] = 0;
    for(c = 1; c < tl_col; c++)
    {
        for(i = 1; i < tl_lin; i++)
        {
            soma += mat[i][c];
        }
        mat[0][c] = soma;
        soma = 0;
    }
}

//preenche a matriz principal com valores aleatórios entre 0-9
void preencher_vetor(int mat[][TF],int tl_col, int tl_lin){
    int i,c,excluido,soma = 0,sorteio,minimo,maximo;
    minimo = (tl_col * tl_lin)/3;
    maximo = (tl_col * tl_lin)/2;

    for(i=1; i<tl_lin; i++){
        for(c = 1; c<tl_col; c++){
            excluido = rand() %2; //excluido, é para saber se a posicao vai ter um valor ou não;
            if(excluido == 1){
                sorteio = rand() %9+1; //preenchendo a posicao com um valor aleatorio;
                mat[i][c] = sorteio;
                soma+=sorteio;
                contador++;
            }
            else
            {
                mat[i][c] = 0;
            }
        }
        mat[i][0] = soma;
        soma = 0;
    }
    efetuar_soma_colunas(mat,tl_col,tl_lin);
}

void print_traco(int tl_lin)
{
    int i, qnt;
    qnt = 8 * (tl_lin+1);
    for(i = 0; i < qnt; i++)
    {
        printf("-");
    }
}

void apresentar_matriz(int mat[][TF], int tl_col, int tl_lin)
{
    int i, c;
    for(i = 0; i < tl_lin; i++)
    {
        for(c = 0; c < tl_col; c++)
        {
            printf("%2d", mat[i][c]);
            if(c == 0)
                printf(" | ");
            if(c == tl_col-1)
            {
                printf("\t| %2d", i);
            }
            else
                printf("\t");
        }
        printf("\n");
        if(i == 0)
        {
            print_traco(tl_lin);
            printf("\n");
        }
        if(i == tl_lin-1)
        {
            print_traco(tl_lin);
            printf("\n");
        }
    }
    for(i = 0; i < tl_lin; i++)
    {
        printf("%2d", i);
        if(i == 0)
            printf(" | ");
        printf("\t");
        if(i == tl_lin-1)
            printf("| %2d", 0);
    }
}

//preenchendo a matriz que o jogador irá ver
void preencher_matriz_jogo(int mat_main[][TF], int mat_game[][TF], int tl_col,int tl_lin)
{
    int i, c, sorteio;
    for(i = 0; i < tl_lin; i++)
    {
        for(c = 0; c < tl_col; c++)
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

//verifica se os valores informados pelo usuario sao validos
int validar_entrada(int i, int c, int mat_b[][TF])
{
    int res = 0;
    if(i > -1 && i < 9 && c > -1 && c < 9) //se esta dentro do intervalo da matriz
    {
        if(i == 0 && c == 0)//caso seja 00, o programa deve parar
        {
            res = 1;
        }
        else if(mat_b[i][c] != 0)//nao pode escolher uma posicao que é 0
        {
            res = 1;
        }
        else
        {
            printf("Posicao informada invalida\n");
        }
    }
    else
    {
        printf("Posicao informada invalida\n");
    }
    return res;
}

void apresentar_vida(int life)
{
    switch (life)
    {
    case 1:
        printf("Vidas: <3\n\n");
        break;
    case 2:
        printf("Vidas: <3 <3\n\n");
        break;
    case 3:
        printf("Vidas: <3 <3 <3\n\n");
    default:
        break;
    }
}

void apresentar_game(int mat_b[][TF], int tl_col, int tl_lin, int *linha, int *coluna, int life)
{
    int i, c, res;
    printf("==================================== KAKURO ====================================\n\n");
    apresentar_vida(life);
    apresentar_matriz(mat_b, tl_col,tl_lin);
    printf("\n");

    do
    {
        printf("Informe a linha e coluna (linha coluna): ");
        scanf("%d", &i);
        scanf("%d", &c);
        res = validar_entrada(i, c, mat_b);
    } while (res == 0);

    *linha = i;
    *coluna = c;
    
    printf("================================================================================\n\n");
}

//verifica se o jogador acertou a posicao, se sim, retorna 1
int verificar_acerto(int line, int col, int mat_main[][TF])
{
    int res = 0;
    if(mat_main[line][col] == 0)
    {
        res = 1;
    }

    return res;
}

void atualizar_matriz_game(int mat_b[][TF], int line, int col)
{
    mat_b[line][col] = 0;
}

int verificar_vida(int life)
{
    int res = 1;
    if(life - 1 == 0)
    {
        res = 0;
    }
    return res;
}

void remover_vida(int *life)
{
    printf("ERROU!\n");
    if(verificar_vida(*life) == 0)
    {
        printf("VOCE PERDEU!\n");
    }
    *life -= 1;
}

int verificar_vencedor(int mat_b[][TF], int mat_main[][TF], int tl_col, int tl_lin)
{
    int res = 1, i, c;
    for(i = 1; i < tl_lin; i++)
    {
        for(c = 1; c < tl_col; c++)
        {
            if(mat_b[i][c] != mat_main[i][c]){
                i = tl_lin;
                c = tl_col;
                res = 0;
            }
        }
    }
    return res;
}

int main()
{
    srand(time(NULL));
    int tamanho_col,tamanho_lin, matriz_principal[TF][TF], matriz_b[TF][TF], linha, coluna, vida = 3, vencedor = 0; // matriz principal é a colinha
    ler_tamanho_matriz(&tamanho_col,&tamanho_lin);
    preencher_vetor(matriz_principal,tamanho_col,tamanho_lin);
    preencher_matriz_jogo(matriz_principal, matriz_b, tamanho_col, tamanho_lin);

    do
    {
        apresentar_game(matriz_b,tamanho_col,tamanho_lin, &linha, &coluna, vida);
        if(linha == 0 && coluna == 0)
        {
            printf("JOGO ENCERRADO!\n");
        }
        else
        {
            if(verificar_acerto(linha, coluna, matriz_principal) == 1)
            {
                atualizar_matriz_game(matriz_b, linha, coluna);
                if(verificar_vencedor(matriz_b, matriz_principal,tamanho_col,tamanho_lin) == 1)
                {
                    vencedor = 1;
                    printf("PARABENS VOCE GANHOU!\n");
                    apresentar_matriz(matriz_b, tamanho_col,tamanho_lin);
                }
            }
            else
            {
                remover_vida(&vida);
            }
        }
    } while (linha != 0 && coluna != 0 && vida > 0 && vencedor != 1);

    return 0;
}