#ifndef TRANSPOSE_H
#define TRANSPOSE_H

template<typename T>
void trivial_transpose(T **A, T **B, int N)
{
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            B[i][j] = A[j][i];
        }
    }
}

template<typename T>
void cached_transpose(T **A, T **B, int block_size, int N)
{
    int nBlocks = N/block_size + 1;
    for(int blk_i = 0; blk_i < nBlocks; blk_i++)
    {
        for(int blk_j = 0; blk_j < nBlocks; blk_j++)
        {
            for(int i = 0; i < block_size; i++)
            {
                for(int j = 0; j < block_size; j++)
                {
                    int idx_i = blk_i * block_size + i;
                    int idx_j = blk_j * block_size + j;
                    if(idx_i >= N || idx_j >= N)
                    {
                        continue;
                    }
                    B[idx_i][idx_j] = A[idx_j][idx_i];
                }
            }
        }
    }
}

#endif