// #include <stdio.h>
// #include <stdlib.h>

// int n;
// int* arr;
// int mem[10001][3];

// int func(int pos, int conti)
// {
//     int op1, op2;
//     if(pos == n)
//         return 0;
//     if(mem[pos][conti] != -1)
//         goto RET;

//     op1 = func(pos + 1, 0);
//     op2 = op1;
//     if(conti < 2)
//         op2 = arr[pos] + func(pos + 1, conti + 1);
//     mem[pos][conti] = op1 > op2 ? op1 : op2;
// RET:
//     return mem[pos][conti];
// }

// int main(void)
// {
//     int res;
//     scanf("%d", &n);
//     arr = (int*)malloc(sizeof(int) * n);
//     for(int i = 0; i < n; ++i)
//     {
//         scanf("%d", arr + i);
//         mem[i][0] = -1;
//         mem[i][1] = -1;
//         mem[i][2] = -1;
//     }
//     res = func(0, 0);
//     printf("%d", res);
//     return 0;
// }

/// 남의 코드인데, 분석해보자
#include <stdio.h>

int main(void)
{
    long long int d[10001] = {};
    int n, a[10001] = {};
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);

    d[1] = a[1];
    d[2] = a[1] + a[2];
    for(int i = 3; i <= n; ++i)
    {
        d[i] = d[i-1];
        if(d[i] < d[i-2] + a[i])
            d[i] = d[i-2] + a[i];
        if(d[i] < d[i-3] + a[i-1] + a[i])
            d[i] = d[i-3] + a[i-1] + a[i];
    }
    printf("%lld", d[n]);
    
    return 0;
}