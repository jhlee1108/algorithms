#include <cstdio>
#include <queue>

using namespace std;

struct Point {
    int y, x, crashed;
};

int N, M, map[1000][1000], check[1000][1000][2];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int main() {
    scanf("%d %d", &N, &M);
    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++) {
            scanf("%1d", &map[i][j]);
            check[i][j][0] = -1;
            check[i][j][1] = -1;
        }

    queue<Point> q;
    Point p;
    p.y = 0; p.x = 0; p.crashed = 0;
    q.push(p);
    check[0][0][0] = 1;

    while(!q.empty()) {
        int y = q.front().y;
        int x = q.front().x;
        int crashed = q.front().crashed;
        q.pop();

        for(int i=0; i<4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if(0 <= ny && ny < N && 0 <= nx && nx < M) {
                if(check[ny][nx][crashed] == -1) {
                    if(map[ny][nx] == 1 && crashed == 0) {
                        Point np;
                        np.y = ny; np.x = nx; np.crashed = 1;
                        q.push(np);
                        check[ny][nx][1] = check[y][x][0] + 1;
                    }
                    else if(map[ny][nx] == 0) {
                        Point np;
                        np.y = ny; np.x = nx; np.crashed = crashed;
                        q.push(np);
                        check[ny][nx][crashed] = check[y][x][crashed] + 1;
                    }
                }
            }
        }
    }
   
    int ans;
    int a = check[N-1][M-1][0];
    int b = check[N-1][M-1][1];

    if(0 < a && 0 < b) ans = min(a, b);
    else if(0 < a) ans = a;
    else if(0 < b) ans = b;
    else ans = -1;

    printf("%d\n", ans);

    return 0;
}
