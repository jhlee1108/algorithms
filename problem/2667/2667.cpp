#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

int map[25][25];
int group[25][25];
int sum[25*25];
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};
int n;

void bfs(int x, int y, int cnt) {
    queue<pair<int,int>> q;
    group[x][y] = cnt;
    q.push(make_pair(x,y));

    while(!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();

        for(int i=0; i<4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(0 <= nx && nx < n && 0 <= ny && ny < n) {
                if(map[nx][ny] == 1 && group[nx][ny] == 0) {
                    q.push(make_pair(nx,ny));
                    group[nx][ny] = cnt;
                }
            }
        }
    }
}

int main() {
    scanf("%d", &n);

    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            scanf("%1d", &map[i][j]);

    int cnt = 0;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            if(map[i][j] == 1 && group[i][j] == 0)
                bfs(i, j, ++cnt);

    printf("%d\n", cnt);
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            sum[group[i][j]] += 1;

    sort(sum+1, sum+cnt+1);
    for(int i=1; i<=cnt; i++)
        printf("%d\n", sum[i]);

    return 0;
}
