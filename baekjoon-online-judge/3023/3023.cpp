#include <cstdio>

int R, C, A, B;
char map[100][100];

int main() {
    scanf("%d %d\n", &R, &C);
    for(int i=0; i<R; i++)
        for(int j=0; j<C; j++) {
            scanf("%c\n", &map[i][j]);
            int rj = j + (C - j) * 2 - 1;
            int di = i + (R - i) * 2 - 1;
            map[di][j] = map[di][rj] = map[i][rj] = map[i][j];
        }

    scanf("%d %d", &A, &B);
    A--; B--;
    if(map[A][B] == '.') map[A][B] = '#';
    else map[A][B] = '.';

    for(int i=0; i<2*R; i++) {
        for(int j=0; j<2*C; j++)
            printf("%c", map[i][j]);
        printf("\n");
    }

    return 0;
}
