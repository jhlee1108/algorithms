#include <cstdio>
#include <queue>
#include <cstring>

#define MAX(A,B) ((A) > (B) ? (A) : (B))

using namespace std;

int n;
int a[111][111];
int b[111][111];
int c[111][111];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

void bfs(int x, int y) {
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

            if(0 <= nx && nx < n && 0 <= ny && ny <n) {
                if(b[nx][ny] > 0 && c[nx][ny] == 0) {
                    q.push(make_pair(nx,ny));
                    c[nx][ny] = 1;
                }
            }
        }
    }
}

int main() {
    int max_value = 0;
    int new_ans = 0;
    int ans = 0;

    scanf("%d", &n);

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            scanf("%d", &a[i][j]);
            max_value = MAX(max_value, a[i][j]);
        }
    }

    for(int m=0; m<max_value; m++) {
        new_ans = 0;
        memset(c, 0, sizeof(c));

        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                b[i][j] = a[i][j] - m;

        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(b[i][j] > 0 && c[i][j] == 0) {
                    bfs(i, j);
                    new_ans++;
                }
            }
        }
        
        ans = MAX(ans, new_ans);
    }

    printf("%d\n", ans);

    return 0;
}
