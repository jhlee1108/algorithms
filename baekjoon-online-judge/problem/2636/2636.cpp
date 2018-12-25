#include <cstdio>
#include <cstring>

#define PII pair<int,int>

using namespace std;

int N, M, map[100][100], check[100][100];
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

int dfs(int y, int x) {
    int ret = 0;

    for(int i=0; i<4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(0 <= ny && ny < N && 0 <= nx && nx < M) {
            if(check[ny][nx] == 0) {
                check[ny][nx] = 1;
                if(map[ny][nx] == 1) {
                    ret++;
                    map[ny][nx] = 0;
                }
                else ret += dfs(ny, nx);
            }   
        }
    }

    return ret;
}

int main() {
    scanf("%d %d", &N, &M);
    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++)
            scanf("%d", &map[i][j]);

    int t = 0, cnt = 0;
    while(1) {
        memset(check, 0, sizeof(check));
        int x = dfs(0, 0);
        if(x == 0) break;
        t++;
        cnt = x;
    }

    printf("%d\n%d\n", t, cnt);

    return 0;
}
