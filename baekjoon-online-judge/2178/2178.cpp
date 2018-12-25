#include <cstdio>
#include <queue>

using namespace std;

int main() {
    int n, m;
    int maze[100][100] = {0,};
    int d[100][100] = {0,};
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    queue<pair<int,int>> q;

    scanf("%d %d", &n, &m);

    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            scanf("%1d", &maze[i][j]);

    d[0][0] = 1;
    q.push(make_pair(0,0));

    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i=0; i<4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(0 <= nx && nx < n && 0 <= ny && ny < m) {
                if(maze[nx][ny] == 1 && d[nx][ny] == 0) {
                    d[nx][ny] = d[x][y] + 1;
                    q.push(make_pair(nx,ny));
                }
            }
        }
    }

    printf("%d\n", d[n-1][m-1]);

    return 0;
}
