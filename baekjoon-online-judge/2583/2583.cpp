#include <cstdio>
#include <queue>

using namespace std;

int a[111][111];
int d[111][111];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int m, n, k;

int bfs(int x, int y) {
    queue<pair<int,int>> q;
    q.push(make_pair(x,y));
    d[x][y] = 1;
    int area = 1;

    while(!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();

        for(int i=0; i<4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(0 <= nx && nx <m && 0 <= ny && ny <n) {
                if(a[nx][ny] == 0 && d[nx][ny] == 0) {
                    d[nx][ny] = 1;
                    q.push(make_pair(nx,ny));
                    area++;
                }
            }
        }
    }

    return area;
}

int main() {
    priority_queue<int, vector<int>, greater<int>> q;

    scanf("%d %d %d", &m, &n, &k);

    while(k--) {
        int x1, y1, x2, y2;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

        for(int i=y1; i<y2; i++)
            for(int j=x1; j<x2; j++)
                a[i][j] = 1;
    }
    
    int cnt=0;
    for(int i=m-1; i>=0; i--) {
        for(int j=0; j<n; j++) {
            if(a[i][j] == 0 && d[i][j] == 0) {
                q.push(bfs(i,j));
                cnt++;
            }
        }
    }

    printf("%d\n", cnt);
    while(!q.empty()) {
        printf("%d ", q.top());
        q.pop();
    }

    return 0;
}
