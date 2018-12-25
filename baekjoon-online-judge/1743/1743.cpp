#include <cstdio>
#include <queue>
#include <algorithm>

#define PII pair<int,int>

using namespace std;

int N, M, K;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int passage[101][101];
int check[101][101];

int bfs(int x, int y) {
    int ret = 0;
    queue<PII> q;
    q.push(make_pair(x, y));
    check[x][y] = 1;

    while(!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        ret++;

        for(int i=0; i<4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(0 <= nx && nx <= N && 0 <= ny && ny <= M) {
                if(passage[nx][ny] == 1 && check[nx][ny] == 0) {
                    q.push(make_pair(nx, ny));
                    check[nx][ny] = 1;
                }
            }
        }
    }

    return ret;
}

int main() {
    scanf("%d %d %d", &N, &M, &K);
    while(K--) {
        int x, y; scanf("%d %d", &x, &y);
        passage[x][y] = 1;
    }

    int ans = 0;
    for(int i=0; i<=N; i++)
        for(int j=0; j<=M; j++)
            if(passage[i][j] == 1 && check[i][j] == 0)
                ans = max(ans, bfs(i, j));

    printf("%d\n", ans);

    return 0;
}
