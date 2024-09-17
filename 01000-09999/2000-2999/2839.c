#include <stdio.h>

int main(void) {
    int N, a, b;
    scanf("%d", &N);
    a = N / 5;
    while (1){
        if ((N - a * 5) % 3 == 0) {
            b = (N - a * 5) / 3;
            break;
        }
        else {
            a--;
            if (a < 0) {
                printf("-1");
                return 0;
            }
        }
    }
    printf("%d", (a+b));

    return 0;
}