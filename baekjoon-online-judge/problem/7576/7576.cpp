#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    int box[1000][1000] = {0,};
    int d[1000][1000] = {0,};
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    int n, m;
    queue<pair<int,int>> q;

    scanf("%d %d", &m, &n);

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            scanf("%d", &box[i][j]);
            if(box[i][j] == 1) {
                q.push(make_pair(i,j));
                d[i][j] = 1;
            }
            if(box[i][j] == -1)
                d[i][j] = -1;
        }
    }

    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i=0; i<4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(0 <= nx && nx < n && 0 <= ny && ny < m) {
                if(d[nx][ny] == -1)
                    continue;

                if(d[nx][ny] == 0) {
                    q.push(make_pair(nx,ny));
                    d[nx][ny] = d[x][y] + 1;
                }
            }
        }
    }

    int ans = 1;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(d[i][j] == 0) {
                ans = 0;
                break;
            }

            if(d[i][j] != -1)
                ans = max(ans, d[i][j]);
        }

        if(ans == 0)
            break;
    }

    printf("%d\n", ans-1);

    return 0;
}
                
