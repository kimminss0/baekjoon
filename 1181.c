#include <stdio.h>
#include <stdlib.h>

int comp(void const* a, void const* b)
{
    int i=0, j=0;
    while ((*(char**)a)[i] != 0) i++;
    while ((*(char**)b)[j] != 0) j++;
    if (i - j != 0)
        return i - j;
    int k = 0;
    while ((*(char**)a)[k] != 0)
    {
        if ((*(char**)a)[k] == (*(char**)b)[k])
        {
            k++;
            continue;
        }
        return (*(char**)a)[k] - (*(char**)b)[k];
    }
    return 0;

}

int main(void)
{
    int N;
    scanf("%d", &N);
    char **arr = (char**)malloc(sizeof(char*) * N);
    for (int i = 0; i < N; i++)
    {
        arr[i] = (char*)malloc(sizeof(char)*51);
        scanf("%s", arr[i]);
    }
    qsort(arr, N, sizeof(char*), comp);
    
    char* tmp = arr[0];
    for (int i = 0; i < N; i++)
    {   
        if (comp(&tmp, &arr[i]) != 0 || i == 0)
        {
            printf("%s\n", arr[i]);
            tmp = arr[i];
        }
    }
}
