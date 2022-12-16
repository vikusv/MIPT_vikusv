#include <stdio.h>
#include <stdlib.h>
#define N 10

void powNxN (unsigned (*A)[N], unsigned k, unsigned m);

int main() 
{
    unsigned matrix[N*N] = {7, 0, 9, 0, 9, 2, 3, 8, 3, 5, 3, 7, 5, 10, 6, 8, 5, 6, 1, 7, 10, 6, 10, 6, 10, 4, 4, 2, 2, 4, 
    0, 9, 4, 6, 7, 4, 2, 2, 8, 4, 1, 8, 8, 0, 2, 0, 0, 10, 5, 1,
4 , 2 , 0, 8, 7 ,2 ,3 ,3 ,6 ,2 ,
4 , 5 , 6, 2, 1 ,5 ,9 ,3 ,1 ,0 ,
3 , 7 , 1, 6, 7 ,1 ,9 ,10, 8, 4, 
1 , 3 , 2, 0, 1 ,5 ,1 ,8 ,9 ,6 ,
10,  8,  10, 4, 0, 10, 4, 4, 5, 4};
    unsigned arr[N][N] = {};
    unsigned k = 22, m = 869267;
    //unsigned matrix[N*N] = {1,1,1,0};
    //unsigned k = 20, m = 10;


    for (int i = 0; i < N; i++)
    {
        for (int ii = 0; ii < N; ii++)
            arr[i][ii] = matrix[i*N + ii];
    }
    powNxN(arr, k, m);

    for (int i = 0; i < N; i++)
    {
        for (int ii = 0; ii < N; ii++)
            matrix[i*N + ii] = arr[i][ii];
    }

    printf("%u %u %u %u\n", matrix[0], matrix[1], matrix[2], matrix[3]);

    return 0;
}

void matrix_mult(unsigned (*A)[N], unsigned (*B)[N], unsigned m)
{
    //int N = 2;
    unsigned arr[N][N] = {0};

    for (int counter1 = 0; counter1 < N; counter1++)
    {
        for (int counter2 = 0; counter2 < N; counter2++)
        {
            for (int ii = 0; ii < N; ii++)
            {
                int proizv = (A[counter1][ii] * B[ii][counter2]);
                //printf("proizv = %d, arr[%d][%d] = %d\n", proizv, counter1, counter2, arr[counter1][counter2]);
                arr[counter1][counter2] = (arr[counter1][counter2] + proizv) % m;
                //printf("%d ", arr[counter1][counter2]);
            }
            //printf("\n");
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int ii = 0; ii < N; ii++)
        {
            A[i][ii] = arr[i][ii];
            //printf("%d ", A[i][ii]);
        }
        //printf("\n");
    }
}

void powNxN(unsigned (*A)[N], unsigned k, unsigned m)
{
    //int N = 2;
    unsigned arr[N][N] = {};

    for (int i = 0; i < N; i++)
    {
        for (int ii = 0; ii < N; ii++)
            arr[i][ii] = A[i][ii];
    }

    for (int i = 1; i < k; i++)
    {
        matrix_mult(arr, A, m);
        //printf("\n");
    }

    for (int i = 0; i < N; i++)
    {
        for (int ii = 0; ii < N; ii++)
            A[i][ii] = arr[i][ii];
    }
}
