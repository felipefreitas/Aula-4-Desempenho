#include <stdlib.h>
#include <stdio.h>
#include <omp.h>
#include <ctime>

int** generateMatrix(int l, int c, int populate)
{
    int** matrix;
    matrix = (int**) calloc(l, 1+sizeof(int*));
    
    for(int i = 0;i<l;i++) 
    {
        matrix[i] = (int*) calloc(c, 1+sizeof(int));
    }

    matrix[l] = NULL;

    for(int i = 0;i<l;i++) 
    {
        for(int j = 0;j<c;j++) 
        {
            if(populate == 1)
            {
                matrix[i][j] = rand() % 20;
            }
            else 
            {
                matrix[i][j] = NULL;
            }
        }
    }

    return matrix;
}

void printMatrix(int** matrix, int l, int c)
{
    for(int i = 0; i < l; i++)
    {
        for(int k = 0; k < c; k++)
        {
            printf(" %d ", matrix[i][k]); 
        }    
        printf("\n");
    }
    printf("\n");

}

// Implementação ikj
int** multMatrix(int** A, int** B, int al, int ac, int bl, int bc)
{
    int r, i, k, j;
    int **C;
    C = generateMatrix(al, bc, 0);
    
    double st=omp_get_wtime();

    printf("Numero maximo de threads: %i \n", omp_get_max_threads());

    #pragma omp parallel for private(k,j)
    for(i = 0; i < al; i++)
    {
        for(k = 0; k < ac; k++)
        {
            r = A[i][k];
            for(j = 0; j < bc; j++)
            {
                C[i][j] += r*B[k][j];
            }
        }
    }
    
    double en=omp_get_wtime();
    printf("Tempo Multiplicacao: %lf\n",en-st);

    return C;
}

int main (){
    int al = 0, ac = 0, bl = 0, bc = 0;
    int** A;
    int** B;
    int** C;

    printf("Digite a dimensao da matriz A: (Ex. 3 2)\n");
    scanf("%d %d", &al, &ac);

    printf("\nDigite a dimensao da matriz B: (Ex. 2 3)\n");
    scanf("%d %d", &bl, &bc);

    printf("\nDimensoes escolhidas: A[%d][%d] e B[%d][%d]\n", al, ac, bl, bc);
    
    printf("Gerando matrizes com valores randomicos...\n");
    printf("Matrix A:\n");
    A = generateMatrix(al, ac, 1);
    //printMatrix(A, al, ac);

    printf("Matrix B:\n");
    B = generateMatrix(bl, bc, 1);
    //printMatrix(B, bl, bc);

    printf("Calculando...\n\n");
    printf("Matrix C:\n");
    C = multMatrix(A, B, al, ac, bl, bc);
    //printMatrix(C, al, bc);
}