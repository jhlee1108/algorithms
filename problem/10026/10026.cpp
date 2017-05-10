#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

char a[101][101];
int c[101][101];
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
int n;

void bfs(int x, int y, char z) {
    queue<pair<int,int>> q;
    q.push(make_pair(x,y));
    c[x][y] = 1;

    while(!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();

        for(int i=0; i<4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(0 <= nx && nx < n && 0 <= ny && ny < n) {
                if(c[nx][ny] == 0 && a[nx][ny] == z) {
                    q.push(make_pair(nx,ny));
                    c[nx][ny] = 1;
                }
            }
        }
    }
}

void bfs2(int x, int y, char z) {
    queue<pair<int,int>> q;
    q.push(make_pair(x,y));
    c[x][y] = 1;
    int flag = 0;
    if(z == 'R' || z == 'G')
        flag = 1;

    while(!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();

        for(int i=0; i<4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(0 <= nx && nx < n && 0 <= ny && ny < n) {
                if(flag == 1) {
                    if(c[nx][ny] == 0 && (a[nx][ny] == 'R' || a[nx][ny] == 'G')) {
                        q.push(make_pair(nx,ny));
                        c[nx][ny] = 1;
                    }
                }
                else {
                    if(c[nx][ny] == 0 && a[nx][ny] == z) {
                        q.push(make_pair(nx,ny));
                        c[nx][ny] = 1;
                    }
                }
            }
        }
    }
}

int main() {
    scanf("%d", &n);

    for(int i=0; i<n; i++)
        scanf("%s", a[i]);

    int ans = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(c[i][j] == 0) {
                bfs(i, j, a[i][j]);
                ans++;
            }
        }
    }

    printf("%d ", ans);
    
    ans = 0;
    memset(c, 0, sizeof(c));

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(c[i][j] == 0) {
                bfs2(i, j, a[i][j]);
                ans++;
            }
        }
    }

    printf("%d\n", ans);

    return 0;
}

