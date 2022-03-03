#ifndef TRANSPOSE_H
#define TRANSPOSE_H

template<typename T>
void rowMajor_by_rowMajor(T &A, T &B, T &C, int N)
{
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            for(int k = 0; k < N; k++)
            {
                C[i][j] = A[i][k] * B[k][j];
            }
        }
    }
}

template<typename T>
void rowMajor_by_colMajor(T &A, T &B, T &C, int N)
{
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            for(int k = 0; k < N; k++)
            {
                C[i][j] = A[i][k] * B[j][k];
            }
        }
    }
}

template<typename T>
void trivial_transpose(T &A, T &B, int N)
{
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            B[i][j] = A[j][i];
        }
    }
}

#endif