#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TF 8

//função para ler o tamanho lógico da matriz
void ler_tamanho_matriz(int *tl_col, int *tl_lin){
    do{
    printf("Escolha a quantidade de linhas no Kakuro (Max. 8): ");
    scanf("%d", tl_lin);}while(*tl_lin <1 || *tl_lin > 8);
    do{
    printf("Escolha a quantidade de colunas no Kakuro (Max. 8): ");
    scanf("%d", tl_col);}while(*tl_col <1|| *tl_col > 8);
}

//calcula a soma das colunas
    void efetuar_soma_colunas(int mat[][TF], int tl_col, int tl_lin, int soma_col[TF])
    {
        int i, c, soma = 0;
        for(c = 0; c < tl_col; c++)
        {
            for(i = 0; i < tl_lin; i++)
            {
                soma += mat[i][c];
            }
            soma_col[c] = soma;
            soma = 0;
        }
    }

void efetuar_soma_linhas(int mat[][TF],int tl_col,int tl_lin, int soma_lin[TF]){
 int l, c, soma = 0;
    for(l = 0; l < tl_lin; l++)
    {
        for(c = 0; c < tl_col; c++)
        {
            soma += mat[l][c];
        }
        soma_lin[l] = soma;
        soma = 0;
    }
}

void validar_preenchimento_minimo(int mat[][TF], int min, int max, int contador){
    int linha, coluna, numero;
    while(contador < min){ //verifica se tem o minimo de numeros para jogar o kakuro
        linha = rand() %9 + 1;
        coluna = rand() %9 + 1;
        if(mat[linha][coluna] == 0){
            numero = rand() %9 +1;
            mat[linha][coluna] = numero;
        }
        contador++;
    }
    while(contador > max){ //verifica se passou do maximo de numeros para jogar o kakuro
        linha = rand() %9 + 1;
        coluna = rand() %9 + 1;
        if(mat[linha][coluna] != 0){
            mat[linha][coluna] = 0;
        }
        contador--;
    }
}

//preenche a matriz principal com valores aleatórios entre 0-9
void preencher_vetor(int mat[][TF],int tl_col, int tl_lin, int soma_col[TF], int soma_lin[TF]){
    int i,c,excluido,sorteio,minimo,maximo,contador = 0;
    minimo = (tl_col * tl_lin)/3;
    maximo = (tl_col * tl_lin)/2;

    for(i=0; i<tl_lin; i++){
        for(c = 0; c<tl_col; c++){
            excluido = rand() %2; //excluido, é para saber se a posicao vai ter um valor ou não;
            if(excluido == 1){
                sorteio = rand() %9+1; //preenchendo a posicao com um valor aleatorio;
                mat[i][c] = sorteio;
                contador++;
            }
            else
            {
                mat[i][c] = 0;
            }
        }
    }
    validar_preenchimento_minimo(mat,minimo,maximo,contador);
    efetuar_soma_colunas(mat,tl_col,tl_lin,soma_col);
    efetuar_soma_linhas(mat,tl_col,tl_lin,soma_lin);
}

void print_traco(int tl_col)
{
    int i, qnt;
    if(tl_col  == 1 ){
        qnt = 20 * (tl_col);
    }else if(tl_col == 2){
        qnt = 14 * (tl_col);
    }
    else if(tl_col > 2 && tl_col < 5 ){
        qnt = 12 * (tl_col);
    }else{
        qnt = 10 * (tl_col);

    }

    for(i = 0; i < qnt; i++)
    {
        printf("-");
    }
    printf("\n");
}

void apresentar_matriz(int mat[][TF], int tl_col, int tl_lin, int soma_col[TF], int soma_lin[TF])
{
    int i, c, contador = 0;
    printf("00 |  \t");
    for(i = 0; i < tl_col; i++){
        printf("%d \t", soma_col[i]);
        if(i ==  tl_col-1){
            printf("| C");
        }
    }
    printf("\n");
    print_traco(tl_col);
 
for(i = 0; i< tl_lin; i++){
        printf("%2d | \t", soma_lin[i]);
        for(c = 0; c< tl_col; c++){
            printf("%d\t",mat[i][c]);
            if(c ==  tl_col-1){
                printf("| %d",contador);
                contador++;
            }
        }
        printf("\n");
    }

    print_traco(tl_col);
    contador = 0;
  
    printf("L  | \t");    
    for(contador = 0; contador < tl_col; contador++){
        printf("%d\t", contador);
    }
    printf("|");
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
}

//verifica se os valores informados pelo usuario sao validos
int validar_entrada(int i, int c, int mat_b[][TF])
{
    int res = 0;
    if(i > -1 && i < 10 && c > -1 && c < 10) //se esta dentro do intervalo da matriz
    {
        if(i == 9 && c == 9)//caso seja 9 9, o programa deve parar
        {
            res = 1;            
        }
        else if(mat_b[i][c] != 9)//nao pode escolher uma posicao que é 0
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

void apresentar_game(int mat_b[][TF], int tl_col, int tl_lin, int *linha, int *coluna, int life, int soma_col[TF], int soma_lin[TF])
{
    int i, c, res;
    printf("\n==================================== KAKURO ====================================\n\n");
    apresentar_vida(life);
    apresentar_matriz(mat_b, tl_col, tl_lin, soma_col, soma_lin);
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
    int tamanho_col,tamanho_lin, matriz_principal[TF][TF], matriz_b[TF][TF], linha, coluna, vida = 3, vencedor = 0, vet_soma_col[TF],vet_soma_lin[TF]; // matriz principal é a colinha
    ler_tamanho_matriz(&tamanho_col,&tamanho_lin);
    printf("Valor da linha: %d\n", tamanho_lin);
    preencher_vetor(matriz_principal,tamanho_col,tamanho_lin,vet_soma_col,vet_soma_lin);
    preencher_matriz_jogo(matriz_principal, matriz_b, tamanho_col, tamanho_lin);

    apresentar_matriz(matriz_principal,tamanho_col,tamanho_lin,vet_soma_col,vet_soma_lin);
    do
    {
        apresentar_game(matriz_b,tamanho_col,tamanho_lin, &linha, &coluna, vida,vet_soma_col,vet_soma_lin);
        if(linha == 9 && coluna == 9)
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
                    apresentar_matriz(matriz_b, tamanho_col,tamanho_lin,vet_soma_lin,vet_soma_col);
                }
            }
            else
            {
                remover_vida(&vida);
            }
        }
    } while (linha != 9 && coluna != 9 && vida > 0 && vencedor != 1);

    return 0;
}