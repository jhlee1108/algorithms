#include <cstdio>
#include <algorithm>

using namespace std;

int n;
int a[500][500];
int d[500][500];
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};

int dfs(int x, int y) {
    if(d[x][y] != 0)
        return d[x][y];

    d[x][y] = 1;

    for(int i=0; i<4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(0 <= nx && nx < n && 0 <= ny && ny < n) {
            if(a[nx][ny] > a[x][y]) {
                d[x][y] = max(d[x][y], dfs(nx,ny)+1);
            }
        }
    }

    return d[x][y];
}

int main() {
    int ans = 0;

    scanf("%d", &n);

    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            scanf("%d", &a[i][j]);

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            int x = dfs(i,j);
            ans = max(ans, x);
        }
    }

    printf("%d\n", ans);

    return 0;
}
