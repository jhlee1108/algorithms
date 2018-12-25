#include <cstdio>
#include <cstring>

int H, W, check[100][100];
char map[100][100];

int main() {
    scanf("%d %d\n", &H, &W);
    for(int i=0; i<H; i++)
        for(int j=0; j<W; j++)
            scanf("%c\n", &map[i][j]);

    memset(check, -1, sizeof(check));
    for(int i=0; i<H; i++)
        for(int j=0; j<W; j++)
            if(map[i][j] == 'c') {
                check[i][j] = 0;
                for(int k=j+1; k<W && map[i][k] != 'c'; k++)
                    check[i][k] = k - j;
            }

    for(int i=0; i<H; i++) {
        for(int j=0; j<W; j++)
            printf("%d ", check[i][j]);
        printf("\n");
    }

    return 0;
}
