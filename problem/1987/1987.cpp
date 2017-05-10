#include <cstdio>

#define MAX(A,B) ((A) > (B) ? (A) : (B))

char a[22][22];
int d[22][22];
int u[26];
int ans = 0;
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
int r, c;

void dfs(int x, int y, int z) {
    d[x][y] = 1;
    u[a[x][y]-65] = 1;
    ans = MAX(ans, z);

    for(int i=0; i<4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(0 <= nx && nx < r && 0 <= ny && ny < c) {
            if(d[nx][ny] == 0 && u[a[nx][ny]-65] == 0)
                dfs(nx, ny, z+1);
        }
    }
    
    d[x][y] = 0;
    u[a[x][y]-65] = 0;
}

int main() {
    scanf("%d %d", &r, &c);

    for(int i=0; i<r; i++)
        scanf("%s", a[i]);

    dfs(0,0,1);

    printf("%d\n", ans);

    return 0;
}

