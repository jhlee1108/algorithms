#include <cstdio>
#include <queue>
#include <cstring>

using namespace std;

int a[50][50];
int d[50][50];
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};
int t, m, n, k;

void bfs(int i, int j, int cnt) {
    queue<pair<int,int>> q;
    q.push(make_pair(i,j));
    d[i][j] = cnt;

    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i=0; i<4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(0 <= nx && nx < n && 0 <= ny && ny < m) {
                if(a[nx][ny] == 1 && d[nx][ny] == 0 ){
                    q.push(make_pair(nx,ny));
                    d[nx][ny] = cnt;
                }
            }
        }
    }
}

int main() {
    scanf("%d", &t);

    while(t--) {
        memset(a, 0, sizeof(a));
        memset(d, 0, sizeof(d));
        int cnt = 0;
        scanf("%d %d %d", &m, &n, &k);

        while(k--) {
            int i, j;
            scanf("%d %d", &j, &i);
            a[i][j] = 1;
        }

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(a[i][j] == 1 && d[i][j] == 0) {
                    bfs(i, j, ++cnt);
                }
            }
        }

        printf("%d\n", cnt);
    }

    return 0;
}
