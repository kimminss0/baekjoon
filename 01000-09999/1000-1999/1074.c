/**
 * @author 김민서 <kimminss0@outlook.kr>
 * @date 2022-03-25
 */
#include <stdio.h>

int func(int N, int r, int c);

int main(void)
{
    int N, r, c;

    scanf("%d %d %d", &N, &r, &c);

    printf("%d", func(N, r, c));
    return 0;
}

int func(int N, int r, int c)
{
    int n = 0;

    if(N == 1)
    {
        return 2 * r + c;
    }

    if(r >= (1 << (N-1)))
    {
        n += 2;
        r -= (1 << (N-1));
    }
    if(c >= (1 << (N-1)))
    {
        n += 1;
        c -= (1 << (N-1));
    }
    return n * (1 << 2*(N-1)) + func(N-1, r, c);
}
