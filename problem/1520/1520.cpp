#include <cstdio>
#include <algorithm>

using namespace std;

int M, N, map[500][500], dp[500][500];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int go(int y, int x) {
    if(dp[y][x] != -1) return dp[y][x];
    
    int ret = 0;
    for(int i=0; i<4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(0 <= ny && ny < M && 0 <= nx && nx < N) {
            if(map[y][x] < map[ny][nx]) ret += go(ny, nx);
        }
    }

    return dp[y][x] = ret;
}

int main() {
    scanf("%d %d", &M, &N);
    for(int i=0; i<M; i++)
        for(int j=0; j<N; j++) {
            scanf("%d", &map[i][j]);
            dp[i][j] = -1;
        }

    dp[0][0] = 1;
    printf("%d\n", go(M-1, N-1));

    return 0;
}
