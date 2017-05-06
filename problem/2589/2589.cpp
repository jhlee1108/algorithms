#include <cstdio>
#include <cstring>
#include <queue>

#define MAX(A,B) ((A) > (B) ? (A) : (B))

using namespace std;

char a[55][55];
int c[55][55];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int m, n;

int bfs(int x, int y) {
    queue<pair<int,int>> q;
    q.push(make_pair(x,y));
    c[x][y] = 1;
    int result = 1;

    while(!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        
        for(int i=0; i<4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(0 <= nx && nx < m && 0 <= ny && ny < n) {
                if(a[nx][ny] == 'L' && c[nx][ny] == 0) {
                    q.push(make_pair(nx,ny));
                    c[nx][ny] = c[x][y] + 1;
                    result = c[nx][ny];
                }
            }
        }
    }

    return result;
}

int main() {
    char s[51];
    int ans = 1;
    scanf("%d %d\n", &m, &n);

    for(int i=0; i<m; i++) {
        scanf("%s", s);
        for(int j=0; j<n; j++)
            a[i][j] = s[j];
    }

    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            if(a[i][j] == 'L') {
                memset(c, 0, sizeof(c));
                int new_value = bfs(i,j);
                ans = MAX(ans, new_value);
            }
        }
    }

    printf("%d\n", ans-1);

    return 0;
}
    
