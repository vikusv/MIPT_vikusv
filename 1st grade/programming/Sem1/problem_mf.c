#include <stdio.h>
#include <stdlib.h>

void matrix_mult(unsigned long long *matrix1, unsigned long long *matrix2, unsigned long long *matrix_res, unsigned long long m);
int main() 
{
    unsigned long long x1, x2, x3, x4, n, m, i, k;
    unsigned long long matrix1[4] = {};
    unsigned long long matrix_res[4] = {};
    unsigned long long matrix2[4] = {};
    int res;
    res = scanf("%llu %llu %llu %llu %llu %llu", &x1, &x2, &x3, &x4, &n, &m);
    if (res != 6) 
    {
        printf("%s\n", "Wrong input");
        abort();
    }
    matrix1[0] = x1; matrix2[0] = x1; matrix_res[0] = x1;
    matrix1[1] = x2; matrix2[1] = x2; matrix_res[1] = x2;
    matrix1[2] = x3; matrix2[2] = x3; matrix_res[2] = x3;
    matrix1[3] = x4; matrix2[3] = x4; matrix_res[3] = x4;
    for (i = 1; i < (n / 2);)
    {
        matrix2[0] = matrix_res[0]; 
        matrix2[1] = matrix_res[1];
        matrix2[2] = matrix_res[2];
        matrix2[3] = matrix_res[3];

        if (n>100000)
        {
            k = 1;
            while ((n / (10 * k)) >= 10)
                k++;
            if (k % 2)
            {
                for (i = 1; i < 10;)
                {
                    matrix2[0] = matrix_res[0]; 
                    matrix2[1] = matrix_res[1];
                    matrix2[2] = matrix_res[2];
                    matrix2[3] = matrix_res[3];
                    
                    matrix_mult(matrix1, matrix2, matrix_res, m);
                    i++;
                }
                for (i = 1; i < k;)
                {
                    matrix2[0] = matrix_res[0]; matrix1[0] = matrix_res[0]; 
                    matrix2[1] = matrix_res[1]; matrix1[1] = matrix_res[1]; 
                    matrix2[2] = matrix_res[2]; matrix1[2] = matrix_res[2]; 
                    matrix2[3] = matrix_res[3]; matrix1[3] = matrix_res[3]; 
                    
                    matrix_mult(matrix1, matrix2, matrix_res, m);
                    i++;
                }
            printf("%llu %llu %llu %llu\n", matrix_res[0], matrix_res[1], matrix_res[2], matrix_res[3]);
            return 0;
            }
        }
        
        matrix_mult(matrix1, matrix2, matrix_res, m);
        i++;
    }
    matrix2[0] = matrix_res[0]; 
    matrix2[1] = matrix_res[1];
    matrix2[2] = matrix_res[2];
    matrix2[3] = matrix_res[3];

    matrix_mult(matrix2, matrix2, matrix_res, m);
    if ((n % 2) != 0)
    {
        matrix2[0] = matrix_res[0]; 
        matrix2[1] = matrix_res[1];
        matrix2[2] = matrix_res[2];
        matrix2[3] = matrix_res[3];

        matrix_mult(matrix1, matrix2, matrix_res, m);
    }

    printf("%llu %llu %llu %llu\n", matrix_res[0], matrix_res[1], matrix_res[2], matrix_res[3]);

    return 0;
}

void matrix_mult(unsigned long long *matrix1, unsigned long long *matrix2, unsigned long long *matrix_res, unsigned long long m)
{
    matrix_res[0] = ((matrix1[0] * matrix2[0]) % m + (matrix1[1] * matrix2[2]) % m) % m;
    matrix_res[1] = ((matrix1[0] * matrix2[1]) % m + (matrix1[1] * matrix2[3]) % m) % m;
    matrix_res[2] = ((matrix1[2] * matrix2[0]) % m + (matrix1[3] * matrix2[2]) % m) % m;
    matrix_res[3] = ((matrix1[2] * matrix2[1]) % m + (matrix1[3] * matrix2[3]) % m) % m;
}
