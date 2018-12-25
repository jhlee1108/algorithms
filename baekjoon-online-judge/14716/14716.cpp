#include <cstdio>
#include <queue>

#define PII pair<int,int>

using namespace std;

int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
int check[250][250], map[250][250];
int M, N;

void bfs(int y, int x) {
    queue<PII> q;
    q.push(make_pair(y, x));
    check[y][x] = 1;

    while(!q.empty()) {
        y = q.front().first;
        x = q.front().second;
        q.pop();

        for(int i=0; i<8; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            
            if(0 <= ny && ny < M && 0 <= nx && nx < N) {
                if(check[ny][nx] == 0 && map[ny][nx] == 1) {
                    check[ny][nx] = 1;
                    q.push(make_pair(ny, nx));
                }
            }
        }
    }
}

int main() {
    scanf("%d %d", &M, &N);
    for(int i=0; i<M; i++)
        for(int j=0; j<N; j++)
            scanf("%d", &map[i][j]);

    int ans = 0;
    for(int i=0; i<M; i++)
        for(int j=0; j<N; j++)
            if(check[i][j] == 0 && map[i][j] == 1) {
                bfs(i, j);
                ans++;
            }

    printf("%d\n", ans);

    return 0;
}
