// #include <stdio.h>
// #include <math.h>

// int main(void){
//     long long int N;
//     scanf("%lld", &N);
//     printf("%d", N == 1 ? 1 : (int)((3+sqrt((4*N-5)/3))/2));

//     return 0;
// }

#include <stdio.h>

int main(void) {
    long long int N, X = 1;
    scanf("%lld", &N);

    int shell = 1;
    while(N > X) {
        X += 6 * shell;
        shell++;
    }
    printf("%d", shell);

    return 0;
}