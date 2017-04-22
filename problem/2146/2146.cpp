#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

int n;
int map[100][100] = {0,};
int group[100][100] = {0,};
int d[100][100] = {0,};
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int cnt = 0;

void make_group(int x, int y, int cnt) {
    group[x][y] = cnt;
    queue<pair<int,int>> q;
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
                    group[nx][ny] = cnt;
                    q.push(make_pair(nx,ny));
                }
            }
        }
    }
}

int main() {
    queue<pair<int,int>> q;

    scanf("%d", &n);

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            scanf("%d", &map[i][j]);
            if(map[i][j] == 1)
                q.push(make_pair(i,j));
        }
    }

    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            if(map[i][j] == 1 && group[i][j] == 0)
                make_group(i, j, ++cnt);

    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i=0; i<4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(0 <= nx && nx < n && 0 <= ny && ny <n) {
                if(d[nx][ny] == 0 && group[nx][ny] == 0)
                    d[nx][ny] = d[x][y] + 1;

                if(group[nx][ny] == 0) {
                    group[nx][ny] = group[x][y];
                    q.push(make_pair(nx,ny));
                }
            }
        }
    }

    int ans=10000;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            for(int k=0; k<4; k++) {
                int x = i + dx[k];
                int y = j + dy[k];

                if(0 <= x && x < n && 0 <= y && y < n)
                    if(group[i][j] != group[x][y])
                        ans = min(ans, d[i][j]+d[x][y]);
            }
        }
    }

    printf("%d\n", ans);

    return 0;
}
