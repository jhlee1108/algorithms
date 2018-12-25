#include <cstdio>
#include <queue>

using namespace std;

int map[50][50];
int group[50][50];
int dx[] = {-1, -1, -1, 0, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};
int w, h;

void bfs(int x, int y, int cnt) {
    queue<pair<int,int>> q;
    group[x][y] = cnt;
    q.push(make_pair(x,y));

    while(!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();

        for(int i=0; i<9; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(0 <= nx && nx < h && 0 <= ny && ny < w) {
                if(map[nx][ny] == 1 && group[nx][ny] == 0) {
                    group[nx][ny] = cnt;
                    q.push(make_pair(nx,ny));
                }
            }
        }
    }
}

int main() {
    while(scanf("%d %d", &w, &h) == 2) {
        if(w == 0 && h == 0)
            continue;

        for(int i=0; i<h; i++) {
            for(int j=0; j<w; j++) {
                group[i][j] = 0;
                scanf("%d", &map[i][j]);
            }
        }
 
        int cnt = 0;
        for(int i=0; i<h; i++)
            for(int j=0; j<w; j++)
                if(map[i][j] == 1 && group[i][j] == 0)
                    bfs(i, j, ++cnt);

        printf("%d\n", cnt);
    }

    return 0;
}
