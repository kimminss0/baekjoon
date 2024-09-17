#include <stdio.h>
#include <stdlib.h>

int main(void){
    int N,M;
    scanf("%d", &N);
    int* N_arr = malloc(sizeof(int)*N);
    for(int i = 0; i < N; i++){
        scanf("%d", N_arr+i);
    }
    scanf("%d", &M);
    int* M_arr = malloc(sizeof(int)*M);
    for(int i = 0; i < M; i++){
        scanf("%d", M_arr+i);
    }
    
    for(int j = 0; j < M; j++){
        int count = 0;
        for(int i = 0; i < N; i++){
            if(N_arr[i]==M_arr[j]){
                count++;
            }
        }
        printf("%d ", count);
    }
}