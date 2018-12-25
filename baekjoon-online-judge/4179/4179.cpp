#include <cstdio>
#include <queue>

using namespace std;

struct point {
    int y, x, z;
    point(int y, int x, int z):y(y),x(x),z(z){}
};

char map[1000][1000];
int R, C, cnt[1000][1000];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
queue<point> q;

int main() {
    int si, sj;
    scanf("%d %d\n", &R, &C);
    for(int i=0; i<R; i++)
        for(int j=0; j<C; j++) {
            scanf("%c\n", &map[i][j]);
            if(map[i][j] == 'J') {
                si = i; sj = j;
            }
            if(map[i][j] == 'F') q.push(point(i, j, 0));
        }

    q.push(point(si, sj, 1));
    cnt[si][sj] = 1;
    while(!q.empty()) {
        int y = q.front().y;
        int x = q.front().x;
        int z = q.front().z;
        q.pop();

        for(int i=0; i<4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if(0 <= ny && ny < R && 0 <= nx && nx < C) {
                if(z) {
                    if(map[ny][nx] == '.' && !cnt[ny][nx]) {
                        cnt[ny][nx] = cnt[y][x] + 1;
                        q.push(point(ny, nx, z));
                    }
                }
                else {
                    if(map[ny][nx] == '.' || map[ny][nx] == 'J') {
                        map[ny][nx] = 'F';
                        q.push(point(ny, nx, z));
                    }
                }
            }
            else {
                if(z) {
                    printf("%d\n", cnt[y][x]);
                    return 0;
                }
            }
        }
    }

    puts("IMPOSSIBLE");
    return 0;
}
