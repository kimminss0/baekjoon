/**
 * @author 김민서 <kimminss0@outlook.kr>
 * @date 2022-09-26
 */
#include <stdio.h>
#include <stdlib.h>

int dirs[8][2] = {{0,-1}, {0,1}, {-1,-1}, {-1,0}, {-1,1}, {1,-1}, {1,0}, {1,1}};
char mbtis[4][2] = {{'E','I'},{'N','S'},{'T','F'},{'P','J'}};
int main(void) {
    int N, M, cnt = 0;
    char** board;
    int* dir;
    scanf("%d %d", &N, &M);
    board = (char**)malloc(sizeof(char*)*N);
    for (int i = 0; i < N; ++i) {
        board[i] = (char*)malloc(sizeof(char)*(M+1));
    }
    for (int i = 0; i < N; ++i) {
        scanf("%s", board[i]);
    }
    for (int i = 0; i < 8; ++i) {
        dir = dirs[i];
        for (int row = (dir[0]<0 ? 3 : 0); row < N - (dir[0]>0 ? 3 : 0); ++row) {
            for (int col = (dir[1]<0 ? 3 : 0); col < M - (dir[1]>0 ? 3 : 0); ++col) {
                int ncol = col;
                int nrow = row;
                for (int foo = 0; foo < 4; ++foo) {
                    if (board[nrow][ncol] == mbtis[foo][0] || board[nrow][ncol] == mbtis[foo][1]) {
                        if (foo == 3) {
                            ++cnt;
                        }
                    } else {
                        break;
                    }
                    nrow += dir[0];
                    ncol += dir[1];
                }          
            }
        }
    }
    printf("%d", cnt);
    return 0;
}
