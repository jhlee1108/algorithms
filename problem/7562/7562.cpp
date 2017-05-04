#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

int d[300][300];
int dx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[8] = {-1, 1, -2, 2, -2, 2, -1, 1};
int t, l;

void bfs(int x, int y) {
    queue<pair<int,int>> q;
    q.push(make_pair(x,y));
    d[x][y] = 1;

    while(!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();

        for(int i=0; i<8; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(0 <= nx && nx < l && 0 <= ny && ny < l) {
                if(d[nx][ny] == 0) {
                    q.push(make_pair(nx,ny));
                    d[nx][ny] = d[x][y] + 1;
                }
            }
        }
    }
}

int main() {
    scanf("%d", &t);

    while(t--) {
        scanf("%d", &l);

        int i, j;
        scanf("%d %d", &i, &j);

        bfs(i, j);

        scanf("%d %d", &i, &j);
        printf("%d\n", d[i][j]-1);
        memset(d, 0, sizeof(d));
    }

    return 0;
}
