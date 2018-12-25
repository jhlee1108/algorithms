#include <cstdio>

int dice[4][4], map[20][20];
int N, M, X, Y, K;
int dx[5] = {0, 0, 0, -1, 1};
int dy[5] = {0, 1, -1, 0, 0};

int main() {
    scanf("%d %d %d %d %d", &N, &M, &X, &Y, &K);
    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++)
            scanf("%d", &map[i][j]);

    while(K--) {
        int move; scanf("%d", &move);
        if(X + dx[move] < 0 || X + dx[move] >= N || Y + dy[move] < 0 || Y + dy[move] >= M)
            continue;
        X += dx[move];
        Y += dy[move];
        int temp;
        
        switch(move) {
            case 1:
                temp = dice[1][0];
                for(int i=1; i<=3; i++)
                    dice[1][i-1] = dice[1][i];
                dice[1][3] = dice[3][1] = temp;
                break;
            case 2:
                temp = dice[1][3];
                for(int i=2; i>=0; i--)
                    dice[1][i+1] = dice[1][i];
                dice[1][0] = temp;
                dice[3][1] = dice[1][3];
                break;
            case 3:
                temp = dice[3][1];
                for(int i=2; i>=0; i--)
                    dice[i+1][1] = dice[i][1];
                dice[0][1] = temp;
                dice[1][3] = dice[3][1];
                break;
            case 4:
                temp = dice[0][1];
                for(int i=1; i<=3; i++)
                    dice[i-1][1] = dice[i][1];
                dice[1][3] = dice[3][1] = temp;
                break;
        }

        if(map[X][Y] == 0) map[X][Y] = dice[1][1];
        else {
            dice[1][1] = map[X][Y];
            map[X][Y] = 0;
        }

        printf("%d\n", dice[3][1]);
    }

    return 0;
}
