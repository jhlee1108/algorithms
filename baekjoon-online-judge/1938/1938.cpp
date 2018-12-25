#include <cstdio>
#include <queue>

using namespace std;

struct tree {
    int y, x, d;
};

char map[50][50];
int N, sy, sx, sd, ey, ex, ed;
int visited[2][50][50];
int dy[] = {0, 0, -1, 1, 0};
int dx[] = {-1, 1, 0, 0, 0};
int dd[] = {0, 0, 0, 0, 1};

int main() {
    scanf("%d\n", &N);
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++) {
            scanf("%c\n", &map[i][j]);
            if(map[i][j] == 'B') {
                if(i-1 >= 0 && map[i-1][j] == 'B') {
                    sy = i-1; sx = j; sd = 0;
                }
                if(j-1 >= 0 && map[i][j-1] == 'B') {
                    sy = i; sx = j-1; sd = 1;
                }
            }

            if(map[i][j] == 'E') {
                if(i-1 >= 0 && map[i-1][j] == 'E') {
                    ey = i-1; ex = j; ed = 0;
                }
                if(j-1 >= 0 && map[i][j-1] == 'E') {
                    ey = i; ex = j-1; ed = 1;
                }
            }
        }

    tree t; t.y = sy; t.x = sx; t.d = sd;
    queue<tree> q;
    q.push(t);
    visited[sd][sy][sx] = 1;

    while(!q.empty()) {
        int y = q.front().y;
        int x = q.front().x;
        int d = q.front().d;
        q.pop();

        if(visited[ed][ey][ex]) {
            printf("%d\n", visited[ed][ey][ex]-1);
            return 0;
        }

        for(int i=0; i<5; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            int nd = (d + dd[i]) % 2;
            
            if(0 <= ny && ny < N && 0 <= nx && nx < N) {
                if(nd != d) {
                    bool is_ok = true;
                    for(int r=-1; r<2; r++)
                        for(int c=-1; c<2; c++)
                            if(!(0 <= ny+r && ny+r < N && 0 <= nx+r && nx+r < N && map[ny+r][nx+c] != '1'))
                                is_ok = false;

                    if(is_ok && !visited[nd][ny][nx]) {
                        t.y = ny; t.x = nx; t.d = nd;
                        q.push(t);
                        visited[nd][ny][nx] = visited[d][y][x] + 1;
                    }
                    continue;
                }
                if(nd == 0)
                    if(ny-1 >= 0 && ny+1 < N && !visited[nd][ny][nx])
                        if( map[ny-1][nx] != '1' && 
                            map[ny][nx] != '1' &&
                            map[ny+1][nx] != '1') {
                            t.y = ny; t.x = nx; t.d = nd;
                            q.push(t);
                            visited[nd][ny][nx] = visited[d][y][x] + 1;
                        }
                if(nd == 1)
                    if(nx-1 >= 0 && nx+1 < N && !visited[nd][ny][nx])
                        if( map[ny][nx-1] != '1' &&
                            map[ny][nx] != '1' &&
                            map[ny][nx+1] != '1') {
                            t.y = ny; t.x = nx; t.d = nd;
                            q.push(t);
                            visited[nd][ny][nx] = visited[d][y][x] + 1;
                        }
            }
        }
    }

    printf("0\n");

    return 0;
}
