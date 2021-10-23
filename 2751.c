#include <stdio.h>
#include <stdlib.h>

void mergesort(int*, int);
void _mergesort(int*, int, int, int);
void copy_arr(int* A, int* B, int N);

int main(void)
{
    int N;
    scanf("%d", &N);
    int *arr = (int *)malloc(sizeof(int) * N);
    for (int i = 0; i < N; i++)
        scanf("%d", &(arr[i]));
    mergesort(arr, N);
    for (int i = 0; i < N; i++)
        printf("%d\n", arr[i]);
}

void mergesort(int* arr, int N)
{
    for (int i = 1; i < N; i *= 2)
    {
        for (int j = 0; j < N; j += 2 * i)
        {
            _mergesort(arr, N, j, i*2);
        }
    }
}

void _mergesort(int* arr, int N, int pos, int wid)
{
    int *a = (int*)malloc((wid/2)*sizeof(int));
    int *b = (int*)malloc((wid/2)*sizeof(int));
    int a_len, b_len;
    if (pos + wid <= N)
    {
        a_len = wid/2;
        b_len = wid/2;
    }
    else if (pos + wid/2 <= N)
    {
        a_len = wid/2;
        b_len = N - pos - wid/2;
    }
    else
    {
        a_len = N - pos;
        b_len = 0;
    }
    copy_arr(&arr[pos], a, a_len);
    copy_arr(&arr[pos + a_len], b, b_len);
    int a_p = 0, b_p = 0;
    for (int i = pos; i < pos + a_len + b_len; i++)
    {
        if (a_p < a_len && b_p < b_len)
        {
            if (a[a_p] < b[b_p])
                arr[i] = a[a_p++];
            else
                arr[i] = b[b_p++];
        }
        else if (a_p < a_len)
            arr[i] = a[a_p++];
        else
            arr[i] = b[b_p++];
    }
    free(a);
    free(b);
}

void copy_arr(int* A, int* B, int N)
{
    for (int i = 0; i < N; i++)
        B[i] = A[i];
}